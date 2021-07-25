#!/usr/bin/env bash

case $1 in
1)
	nalunos=$(wc -l <data/estudantes.csv)
	sum=0
	for i in $(seq 1 $nalunos); do
		let sum+=$(head -n $i data/estudantes.csv | tail -n 1 | cut -d ',' -f 7)
	done
	let avg=sum/nalunos
	echo $avg
	echo "Pressione [enter] para continuar"
	read
	;;
2)
	nalunos=$(wc -l <data/estudantes.csv)
	echo >/tmp/uniList
	for i in $(cat data/estudantes.csv); do
		echo $i | cut -d ',' -f 4 >>/tmp/uniList
	done
	echo >/tmp/ctList
	for i in $(cat /tmp/uniList); do
		awk -F, -v var="$i" '$1==var' data/universidades.csv | cut -d ',' -f 5 >>/tmp/ctList
	done
	sort /tmp/ctList | uniq >/tmp/uctList
	max=0
	for i in $(cat /tmp/uctList); do
		temp=$(grep -c $i /tmp/ctList)
		if [ $temp -gt $max ]; then
			max=$temp
			most=$i
		elif [ $temp -eq $max ]; then
			most=$most,$i
		fi
	done
	echo $most
	echo "Pressione [enter] para continuar"
	read
	;;
3)
	nalunos=$(wc -l <data/estudantes.csv)
	echo >/tmp/dispList
	for i in $(cat data/estudantes.csv); do
		num=$(echo $i | cut -d ',' -f 7)
		for i in $(seq 1 $num); do
			let j=$i+7
			echo $i | cut -d ',' -f $j >>/tmp/dispList
		done
	done
	sort /tmp/dispList | uniq >/tmp/udispList
	echo
	for i in $(cat /tmp/udispList); do
		awk -F, -v var="$i" '$1==var' data/disciplinas.csv | cut -d ',' -f 2
	done
	echo "Pressione [enter] para continuar"
	read
	;;
4)
	nalunos=$(wc -l <data/estudantes.csv)
	echo >/tmp/dispList
	for i in $(cat data/estudantes.csv); do
		num=$(echo $i | cut -d ',' -f 7)
		for j in $(seq 1 $num); do
			let k=$j+7
			disp=$(echo $i | cut -d ',' -f $k)
			echo $disp >>/tmp/dispList
		done
	done
	sort /tmp/dispList | uniq >/tmp/udispList
	max=0
	echo >/tmp/most
	for i in $(cat /tmp/udispList); do
		temp=$(grep -c $i /tmp/dispList)
		if [ $temp -gt $max ]; then
			max=$temp
			echo $i >/tmp/most
		elif [ $temp -eq $max ]; then
			echo $i >>/tmp/most
		fi
	done
	echo
	for i in $(cat /tmp/most); do
		awk -F, -v var="$i" '$1==var' data/disciplinas.csv | cut -d ',' -f 2
	done
	echo $most
	echo "Pressione [enter] para continuar"
	read
	;;
esac
