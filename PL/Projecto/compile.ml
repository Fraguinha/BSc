open Format
open X86_64
open Ast

exception Error of string

(* Frame size, in byte (each variable takes 8 bytes) *)
let frame_size = ref 0

(* Global variables *)
let (genv : (string, unit) Hashtbl.t) = Hashtbl.create 17

module StrMap = Map.Make(String)

(* Compiling an expression *)
let compile_expr =
  let rec comprec env next = function
    | Econst (Cint i) -> movq (imm i) (reg rax)
    | Econst (Cbool b) ->
      if b then
        movq (imm 1) (reg rax)
      else
        movq (imm 0) (reg rax)
    | Econst (Crange (i, (s,f))) -> movq (imm i) (reg rax)
    | Econst (Climit s) -> assert false
    | Econst (Cstring s) -> assert false
    | Evar id ->
      (try
         let ofs = - (StrMap.find id env) in
         movq (ind ~ofs rbp) (reg rax)
       with Not_found ->
         if not (Hashtbl.mem genv id) then raise (Error "undefined variable");
         movq (lab id) (reg rax))
    | Epair (e1, e2) -> assert false
    | Earr (id, e) -> assert false
    | Ecall (id, lst) -> assert false
    | OPbin (e1, OPdiv, e2) ->
      comprec env next e1 ++
      pushq (reg rax) ++
      comprec env next e2 ++
      movq (reg rax) (reg rbx) ++
      movq (imm 0) (reg rdx) ++
      popq rax ++
      idivq (reg rbx)
    | OPbin (e1, OPmod, e2) ->
      comprec env next e1 ++
      pushq (reg rax) ++
      comprec env next e2 ++
      movq (reg rax) (reg rbx) ++
      movq (imm 0) (reg rdx) ++
      popq rax ++
      idivq (reg rbx) ++
      movq (reg rdx) (reg rax)
    | OPbin (e1, op, e2) ->
      let op = match op with
        | OPadd -> addq
        | OPsub -> subq
        | OPmul -> imulq
        | OPand -> andq
        | OPor -> orq
        | OPxor -> xorq
        | OPeq -> assert false
        | OPne -> assert false
        | OPlt -> assert false
        | OPgt -> assert false
        | OPle -> assert false
        | OPge -> assert false
        | _ -> assert false
      in
      comprec env next e1 ++
      pushq (reg rax) ++
      comprec env next e2 ++
      movq (reg rax) (reg rbx) ++
      popq rax ++
      op (reg rbx) (reg rax)
    | OPun (op, e) -> assert false
    | EAsize (e) -> assert false
    | ERsize (t) -> assert false
  in
  comprec StrMap.empty 0

(* Compiling an instruction *)
let compile_instr = function
  | Stype (id, t) -> assert false
  | Slet (id, t, e, s) -> assert false
  | Svar (id, t, e) ->
    let code =
      compile_expr e ++
      movq (reg rax) (lab id)
    in
    Hashtbl.replace genv id ();
    code
  | Satr (id, e) -> assert false
  | Sset (id, e1, e2) -> assert false
  | Sfor (id, e, s) -> assert false
  | Sif (id, s1, s2) -> assert false
  | Sfunc (id, t, p, s) -> assert false
  | Sret (e) -> assert false
  | Sblock (e) -> assert false
  | Sprint (e) ->
    match e with
    | Econst (Cint i) ->
      compile_expr e ++
      movq (reg rax) (reg rdi) ++
      call "print_int" ++
      movq (reg rax) (reg rdi) ++
      call "print_newline"
    | Econst (Cbool b) ->
      compile_expr e ++
      movq (reg rax) (reg rdi) ++
      call "print_bool" ++
      movq (reg rax) (reg rdi) ++
      call "print_newline"
    | Evar v ->
      compile_expr e ++
      movq (reg rax) (reg rdi) ++
      call "print_int" ++
      movq (reg rax) (reg rdi) ++
      call "print_newline"
    | _ -> assert false


(* Compiling a program *)
let compile_program ofile program =
  let code = List.map compile_instr program in
  let code = List.fold_right (++) code nop in
  let program =
    { text =
        globl "main" ++
        label "main" ++
        subq (imm !frame_size) (reg rsp) ++
        leaq (ind ~ofs:(!frame_size - 8) rsp) rbp ++
        code ++
        addq (imm !frame_size) (reg rsp) ++
        movq (imm 0) (reg rax) ++
        ret ++
        label "print_newline" ++
        movq (reg rdi) (reg rsi) ++
        movq (ilab ".Sprint_newline") (reg rdi) ++
        movq (imm 0) (reg rax) ++
        call "printf" ++
        ret ++
        label "print_int" ++
        movq (reg rdi) (reg rsi) ++
        movq (ilab ".Sprint_int") (reg rdi) ++
        movq (imm 0) (reg rax) ++
        call "printf" ++
        ret ++
        label "print_string" ++
        movq (reg rdi) (reg rsi) ++
        movq (ilab ".Sprint_string") (reg rdi) ++
        movq (imm 0) (reg rax) ++
        call "printf" ++
        ret ++
        label "print_null" ++
        movq (reg rdi) (reg rsi) ++
        movq (ilab ".Sprint_null") (reg rdi) ++
        movq (imm 0) (reg rax) ++
        call "printf" ++
        ret ++
        label "print_bool" ++
        cmpq (imm 0) (reg rdi) ++
        je (".Lfalse") ++
        movq (ilab ".Sprint_true") (reg rdi) ++
        jmp (".Lprint") ++
        label ".Lfalse" ++
        movq (ilab ".Sprint_false") (reg rdi) ++
        label ".Lprint" ++
        movq (imm 0) (reg rax) ++
        call "printf" ++
        ret ++
        label "print_maxint" ++
        movq (reg rdi) (reg rsi) ++
        movq (ilab ".Sprint_maxint") (reg rdi) ++
        movq (imm 0) (reg rax) ++
        call "printf" ++
        ret ++
        label "print_minint" ++
        movq (reg rdi) (reg rsi) ++
        movq (ilab ".Sprint_minint") (reg rdi) ++
        movq (imm 0) (reg rax) ++
        call "printf" ++
        ret;
      data =
        Hashtbl.fold (fun x _ l -> label x ++ dquad [1] ++ l) genv
          (label ".Sprint_newline" ++ string "\n") ++
        (label ".Sprint_int" ++ string "%d") ++
        (label ".Sprint_string" ++ string "%s") ++
        (label ".Sprint_null" ++ string "null") ++
        (label ".Sprint_true" ++ string "true") ++
        (label ".Sprint_false" ++ string "false") ++
        (label ".Sprint_maxint" ++ string "maxint") ++
        (label ".Sprint_minint" ++ string "minint")
    }
  in
  X86_64.print_in_file ~file: ofile program
