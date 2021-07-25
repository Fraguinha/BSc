open Stream
open Genlex

type variavel = string
type formula =
  | Implica of formula*formula
  | Equivale of formula*formula
  | Ou of formula*formula
  | E of formula*formula
  | Nand of formula*formula
  | Nao of formula
  | Var of variavel
  | Verdade
  | Falso

let lexer = Genlex.make_lexer ["("; ")"; "<->"; "->"; "|"; "&" ; "!"; "TRUE"; "FALSE"]

let rec parse_expr = parser 
    [< e1 = parse_conj; e = parse_more_imps e1 >] -> e
and parse_more_imps e1 = parser 
    [< 'Kwd "->"; e2 = parse_conj; e = parse_more_imps (Implica(e1, e2)) >] -> e
                       | [< 'Kwd "<->"; e2 = parse_conj; e = parse_more_imps (Equivale(e1, e2)) >] -> e
                       | [< >] -> e1
and parse_conj = parser 
    [< e1 = parse_simple; e = parse_more_conjs e1 >] -> e
and parse_more_conjs e1 = parser 
    [< 'Kwd "&"; e2 = parse_simple; e = parse_more_conjs (E(e1, e2)) >] -> e
                        | [< 'Kwd "|"; e2 = parse_simple; e = parse_more_conjs (Ou(e1, e2)) >] -> e
                        | [< >] -> e1
and parse_simple = parser 
    [< 'Ident s >] -> Var s
                 | [< 'Kwd "TRUE" >] -> Verdade
                 | [< 'Kwd "FALSE" >] -> Falso
                 | [< 'Kwd "!";  'Kwd "("; e = parse_expr; 'Kwd ")" >] -> Nao e
                 | [< 'Kwd "("; e = parse_expr; 'Kwd ")" >] -> e;;

let parse_expression = parser [< e = parse_expr; _ = Stream.empty >] -> e;;

let formula_of_string s =
  parse_expression
    (lexer
       (Stream.of_string (Str.global_replace (Str.regexp "!") "! " s)
       ))

let read_formula () =  formula_of_string (read_line ())

let rec string_of_formula formula =

  match formula with
  | Var v          ->  v
  | Verdade        -> "TRUE"
  | Falso          -> "FALSE"
  | Nao (Var v)    ->  ("!("^ v ^")" )
  | Nao f          ->  ("!"^ string_of_formula f)
  | E(f, g)        -> ("("^ string_of_formula f ^ " & " ^ string_of_formula g ^")")
  | Ou(f, g)       -> ("("^ string_of_formula f ^ " | " ^ string_of_formula g ^")")
  | Implica(f, g)  -> ("("^ string_of_formula f ^ " -> " ^ string_of_formula g ^")")
  | Equivale(f, g) -> ("("^ string_of_formula f ^ " <-> " ^ string_of_formula g ^")")
  | Nand(f,g)      -> ("("^ string_of_formula f ^ " % " ^ string_of_formula g ^")")

let input =  read_formula ()

let rec nand_of_formula formula =

  match formula with 
  | Var v -> formula
  | Verdade -> let z = Var "Z" in Nand(z , Nand(z, z))
  | Falso -> Nand(nand_of_formula Verdade, nand_of_formula Verdade)
  | Nao(E(f,g)) -> Nand(nand_of_formula f, nand_of_formula g)
  | Nao f -> Nand(nand_of_formula f, nand_of_formula f)
  | E (f, g) -> Nand(Nand(nand_of_formula f, nand_of_formula g), Nand(nand_of_formula f, nand_of_formula g))
  | Nand (f,g) -> Nand(nand_of_formula f, nand_of_formula g)
  | Ou (f, g) -> Nand(Nand(nand_of_formula f, nand_of_formula f), Nand(nand_of_formula g, nand_of_formula g))
  | Implica (f, g) -> nand_of_formula (Ou(Nao f, g))
  | Equivale (f, g) -> nand_of_formula (E(Implica(f, g), Implica(g, f)))

let () =  Format.printf "%s@."  (string_of_formula (nand_of_formula input))