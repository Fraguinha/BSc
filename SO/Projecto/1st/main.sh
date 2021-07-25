#!/usr/bin/env bash

op=127

if ! [ -d data/ ]; then
	mkdir data
fi

if ! [ -d backup/user ]; then
	mkdir -p backup/user/
fi

until [ $op -eq 0 ]; do
	clear
	echo "Gestao de Erasmus"
	echo
	echo "1. Registar"
	echo "2. Editar"
	echo "3. Eliminar"
	echo "4. Consultar"
	echo "5. Listar"
	echo "6. Relatorio"
	echo "7. Backups"
	echo
	echo "0. Sair"
	echo
	echo -n "Selecione uma opcao: "
	read op
	if [ $op -lt 0 ] || [ $op -gt 7 ]; then
		op=127
	fi
	case $op in
	0) ;;
	1)
		./src/menuEntidade.sh "Registar"
		./src/registar.sh $?
		;;
	2)
		./src/menuEntidade.sh "Editar"
		./src/editar.sh $?
		;;
	3)
		./src/menuEntidade.sh "Eliminar"
		./src/eliminar.sh $?
		;;
	4)
		./src/menuEntidade.sh "Consultar"
		./src/consultar.sh $?
		;;
	5)
		./src/menuEntidade.sh "Listar"
		./src/listar.sh $?
		;;
	6)
		./src/menuRelatorio.sh
		./src/relatorio.sh $?
		;;
	7)
		./src/menuBackups.sh
		./src/backup.sh $?
		;;
	*)
		echo "Opcao invalida"
		echo "Pressione [enter] para continuar"
		read
		;;
	esac
done
