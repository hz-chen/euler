#!/bin/bash


largest=0
for i in {999..100}; do
	for j in {999..100}; do
		prod=$(($i * $j))
		dorp=$(echo $prod |rev)

		if ( [ $prod -eq $dorp ] && (( $prod > $largest )) )
		then
			largest=$prod
			echo $largest " found"
		fi

	done
done
echo $largest

