CMO=lexer.cmo parser.cmo interpret.cmo x86_64.cmo compile.cmo main.cmo
GENERATED =lexer.ml parser.ml parser.mli
FLAGS=-annot -g

.PHONY: tests
tests: natrix
	sh run-tests

all: natrix
	tests

natrix: $(CMO)
	ocamlc $(FLAGS) -o $@ $(CMO)

.SUFFIXES: .ml .mll .mly .mli .cmi .cmo

.mli.cmi:
	ocamlc $(FLAGS) -c $<

.ml.cmo:
	ocamlc $(FLAGS) -c $<

.mll.ml:
	ocamllex $<

.mly.ml:
	menhir -v $<

.mly.mli:
	menhir -v $<

clean:
	rm -f *.cm[io] *.o *.annot *~ natrix $(GENERATED)
	rm -f parser.output parser.automaton
	rm -f .depend

.depend depend:$(GENERATED)
	rm -f .depend
	ocamldep *.ml *.mli > .depend

include .depend
