#!/bin/bash

#executar caçador.c passando ./exec $i $i como parametros variando 0.2
#a cada iteracao e plotar os graficos ao final

for i in $(seq 0.5 0.2 1.5);
do
    ./exec $i $i > saida.dat
    mv saida.dat saida-$i.dat
done
python plot.py

