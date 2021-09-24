#include <stdio.h>
#include <stdlib.h>

#define TESTMIN 0
#define TESTMAX 8

#define max 4294967295.0 
unsigned s = 88912125;
unsigned 
R = 8932924
;

double sortRandomNumber(unsigned *R){
    *R=*R*s;
    return (*R/max);
}

//Sort int number between minNum and maxNum-1
//call: SortRandomNumberInteger(minNum, maxNum)
int sortRandomNumberInteger(int minNum, int maxNum){

    return (int)( sortRandomNumber(&R)*(maxNum-minNum)+minNum );
}

//Sort double number between minNum and maxNum-(≅0.00001)
//call: SortRandomNumberDouble(minNum, maxNum)
double sortRandomNumberDouble(double minNum, double maxNum){

    return ( sortRandomNumber(&R)*(maxNum-minNum)+minNum );
}


int main(){


    return 0;
}