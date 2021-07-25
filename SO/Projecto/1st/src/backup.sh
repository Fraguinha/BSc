#!/usr/bin/env bash

case $1 in
1)
	echo
	tar -czf "backup/user/$(date).tar.gz" data 2>/dev/null && echo "Backup criado com sucesso" || echo "Backup falhou"
	echo "Pressione [enter] para continuar"
	read
	;;
2)
	echo -n >/tmp/backuplist
	ls -1 backup/user >>/tmp/backuplist
	OPNUM=$(wc -l </tmp/backuplist)
	echo
	echo "Backups disponiveis:"
	echo
	nl /tmp/backuplist
	echo
	echo -n "Selecione qual o ficheiro que pretende restaurar: "
	read op
	if [ $op -ge 1 ] && [ $op -le $OPNUM ]; then
		NAME=$(sed -n ${op}p /tmp/backuplist)
		FILE=$(find . -name "$NAME")
		tar -xzf "$FILE" -C /tmp && rm -r ./data && mv /tmp/data . && echo "Backup restaurado com sucesso"
		echo "Pressione [enter] para continuar"
		read
	else
		echo "Ficheiro invalido"
		echo "Pressione [enter] para continuar"
		read
	fi
	;;
3)
	echo -n >/tmp/backuplist
	ls -1 backup/user >>/tmp/backuplist
	OPNUM=$(wc -l < /tmp/backuplist)
	echo
	echo "Backups disponiveis:"
	echo
	nl /tmp/backuplist
	echo
	echo -n "Selecione qual o ficheiro que pretende remover: "
	read op
	if [ $op -ge 1 ] && [ $op -le $OPNUM ]; then
		NAME=$(sed -n ${op}p /tmp/backuplist)
		FILE=$(find . -name "$NAME")
		rm "$FILE" && echo "Backup removido com sucesso"
		echo "Pressione [enter] para continuar"
		read
	else
		echo "Ficheiro invalido"
		echo "Pressione [enter] para continuar"
		read
	fi
	;;
esac
