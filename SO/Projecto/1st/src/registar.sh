#!/usr/bin/env bash

case $1 in
1)
	echo -n "ID: "
	read id
	echo -n "Nome: "
	read nome
	echo -n "Contacto: "
	read contacto
	echo -n "Morada: "
	read morada
	echo -n "Pais: "
	read pais
	echo -n "Numero maximo creditos: "
	read n_creditos
	echo $id,$nome,$contacto,$morada,$pais,$n_creditos >>./data/universidades.csv
	;;
2)
	echo -n "ID: "
	read id
	echo -n "Nome: "
	read nome
	echo -n "Contacto: "
	read contacto
	echo -n "Universidade: "
	read universidade
	echo -n "Departamento: "
	read departamento
	echo $id,$nome,$contacto,$universidade,$departamento >>./data/professores.csv
	;;
3)
	echo -n "ID: "
	read id
	echo -n "Nome: "
	read nome
	echo -n "Contacto: "
	read contacto
	echo -n "ID da universidade: "
	read universidade
	echo -n "Curso: "
	read curso
	echo -n "ID do professor: "
	read professor
	echo -n "Numero de Disciplinas: "
	read ndisciplinas
	echo -n "Escreva os codigos das disciplinas separadas por virgulas: "
	read disciplinas
	echo $id,$nome,$contacto,$universidade,$curso,$professor,$ndisciplinas,$disciplinas >>./data/estudantes.csv
	;;
4)
	echo -n "ID: "
	read id
	echo -n "Nome: "
	read nome
	echo -n "Ano: "
	read ano
	echo -n "Semestre: "
	read semestre
	echo -n "Regente: "
	read regente
	echo -n "Creditos: "
	read creditos
	echo $id,$nome,$ano,$semestre,$regente,$creditos >>./data/disciplinas.csv
	;;
esac
