open Ast
open Format

(* Excepção levantada para assinalar um erro durante a interpretação *)
exception Error of string
let error s = raise (Error s)

(* Os valores de Mini-Python

   - uma diferença notável com Python : utilizamos aqui o tipo int "máquina"
     enquanto os inteiros de Python têm precisão arbitrária ; poderiamos
     utilizar o tipo Big_int de OCaml mas preferimos aqui a opção cómoda
     e fácil ;

   - o que Python designa de lista é na verdade um vector redimensionável ;
     no fragmento aqui considerado, não há forma de modificar o comprimento,
     logo um simples vector OCaml chegará *)

type value =
  | Vnone
  | Vbool of bool
  | Vint of int
  | Vstring of string
  | Vlist of value array

(* Vizualização *)
let rec print_value = function
  | Vnone -> printf "None"
  | Vbool true -> printf "True"
  | Vbool false -> printf "False"
  | Vint n -> printf "%d" n
  | Vstring s -> printf "%s" s
  | Vlist a ->
    let n = Array.length a in
    printf "[";
    for i = 0 to n-1 do print_value a.(i); if i < n-1 then printf ", " done;
    printf "]"

(* Interpretação booleana

   Em Python, qualquer valor pode ser utilizado como um valor boleano :
   None, a lista vazia, a string vazia o inteiro 0 são considerados como
   False e qualquer outro valor como True *)

let is_false = function
  | Vnone
  | Vbool false
  | Vstring ""
  | Vlist [||] -> true
  | Vint n -> n = 0
  | _ -> false

let is_true v = not (is_false v)

(* Comparações (questão opcional)

   Vamos aqui nos esforçar parea aceitar comparações enter booleanos e
   inteiros, mas apesar de tal esforço, permaneçam diferenças com o
   Python.

   De fqcto em Python (3) recusa comparações tais como  True < None
   ou ainda "" < []  que aqui são ainda aceites. *)

let rec compare_list a1 n1 a2 n2 i =
  if i = n1 && i = n2 then 0
  else if i = n1 then -1
  else if i = n2 then 1
  else let c = compare_value a1.(i) a2.(i) in
    if c <> 0 then c else compare_list a1 n1 a2 n2 (i + 1)

and compare_value v1 v2 = match v1, v2 with
  | Vlist a1, Vlist a2 ->
    compare_list a1 (Array.length a1) a2 (Array.length a2) 0
  | Vbool b1, Vint _ -> compare_value (Vint (if b1 then 1 else 0)) v2
  | Vint _, Vbool b2 -> compare_value v1 (Vint (if b2 then 1 else 0))
  | _ -> compare v1 v2


(* Interpretação dos operadores binários

   - o operador + é sobrecarregado : designa também a concatenação
     das listas e das strings
   - os operadores / e % devem levantar uma excepção se se tenta dividir
     por zero
*)

let binop op v1 v2 = match op, v1, v2 with
  | Badd, Vint n1, Vint n2 -> Vint (n1+n2)
  | Badd, Vstring s1, Vstring s2 -> Vstring (s1 ^ s2)
  | Badd, Vlist l1, Vlist l2 -> Vlist (Array.append l1 l2)
  | Bsub, Vint n1, Vint n2 -> Vint (n1-n2)
  | Bmul, Vint n1, Vint n2 -> Vint (n1*n2)
  | (Bdiv | Bmod), Vint _, Vint 0 -> error "division by zero"
  | Bdiv, Vint n1, Vint n2 -> Vint (n1/n2)
  | Bmod, Vint n1, Vint n2 -> Vint (n1 mod n2)
  | Beq, _, _ -> Vbool (compare_value v1 v2 = 0)
  | Bneq, _, _ -> Vbool (compare_value v1 v2 <> 0)
  | Blt, _, _ -> Vbool (compare_value v1 v2 < 0)
  | Ble, _, _ -> Vbool (compare_value v1 v2 <= 0)
  | Bgt, _, _ -> Vbool (compare_value v1 v2 > 0)
  | Bge, _, _ -> Vbool (compare_value v1 v2 >= 0)
  | _ -> error "unsupported operand types"


(* As funções são aqui exclusivamente globais *)

let functions = (Hashtbl.create 17 : (string, ident list * stmt) Hashtbl.t)

(* A instrução 'return' de Python é interpretada com recurso a uma excepção *)

exception Return of value

(* Les variáveis locais
   (parâmetros de funções e variáveis introduzidas por atribuições) são
   arquivadas numa tabela de hash passada como argumento às funções
   seguintes com o nome 'ctx'
*)

type ctx = (string, value) Hashtbl.t

(* Interpretação de uma expressão (devolve um valor) *)

let rec expr ctx = function
  | Ecst Cnone ->
    Vnone
  | Ecst (Cbool b) ->
    Vbool b
  | Ecst (Cint n) ->
    Vint n
  | Ecst (Cstring s) ->
    Vstring s
  | Ebinop (Band, e1, e2) ->
    let v1 = expr ctx e1 in
    if is_true v1 then expr ctx e2 else v1
  | Ebinop (Bor, e1, e2) ->
    let v1 = expr ctx e1 in
    if is_false v1 then expr ctx e2 else v1
  | Ebinop (Badd | Bsub | Bmul | Bdiv | Bmod |
            Beq | Bneq | Blt | Ble | Bgt | Bge as op, e1, e2) ->
    binop op (expr ctx e1) (expr ctx e2)
  | Eunop (Uneg, e1) ->
    begin match expr ctx e1 with
      | Vint n -> Vint (-n)
      | _ -> error "unsupported operand types" end
  | Eunop (Unot, e1) ->
    Vbool (is_false (expr ctx e1))
  | Ecall ("len", [e1]) ->
    begin match expr ctx e1 with
      | Vstring s -> Vint (String.length s)
      | Vlist l -> Vint (Array.length l)
      | _ -> error "this value has no 'len'" end
  | Ecall ("list", [Ecall ("range", [e1])]) ->
    let n = expr_int ctx e1 in
    Vlist (Array.init (max 0 n) (fun i -> Vint i))
  | Ecall (f, el) ->
    if not (Hashtbl.mem functions f) then error ("unbound function " ^ f);
    let args, body = Hashtbl.find functions f in
    if List.length args <> List.length el then error "bad arity";
    let ctx' = Hashtbl.create 16 in
    List.iter2 (fun x e -> Hashtbl.add ctx' x (expr ctx e)) args el;
    begin try stmt ctx' body; Vnone with Return v -> v end
  | Elist el ->
    Vlist (Array.of_list (List.map (expr ctx) el))
  | Eident id ->
    if not (Hashtbl.mem ctx id) then error "unbound variable";
    Hashtbl.find ctx id
  | Eget (e1, e2) ->
    begin match expr ctx e1 with
      | Vlist l ->
        let i = expr_int ctx e2 in
        (try l.(i) with Invalid_argument _ -> error "index out of bounds")
      | _ -> error "list expected" end

(* interpretação de um valor e verificação de que se trata de um inteiro *)

and expr_int ctx e = match expr ctx e with
  | Vint n -> n
  | _ -> error "integer expected"

(* interpretação de uma instrução - não devolve nada *)

and stmt ctx = function
  | Sif (e, s1, s2) ->
    if is_true (expr ctx e) then stmt ctx s1 else stmt ctx s2
  | Sreturn e ->
    raise (Return (expr ctx e))
  | Sassign (id, e1) ->
    Hashtbl.replace ctx id (expr ctx e1)
  | Sset (e1, e2, e3) ->
    begin match expr ctx e1 with
      | Vlist l -> l.(expr_int ctx e2) <- expr ctx e3
      | _ -> error "list expected" end
  | Sprint e ->
    print_value (expr ctx e); printf "@."
  | Sblock bl ->
    block ctx bl
  | Sfor (x, e, s) ->
    begin match expr ctx e with
      | Vlist l ->
        Array.iter (fun v -> Hashtbl.replace ctx x v; stmt ctx s) l
      | _ -> error "list expected" end
  | Seval e ->
    ignore (expr ctx e)

(* interpretação de um bloco, i.e. uma sequência de instruções *)

and block ctx = function
  | [] -> ()
  | s :: sl -> stmt ctx s; block ctx sl

(* interpretação de um ficheiro *)

let file (fl, s) =
  List.iter
    (fun (f,args,body) -> Hashtbl.add functions f (args, body)) fl;
  stmt (Hashtbl.create 17) s
