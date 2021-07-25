#!/bin/bash

VAR=$(sort -n $1 | tail -n 1 | cut -d ':' -f 1)
let RES=$VAR+1
echo $RES
