(* Lexer *)

{
  open Lexing
  open Parser
  open Ast

  exception Lexing_error of string

  let id_or_kwd =
    let h = Hashtbl.create 32 in
    List.iter (fun (s, tok) -> Hashtbl.add h s tok) [
      "true", CST (Cbool true); "false", CST (Cbool false);
      "minint", CST (Climit "min"); "maxint", CST (Climit "max");
      "print", PRINT;
      "range", RANGE;
      "size", SIZE;
      "in", IN;
      "let", LET;
      "var", VAR;
      "type", TYPE; "int", INT; "null", NULL; "bool", BOOL; "string", STRING;
      "array", ARRAY; "of", OF; "filled", FILLED; "by", BY;
      "if", IF; "then", THEN; "else", ELSE;
      "foreach", FOREACH; "do", DO;
      "function", FUNCTION; "return", RETURN;
    ];
    fun s -> try Hashtbl.find h s with Not_found -> IDENTIFIER s

  let num1_buffer = Buffer.create 20
  let num2_buffer = Buffer.create 20

  let rec parse_range s flag =
    if String.length s > 0 then
      let c = String.get s 0 in
      let i = int_of_char c in
      if i >= 48 && i <= 57 then
        (if flag then
          Buffer.add_char num1_buffer c
        else
          Buffer.add_char num2_buffer c;
        parse_range (String.sub s 1 ((String.length s) - 1)) flag)
      else parse_range (String.sub s 1 ((String.length s) - 1)) false

  let string_buffer = Buffer.create 1024
  let level = ref 0
}

let space = [' ' '\t']+

let comment = "//" [^ '\n']* '\n'

let character = ['a'-'z' 'A'-'Z' '_']
let number = ['0'-'9']+

let range = number space? ".." space? number

let identifier = character (character | number)*

rule token = parse
  | '\n' { new_line lexbuf; token lexbuf }
  | (space | comment)+ { token lexbuf }
  | identifier as id { [id_or_kwd id] }
  | ":=" { [ATRIBUTION] }
  | "->" { [ARROW] }
  | '=' { [EQUAL] }
  | ':' { [COLON] }
  | '[' { [LSB] }
  | ']' { [RSB] }
  | '{' { [LCB] }
  | '}' { [RCB] }
  | '(' { [LP] }
  | ')' { [RP] }
  | '!' { [NOT] }
  | '&' { [AND] }
  | '|' { [OR] }
  | '^' { [XOR] }
  | '<' { [LT] }
  | '>' { [GT] }
  | "<=" { [LE] }
  | ">=" { [GE] }
  | "==" { [EQ] }
  | "!=" { [NE] }
  | '+' { [ADD] }
  | '-' { [SUB] }
  | '*' { [MUL] }
  | '/' { [DIV] }
  | '%' { [MOD] }
  | ',' { [COMMA] }
  | ';' { [SEMICOLON] }
  | eof     { [EOF] }
  | range as s {
    Buffer.reset num1_buffer; Buffer.reset num2_buffer; parse_range s true;
    [INTERVAL ((int_of_string (Buffer.contents num1_buffer), int_of_string (Buffer.contents num2_buffer)))]
  }
  | number as s {
    try [CST (Cint (int_of_string s))]
    with _ -> raise (Lexing_error ("constant too large: " ^ s))
  }
  | "(*"    { level := 1; comment lexbuf; token lexbuf }
  | '"'     { [CST (Cstring (string lexbuf))] }
  | _ as c  { raise (Lexing_error ("illegal character: " ^ String.make 1 c)) }

and comment = parse
  | "*)"  { level := !level - 1; if !level > 0 then comment lexbuf }
  | "(*"  { level := !level + 1; comment lexbuf }
  | _     { comment lexbuf }
  | eof { raise (Lexing_error "unterminated comment") }

and string = parse
  | '"'
    {
      let s = Buffer.contents string_buffer in
      Buffer.reset string_buffer;
      s
    }
  | "\\t"
    {
      Buffer.add_char string_buffer '\t';
      string lexbuf
    }
  | "\\n"
    {
      Buffer.add_char string_buffer '\n';
      string lexbuf
    }
  | "\\\""
    {
      Buffer.add_char string_buffer '"';
      string lexbuf
    }
  | _ as c
    {
      Buffer.add_char string_buffer c;
      string lexbuf
    }
  | eof { raise (Lexing_error "unterminated string") }

{
  let next_token =
    let queue = Queue.create () in
    fun lb ->
      if Queue.is_empty queue then
      begin
        let l = token lb in
        List.iter (fun t -> Queue.add t queue) l
      end;
      Queue.pop queue
}
