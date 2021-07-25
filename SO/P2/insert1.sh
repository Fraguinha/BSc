#!/bin/bash

echo "ID:"
read ID

echo "NOME:"
read NOME

echo "QUANTIDADE:"
read QUANTIDADE

echo $ID:$NOME:$QUANTIDADE >>$1
