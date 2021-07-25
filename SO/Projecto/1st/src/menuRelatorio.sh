#!/usr/bin/env bash

clear
echo "Menu Relatorios"
echo
echo "1. Mostrar numero medio de disciplinas"
echo "2. Mostrar país de origem mais comum"
echo "3. Listar disciplinas com estudantes"
echo "4. Mostrar disciplina mais escolhida pelos estudantes"
echo
echo "0. Voltar"
echo
echo -n "Selecione uma opcao: "
read op
if [ $op -lt 0 ] || [ $op -gt 4 ]; then
	op=127
fi
exit $op
