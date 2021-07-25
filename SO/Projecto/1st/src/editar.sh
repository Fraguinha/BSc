#!/usr/bin/env bash

op=127

case $1 in
1)
	clear
	echo -n 'ID: '
	read id
	until [ $op -eq 0 ]; do
		clear
		line=$(awk -F, -v var="$id" '$1==var' data/universidades.csv)
		echo -e "\033[1m$line\033[0m"
		echo
		echo "1. Nome"
		echo "2. Contacto"
		echo "3. Morada"
		echo "4. Pais"
		echo "5. ECTS"
		echo
		echo "0. Voltar"
		echo
		echo -n "Selecione o campo que pretende alterar: "
		read op
		if [ $op -ge 1 ] && [ $op -le 5 ]; then
			let column=$op+1
			let oc=(2*$op)+1
			old=$(echo $line | cut -d ',' -f $column)
			echo -n "Selecionou: "
			echo $old
			echo
			echo -n "Introduza novo: "
			read new
			sed -i -e "/^$id,/s/[^,]*/$new/$oc" data/universidades.csv
			rm data/universidades.csv-e
		elif [ $op -ne 0 ]; then
			echo "Opcao Invalida."
			read
		fi
	done
	;;
2)
	clear
	echo -n 'ID: '
	read id
	until [ $op -eq 0 ]; do
		clear
		line=$(awk -F, -v var="$id" '$1==var' data/professores.csv)
		echo -e "\033[1m$line\033[0m"
		echo
		echo "1. Nome"
		echo "2. Contacto"
		echo "3. Universidade"
		echo "4. Departamento"
		echo
		echo "0. Voltar"
		echo
		echo -n "Selecione o campo que pretende alterar: "
		read op
		if [ $op -ge 1 ] && [ $op -le 4 ]; then
			let column=$op+1
			let oc=(2*$op)+1
			old=$(echo $line | cut -d ',' -f $column)
			echo -n "Selecionou: "
			echo $old
			echo
			echo -n "Introduza novo: "
			read new
			sed -i -e "/^$id,/s/[^,]*/$new/$oc" data/professores.csv
			rm data/professores.csv-e
		elif [ $op -ne 0 ]; then
			echo "Opcao Invalida."
			read
		fi
	done
	;;
3)
	clear
	echo -n 'ID: '
	read id
	until [ $op -eq 0 ]; do
		clear
		line=$(awk -F, -v var="$id" '$1==var' data/estudantes.csv)
		echo -e "\033[1m$line\033[0m"
		echo
		echo "1. Nome"
		echo "2. Contacto"
		echo "3. Universidade"
		echo "4. Curso"
		echo "5. Professor"
		echo "6. Adicionar Disciplina"
		echo "7. Remover Disciplinas"
		echo
		echo "0. Voltar"
		echo
		echo -n "Selecione o campo que pretende alterar: "
		read op
		if [ $op -ge 1 ] && [ $op -le 5 ]; then
			let column=$op+1
			let oc=(2*$op)+1
			old=$(echo $line | cut -d ',' -f $column)
			echo -n "Selecionou: "
			echo $old
			echo
			echo -n "Introduza novo: "
			read new
			sed -i -e "/^$id,/s/[^,]*/$new/$oc" data/estudantes.csv
		elif [ $op -eq 6 ]; then
			echo -n "ID da Disciplina: "
			read new
			totD=$(echo $line | cut -d ',' -f 7)
			let column=$totD+7
			old=$(echo $line | cut -d ',' -f $column)
			let oc=$column*2-1
			let tc=7*2-1
			let totD++
			sed -i -e "/^$id,/s/[^,]*/$totD/$tc" data/estudantes.csv
			sed -i -e "/^$id,/s/[^,]*/"$old,$new"/$oc" data/estudantes.csv
		elif [ $op -eq 7 ]; then
			echo -n "ID da disciplina: "
			read disp
			totD=$(echo $line | cut -d ',' -f 7)
			for i in $(seq 1 $totD); do
				let column=7+$i
				old=$(echo $line | cut -d ',' -f $column)
				if [ $old = $disp ]; then
					let oc=$column*2-1
					let tc=7*2-1
					let totD--
					let virg=$column-1
					sed -i -e "/^$id,/s/[^,]*/$totD/$tc" data/estudantes.csv
					sed -i -e "/^$id,/s/[^,]*//$oc" data/estudantes.csv
					sed -i -e "/^$id,/s/,//$virg" data/estudantes.csv
				fi
			done
		elif [ $op -ne 0 ]; then
			echo "Opcao Invalida"
			read
		fi
		if [ -e data/estudantes.csv-e ]; then
			rm data/estudantes.csv-e
		fi
	done
	;;
4)
	clear
	echo -n 'ID: '
	read id
	until [ $op -eq 0 ]; do
		clear
		line=$(awk -F, -v var="$id" '$1==var' data/disciplinas.csv)
		echo -e "\033[1m$line\033[0m"
		echo
		echo "1. Nome"
		echo "2. Ano"
		echo "3. Semestre"
		echo "4. Regente"
		echo "5. ECTS"
		echo
		echo "0. Voltar"
		echo
		echo -n "Selecione o campo que pretende alterar: "
		read op
		if [ $op -ge 1 ] && [ $op -le 5 ]; then
			let column=$op+1
			let oc=(2*$op)+1
			old=$(echo $line | cut -d ',' -f $column)
			echo -n "Selecionou: "
			echo $old
			echo
			echo -n "Introduza novo: "
			read new
			sed -i -e "/^$id,/s/[^,]*/$new/$oc" data/disciplinas.csv
			rm data/disciplinas.csv-e
		elif [ $op -ne 0 ]; then
			echo "Opcao Invalida."
			read
		fi
	done
	;;
esac
