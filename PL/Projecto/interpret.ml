open Ast

(* Types *)

exception Error of string

type value =
  | Vnull
  | Vint of int
  | Vstring of string
  | Vbool of bool
  | Vpair of value * value
  | Vrange of interval
  | Varray of interval * value array

exception Return of value

(* ctx - Global variables *)
let ctx : (identifier, (value*typ)) Hashtbl.t = Hashtbl.create 17

(* env - Type variables *)
let env : (identifier, typ) Hashtbl.t = Hashtbl.create 17

(* func - Functions declarations *)
let func : (identifier, (typ * (identifier * typ) list * statement)) Hashtbl.t = Hashtbl.create 17

let rec print_value = function
  | Vnull -> Format.printf "null"
  | Vint i -> Format.printf "%d" i
  | Vstring s -> Format.printf "%s" s
  | Vbool true -> Format.printf "true"
  | Vbool false -> Format.printf "false"
  | Vrange (s,f) -> Format.printf "%d..%d" s f
  | Vpair (p1, p2) -> ((print_value p1); Format.printf ", "; (print_value p2))
  | Varray (_, a) -> Format.printf "[ "; Array.iter (fun x -> (print_value x); Format.printf " ") a; Format.printf "]"

let print x = print_value x; Format.printf "@."

let array_size = function
  | Varray ((s, f), a) -> Vint (f-s+1)
  | _ -> raise (Error "invalid argument")

let range_size = function
  | Trange (s,f) -> Vint (f-s+1)
  | _ -> raise (Error "invalid argument")
let is_false = function
  | Vnull
  | Vint 0
  | Vbool false
  | Vstring "" -> true
  | _ -> false

let is_true v = not (is_false v)

let rec type_of_value = function
  | Vnull -> Tnull
  | Vint _ -> Tint
  | Vbool _ -> Tbool
  | Vstring _ -> Tstring
  | Vpair (p1, p2) -> Tpair ((type_of_value p1), (type_of_value p2))
  | Varray ((s, f), a) -> type_of_value (Array.get a 0)
  | Vrange (s,f) -> Trange (s,f)


let create_array s f x =
  let v = Array.make (f-s+1) x in Varray ((s,f), v)

let rec compare_value v1 v2 = match v1, v2 with
  | Vint i1, Vint i2 -> compare i1 i2
  | Vstring i1, Vstring i2 -> compare i1 i2
  | Vbool b1, Vint _ -> compare_value (Vint (if b1 then 1 else 0)) v2
  | Vint _, Vbool b2 -> compare_value v1 (Vint (if b2 then 1 else 0))
  | _ -> raise (Error "unsuported comparison")

let rec compare_types t1 v =
  let t2 = type_of_value v in
  match t1, t2 with
  | Trange (s,f), Tint -> if compare_value v (Vint s) >= 0 && compare_value v (Vint f) <= 0 then true else false
  | _ , _ -> if t1 = t2 then true else false

let check_bound i s f =
  match i with
  | Vint i ->
    if i >= s && i <= f then
      i
    else -1
  | _ -> raise (Error "invalid index")


let unop op v = match op, v with
  | OPneg, Vint i -> Vint (-i)
  | OPnot, _ -> Vbool (is_false v)
  | _ -> raise (Error "unsuported operand")

let binop v1 op v2 = match v1, op, v2 with
  | Vbool b1, OPand, Vbool b2 -> if (is_false v1) then (Vbool false) else Vbool (is_true v2)
  | Vbool b1, OPor, Vbool b2 -> if (is_true v1) then (Vbool true) else Vbool (is_true v2)
  | Vbool b1, OPxor, Vbool b2 -> Vbool (is_false v1 = is_false v2)
  | Vint i1, OPadd, Vint i2 -> Vint (i1 + i2)
  | Vstring s1, OPadd, Vstring s2 -> Vstring (s1 ^ s2)
  | Vint i1, OPsub, Vint i2 -> Vint (i1 - i2)
  | Vint i1, OPmul, Vint i2 -> Vint (i1 * i2)
  | Vint _, (OPdiv | OPmod), Vint 0 -> raise (Error "division by zero")
  | Vint i1, OPdiv, Vint i2 -> Vint (i1 / i2)
  | Vint i1, OPmod, Vint i2 -> Vint (i1 mod i2)
  | _, OPeq, _ -> Vbool (compare_value v1 v2 = 0)
  | _, OPne, _ -> Vbool (compare_value v1 v2 <> 0)
  | _, OPlt, _ -> Vbool (compare_value v1 v2 < 0)
  | _, OPgt, _ -> Vbool (compare_value v1 v2 > 0)
  | _, OPle, _ -> Vbool (compare_value v1 v2 <= 0)
  | _, OPge, _ -> Vbool (compare_value v1 v2 >= 0)
  | _ -> raise (Error "unsuported operand types")

let rec expr ctx = function
  | Econst (Cint i) -> Vint i
  | Econst (Cbool b) -> Vbool b
  | Econst (Cstring s) -> Vstring s
  | Econst (Crange (i, (s,f))) -> Vint i
  | Evar var ->
    (try
       let v,t = (Hashtbl.find ctx var) in v
     with Not_found -> raise (Error "undefined variable"))
  | Epair (e1, e2) -> Vpair ((expr ctx e1), (expr ctx e2))
  | Earr (id, e) ->
    (try
       let v,t = Hashtbl.find ctx id in
       match v with
       | Varray ((s,f), arr) ->
         let i = check_bound (expr ctx e) s f in
         (if i >= 0 then
            let i = i-s in arr.(i)
          else raise (Error "index out of bounds"))
       | _ -> raise (Error "variable is not an array")
     with Not_found -> raise (Error "undefined variable"))
  | Ecall (f, a) ->
    (try
       let t, p, b = Hashtbl.find func f in
       let ctx_func = Hashtbl.copy ctx in
       let env_func = Hashtbl.copy env in
       let func_func = Hashtbl.copy func in
       List.iter2 (
         fun (x,tx) v ->
           let v = expr ctx v in
           if compare_types tx v then
             Hashtbl.add ctx_func x (v,tx)
           else raise (Error "invalid argument type")
       ) p a; stmt ctx_func env_func func_func b; Vnull
     with
     | Not_found -> raise (Error "undefined function")
     | Invalid_argument _ -> raise (Error "invalid number of arguments")
     | Return v -> v)
  | EAsize e ->
    (try
       let v = (expr ctx e) in array_size v
     with Error _ ->
     match e with
     | Evar i ->
       (try
          let t = Hashtbl.find env i in (range_size (get_type t))
        with Not_found -> raise (Error "invalid argument") )
     | _ -> raise (Error "invalid argument"))
  | ERsize t -> range_size (get_type t)
  | OPbin (e1, op, e2) -> binop (expr ctx e1) op (expr ctx e2)
  | OPun (op, e) -> unop op (expr ctx e)
  | _ -> assert false
and stmt ctx env func = function
  | Stype (id, t) ->
    let typ = get_type t in
    Hashtbl.add env id typ
  | Slet (id, t, e, b) ->
    (let typ = get_type t in
     let v = expr ctx e in
     if compare_types typ v then
       (Hashtbl.add ctx id (v,typ); stmt ctx env func b; Hashtbl.remove ctx id)
     else raise (Error "incompatible types"))
  | Svar (id, t, e) ->
    (let typ = get_type t in
     let v = expr ctx e in
     match typ with
     | Tarray ((s,f), t1) ->
       if compare_types t1 v then
         (let a = create_array s f v in Hashtbl.add ctx id (a,t1))
       else raise (Error "incompatible types")
     | Trange (s,f) ->
       (let v = expr ctx e in
        let i = check_bound v s f in
        if i >= 0 then
          (Hashtbl.add ctx id (Vint (i), typ))
        else raise (Error "index out of bounds"))
     | _ ->
       if compare_types typ v then
         Hashtbl.add ctx id (v,typ)
       else raise (Error "incompatible types"))
  | Satr (id, e) ->
    (try (let _, t1 = Hashtbl.find ctx id in
          let v = expr ctx e in
          if compare_types t1 v then
            Hashtbl.replace ctx id (v, t1)
          else raise (Error "incompatible types"))
     with Not_found -> raise (Error "undefined variable"))
  | Sset (id, i, e) ->
    (try
       let a, t = Hashtbl.find ctx id in
       let v = (expr ctx e) in
       match a with
       | Varray ((s,f),arr) ->
         (let i = check_bound (expr ctx i) s f in
          if i >= 0 then
            if  compare_types t v then
              let i = i-s in arr.(i) <- v
            else raise (Error "invalid atribution, value out of bounds")
          else raise (Error "index out of bounds"))
       | _ -> raise (Error "invalid atribution")
     with Not_found -> raise (Error "undefined variable"))
  | Sblock l -> List.iter (fun x -> stmt ctx env func x) l
  | Sif (e, s1, s2) ->
    (let v = (expr ctx e) in
     if is_true v then
       stmt ctx env func s1
     else
       stmt ctx env func s2)
  | Sfor (id, t, b) ->
    (let typ = get_type t in
     match typ with
     | Trange (s,f) ->
       if s < f && s >= 0 then
         (Hashtbl.add ctx id (Vint s, Tint); foreach id s (s,f) b; Hashtbl.remove ctx id)
       else raise (Error "invalid range")
     | _ -> raise (Error "invalid type"))
  | Sfunc (f, t, p, b) -> Hashtbl.add func f (t, p, b)
  | Sret e -> raise (Return (expr ctx e))
  | Sprint e -> print (expr ctx e)
and foreach id i (s,f) b =
  if i <= f then
    (stmt ctx env func b; Hashtbl.replace ctx id (Vint(i+1), Tint); foreach id (i+1) (s,f) b)

(* Converts syntatic sugar to primitive types *)
and get_type = function
  | Tvar id ->
    (try
       (let v = Hashtbl.find env id in (get_type v))
     with Not_found -> raise (Error "undefined type variable"))
  | TAcst (c, t) ->
    (let t1 = get_type t in
     match c with
     | Cint i ->
       if i > 0 then
         Tarray ((0, i-1), t1)
       else raise (Error "invalid array size")
     | _ -> raise (Error "invalid array size, must be an integer"))
  | TAvar (id, t) ->
    (let t1 = get_type t in
     try
       let v = Hashtbl.find env id in
       match v with
       | Trange (s,f) -> Tarray ((s,f), t1)
       | _ -> raise (Error "invalid size type")
     with Not_found ->
       (try
          let (v,t) = Hashtbl.find ctx id in
          match v with
          | Vint i ->
            if i > 0 then
              Tarray ((0, i-1), t1)
            else raise (Error "invalid array size")
          | _ -> raise (Error "invalid array size, must be an integer")
        with Not_found -> raise (Error "undefined variable")))
  | Tarray ((s,f), t) ->
    (let t1 = get_type t in
     if (f-s) > 0 && s >= 0 then
       Tarray ((s,f), t1)
     else raise (Error "invalid array size"))
  | Trange_fun e ->
    (let v = (expr ctx e) in
     match v with
     | Vint i ->
       if i > 0 then
         Trange (0, i-1)
       else raise (Error "invalid argument")
     | _ -> raise (Error "invalid argument"))
  | t -> t
let file f =
  List.iter (fun s -> stmt ctx env func s) f
