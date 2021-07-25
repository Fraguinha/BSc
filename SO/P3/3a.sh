#!/bin/bash

echo "1: mês actual"
echo "2: data actual"
echo "Opcao: "
read op

if [ $op -eq 1 ]; then
	cal
elif [ $op -eq 2 ]; then
	date
else
	echo "Selecione uma opcao valida" >&2
fi
