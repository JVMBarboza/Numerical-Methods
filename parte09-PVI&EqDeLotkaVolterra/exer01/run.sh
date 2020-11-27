#!/bin/bash

#executar caçador.c passando ./exec $i $i como parametros variando 0.2
#a cada iteracao e plotar os graficos ao final

for i in $(seq 0.5 0.2 1.5);
do
    ./exec $i $i > saida.dat
    python plot.py
    mv image.png result-$i.png
    rm saida.dat
    #fazendo tudo em um mesmo saida.dat eu nao me preocupo com qual
    #.dat estou enviando ao python desde que a cada iteracao o antigo
    #é excluido e substituido por um com valores atualizados
done


