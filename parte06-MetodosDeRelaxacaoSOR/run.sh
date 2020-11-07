#!/bin/bash

echo "Omega,It" >> itvsOmega.csv

for i in $(seq 1.0 0.1 1.9);
do
    ./exec 4 5 $i < entrada.txt
    echo "$i," >> itvsOmega.csv
    cat -n ./saida.csv | tail -n 1 | awk '{print $1}' >> itvsOmega.csv
    rm saida.csv
done

#PLOTING
#python plot.py