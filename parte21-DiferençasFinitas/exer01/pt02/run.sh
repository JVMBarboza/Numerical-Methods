#!/bin/bash

#executar caçador.c passando ./exec $i $i como parametros variando 0.2
#a cada iteracao e plotar os graficos ao final

for i in 99 999;
do
    ./exec 0 10 $i 400 200 1.0 300 > saida.dat
    mv saida.dat saida-$i.dat
done

