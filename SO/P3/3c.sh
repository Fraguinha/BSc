#!/bin/bash

echo "1: mês actual"
echo "2: data actual"
echo "3: ano actual"
echo "4: segundos desde start of time"
echo "5: calendario 1752"
echo "Opcao: "
read op

case $op in
1) cal ;;
2) date ;;
3) cal --year ;;
4) date +%s ;;
5) cal 1752 ;;
*) echo "Selecione uma opcao valida" >&2 ;;
esac
