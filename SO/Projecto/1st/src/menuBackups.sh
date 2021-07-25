#!/usr/bin/env bash

clear
echo "Menu Backups"
echo
echo "1. Criar backup"
echo "2. Restaurar backup"
echo "3. Apagar backup"
echo
echo "0. Voltar"
echo
echo -n "Selecione uma opcao: "
read op
if [ $op -lt 0 ] || [ $op -gt 3 ]; then
	op=127
fi
exit $op
