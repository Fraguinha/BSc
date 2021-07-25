#!/usr/bin/env bash

case $1 in
1)
	clear
	echo '1. Pesquisar por ID'
	echo '2. Pesquisar por nome'
	echo
	echo -n 'Selecione uma opcao: '
	read op
	if [ $op -eq 1 ] || [ $op -eq 2 ]; then
		echo -n 'Pesquisa: '
		read valor
		awk -F, -v var="$valor" -v op="$op" '$op!=var' data/universidades.csv >/tmp/deleteTmp
		cat /tmp/deleteTmp >data/universidades.csv
		echo
	else
		echo "Comando Invalido"
		read
	fi
	echo "Pressione [enter] para continuar"
	read op
	;;
2)
	clear
	echo '1. Pesquisar por ID'
	echo '2. Pesquisar por nome'
	echo
	echo -n 'Selecione uma opcao: '
	read op
	if [ $op -eq 1 ] || [ $op -eq 2 ]; then
		echo -n 'Pesquisa: '
		read valor
		awk -F, -v var="$valor" -v op="$op" '$op!=var' data/professores.csv >/tmp/deleteTmp
		cat /tmp/deleteTmp >data/professores.csv
		echo
	else
		echo "Comando Invalido"
		read
	fi
	echo "Pressione [enter] para continuar"
	read op
	;;
3)
	clear
	echo '1. Pesquisar por ID'
	echo '2. Pesquisar por nome'
	echo
	echo -n 'Selecione uma opcao: '
	read op
	if [ $op -eq 1 ] || [ $op -eq 2 ]; then
		echo -n 'Pesquisa: '
		read valor
		awk -F, -v var="$valor" -v op="$op" '$op!=var' data/estudantes.csv >/tmp/deleteTmp
		cat /tmp/deleteTmp >data/estudantes.csv
		echo
	else
		echo "Comando Invalido"
		read
	fi
	echo "Pressione [enter] para continuar"
	read op
	;;
4)
	clear
	echo '1. Pesquisar por ID'
	echo '2. Pesquisar por nome'
	echo
	echo -n 'Selecione uma opcao: '
	read op
	if [ $op -eq 1 ] || [ op -eq 2 ]; then
		echo -n 'Pesquisa: '
		read valor
		awk -F, -v var="$valor" -v op="$op" '$op!=var' data/disciplinas.csv >/tmp/deleteTmp
		cat /tmp/deleteTmp >data/disciplinas.csv
		echo
	else
		echo "Comando Invalido"
		read
	fi
	echo "Pressione [enter] para continuar"
	read op
	;;
esac
