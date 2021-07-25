#!/bin/bash

echo "1: mês actual"
echo "2: data actual"
echo "Opcao: "
read op

case $op in
1) cal ;;
2) date ;;
*) echo "Selecione uma opcao valida" >&2 ;;
esac
