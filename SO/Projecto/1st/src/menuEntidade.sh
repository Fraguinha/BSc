#!/usr/bin/env bash

clear
echo "Menu" $1
echo
echo "1. Universidade"
echo "2. Professor"
echo "3. Estudante"
echo "4. Disciplina"
echo
echo "0. Voltar"
echo
echo -n "Selecione uma opcao: "
read op
if [ $op -lt 0 ] || [ $op -gt 4 ]; then
	op=127
fi
exit $op
