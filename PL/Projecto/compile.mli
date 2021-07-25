exception Error of string

val compile_program : string -> Ast.program -> unit
(** [compile_program f p] compila o programa [p] e escreve o código X86-64
    correspondente no ficheiro [f] *)
