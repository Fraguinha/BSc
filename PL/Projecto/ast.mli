(* Abstract Syntax Tree *)

type identifier = string

type interval = int * int

type constant =
  | Cint    of int
  | Cbool   of bool
  | Crange  of int * interval
  | Climit  of string
  | Cstring of string

type unop =
  | OPneg
  | OPnot

type binop =
  | OPand | OPor  | OPxor
  | OPadd | OPsub | OPmul | OPdiv | OPmod
  | OPeq  | OPne  | OPlt  | OPgt  | OPle  | OPge

type expression =
  | Econst  of constant
  | Evar    of identifier
  | Epair   of expression * expression
  | Earr    of identifier * expression
  | Ecall   of identifier * expression list
  | EAsize  of expression
  | ERsize  of typ
  | OPbin   of expression * binop * expression
  | OPun    of unop * expression

and typ =
  | Tnull
  | Tint
  | Tbool
  | Tstring
  | Trange      of interval
  | Tvar        of identifier
  | Tfun        of typ * typ
  | Tpair       of typ * typ
  | TAcst       of constant * typ
  | TAvar       of identifier * typ
  | Tarray      of interval * typ
  | Trange_fun  of expression

type statement =
  | Stype   of identifier * typ
  | Slet    of identifier * typ * expression * statement
  | Svar    of identifier * typ * expression
  | Satr    of identifier * expression
  | Sset    of identifier * expression * expression
  | Sfor    of identifier * typ * statement
  | Sif     of expression * statement * statement
  | Sfunc   of identifier * typ * (identifier * typ) list * statement
  | Sprint  of expression
  | Sret    of expression
  | Sblock  of statement list

type program = statement list
