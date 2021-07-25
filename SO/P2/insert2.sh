#!/bin/bash

sort -h <$1 >"/tmp/temp.txt"
mv "/tmp/temp.txt" $1
