#!/bin/bash

sum=0
for i in $(seq 1901 2000); do 
	o=$(cal $i | grep -o "1  2  3  4  5  6  7" | wc -l);
	sum=$(($sum+$o)); 
done
echo $sum


for i in `seq 1901 2000`; do for j in `seq 1 12`; do cal $j $i | grep '^ 1'; done; done | wc -l
