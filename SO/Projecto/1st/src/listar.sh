#!/usr/bin/env bash

case $1 in
1)
	clear
	if [ -e data/universidades.csv ]; then
		echo -e "\033[1mID,Nome,Morada,Contacto,País,ECTS\033[0m"
		cat data/universidades.csv
	else
		echo "Ainda nao existem universidades registadas."
	fi
	echo
	echo "Pressione [enter] para continuar"
	read
	;;
2)
	clear
	if [ -e data/professores.csv ]; then
		echo -e "\033[1mID,Nome,Contacto,Universidade,Departamento\033[0m"
		cat data/professores.csv
	else
		echo "Ainda não existem professores registados."
	fi
	echo
	echo "Pressione [enter] para continuar"
	read
	;;
3)
	clear
	if [ -e data/estudantes.csv ]; then
		echo -e "\033[1mID,Nome,Contacto,Universidade,Curso,Professor,Numero de Disciplinas, Lista de Disciplinas\033[0m"
		cat data/estudantes.csv
	else
		echo "Ainda não existem estudantes registados."
	fi
	echo
	echo "Pressione [enter] para continuar"
	read
	;;
4)
	clear
	if [ -e data/disciplinas.csv ]; then
		echo -e "\033[1mID,Nome,Ano,Semestre,Regente,ECTS\033[0m"
		cat data/disciplinas.csv
	else
		echo "Ainda não existem disciplinas registadas."
	fi
	echo
	echo "Pressione [enter] para continuar"
	read
	;;
esac
