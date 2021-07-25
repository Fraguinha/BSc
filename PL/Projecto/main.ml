(* Libraries *)
open Lexing
open Parser

(* Variables *)
let parse_only = ref false
let intrepret = ref false
let ifile = ref ""
let ofile = ref "a.s"

(* Commandline options *)
let option = [
  "--parse-only", Arg.Set parse_only, "  stop after parsing";
  "--interpret", Arg.Set intrepret, "  run as an interpreter";
  "-o", Arg.String (fun s -> ofile := s), "  set output file"
]
let usage = "usage: natrixc [options] filename.nx"

let file =
  let file = ref None in
  let set_file s =
    if not (Filename.check_suffix s ".nx") then
      raise (Arg.Bad "no .nx extension");
    file := Some s
  in
  Arg.parse option set_file usage;
  match !file with
  | Some f -> f
  | None -> Arg.usage option usage; exit 1

let report (start, finish) =
  let line = start.pos_lnum in
  let first = start.pos_cnum - start.pos_bol + 1 in
  let last = finish.pos_cnum - finish.pos_bol + 1 in
  Printf.eprintf "Error in file: \"%s\", line %d, characters %d-%d:\n" file line first last

let () =
  let c = open_in file in
  let lexbuf = Lexing.from_channel c in
  try
    let program = Parser.program Lexer.next_token lexbuf in
    close_in c;
    if !parse_only then exit 0;
    if !intrepret then
      Interpret.file program
    else
      Compile.compile_program !ofile program
  with
  | Lexer.Lexing_error s ->
    report (lexeme_start_p lexbuf, lexeme_end_p lexbuf);
    Printf.eprintf "lexical error: %s\n" s;
    exit 1
  | Parser.Error ->
    report (lexeme_start_p lexbuf, lexeme_end_p lexbuf);
    Printf.eprintf "syntax error\n";
    exit 1
  | Interpret.Error s ->
    Printf.eprintf "error: %s\n" s;
    exit 1
  | Compile.Error s ->
    Printf.eprintf "error: %s\n" s;
    exit 1
  | e ->
    Printf.eprintf "Anomaly: %s\n" (Printexc.to_string e);
    exit 2
