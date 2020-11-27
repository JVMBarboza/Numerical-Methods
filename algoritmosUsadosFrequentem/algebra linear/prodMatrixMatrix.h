#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double **retornarMultplMatriz(double **matrizA, double **matrizB, int m, int n){
  int i,j,k;
  double sum=0, **matrizResult;

  matrizResult = malloc(m*sizeof(double *));
  for(i=0;i<m;i++) matrizResult[i] = malloc(m*sizeof(double *));
  
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){ 
      matrizResult[i][j] = 0.0;
    }
  }

  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      
      for(k=0;k<m;k++){ matrizResult[i][j] = matrizResult[i][j] + matrizA[i][k]*matrizB[k][j]; }
      
      printf("%g ",matrizResult[i][j]);
      sum = 0;
    }
    puts("");
  }

  return matrizResult;
}