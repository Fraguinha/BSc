/* Parser */

%{
  open Ast
%}

/* Token definition */

%token <Ast.identifier> IDENTIFIER
%token <Ast.interval> INTERVAL
%token <Ast.constant> CST

%token PRINT RANGE SIZE
%token NULL BOOL INT STRING
%token LET IN VAR TYPE ARRAY OF FILLED BY IF THEN ELSE FOREACH DO FUNCTION RETURN
%token ATRIBUTION ARROW EQUAL COLON LSB RSB LCB RCB LP RP COMMA SEMICOLON EOF
%token ADD SUB MUL DIV MOD
%token NOT AND OR XOR
%token GT LT GE LE EQ NE

/* Priority and Associativity definition of tokens */

%left OR
%left AND
%left XOR
%left ADD SUB
%left MUL DIV MOD

%nonassoc NOT
%nonassoc GT LT GE LE EQ NE
%nonassoc LSB
%nonassoc LCB
%nonassoc LP
%nonassoc COMMA
%nonassoc ARROW

/* Grammar start */
%start program

/* Return type */
%type <Ast.program> program

%%

program:
  stmt = nonempty_list( statement ) EOF { stmt }
;

statement:
  s = simple_statement SEMICOLON { s }
| IF e = expression THEN b1 = block ELSE b2 = block { Sif(e, b1, b2) }
| FOREACH id = IDENTIFIER IN t = type_value DO b = block { Sfor(id, t, b) }
| FUNCTION id = IDENTIFIER COLON t = type_value p = parameters b = block { Sfunc(id, t, p, b) }
| LET id = IDENTIFIER COLON typ = type_value set e = expression IN b = block { Slet(id, typ, e, b)}
;

parameters:
  LP  l = separated_list(SEMICOLON, single_parameter) RP { l }

single_parameter:
 id = IDENTIFIER COLON t = type_value { (id,t) }

block:
  LCB s = nonempty_list(statement) RCB { Sblock(s) }
| s = statement { s }
;

simple_statement:
  VAR id = IDENTIFIER COLON typ = type_value set e = expression { Svar(id, typ, e) }
| TYPE id = IDENTIFIER EQUAL t = type_value { Stype(id, t) }
| id = IDENTIFIER ATRIBUTION e = expression { Satr(id, e) }
| id = IDENTIFIER LSB i = expression RSB ATRIBUTION e = expression { Sset(id, i, e) }
| RETURN e = expression { Sret(e) }
| PRINT LP e = expression RP { Sprint(e) }
;

set:
  EQUAL {}
| FILLED BY {}
;

expression:
  LP e = expression RP { e }
| c = CST { Econst(c) }
| id = IDENTIFIER { Evar(id) }
| id = IDENTIFIER LSB e = expression RSB { Earr(id, e) }
| op = unop e = expression { OPun(op, e) }
| e1 = expression op = binop e2 = expression { OPbin(e1, op, e2) }
| e1 = expression COMMA e2 = expression { Epair(e1,e2) }
| f = IDENTIFIER LP x = separated_list(SEMICOLON, expression) RP { Ecall(f, x) }
| SIZE LP e = expression RP { EAsize(e) }
| SIZE LP i = INTERVAL RP { ERsize(Trange(i)) }
;

array:
  ARRAY c = CST OF t = type_value { TAcst(c, t) }
| ARRAY id = IDENTIFIER OF t = type_value { TAvar(id, t) }
| ARRAY i = INTERVAL OF t = type_value { Tarray(i, t) }
;

type_value:
  p = primitive { p }
| LP t1 = type_value MUL t2 = type_value RP { Tpair(t1, t2)}
| LP t1 = type_value ARROW t2 = type_value RP { Tfun(t1, t2)}
| id = IDENTIFIER { Tvar(id) }
| RANGE LP e = expression RP { Trange_fun(e) }
| i = INTERVAL { Trange(i) }
| a = array { a }
;

%inline primitive:
  INT { Tint }
| NULL { Tnull }
| BOOL { Tbool }
| STRING { Tstring }
;

%inline unop:
  SUB { OPneg }
| NOT { OPnot }
;

%inline binop:
  c = cmp { c }
| ADD { OPadd }
| SUB { OPsub }
| MUL { OPmul }
| DIV { OPdiv }
| MOD { OPmod }
| OR { OPor }
| XOR { OPxor }
| AND { OPand }
;

%inline cmp:
  GT { OPgt }
| LT { OPlt }
| GE { OPge }
| LE { OPle }
| EQ { OPeq }
| NE { OPne }
