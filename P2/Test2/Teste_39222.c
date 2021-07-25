
//  PROGRAMA��O II - TESTE PR�TICO 2
//
//  Identifica��o do estudante
//      N�mero:
//      Nome:


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// construir o programa em C
int main() {

  FILE *fin, *fout;

  fin = fopen("Reais.txt", "r");
  fout = fopen("Saida39222.txt", "w");

  float num;

  int i=0;
  int tam=1;

  float *X = malloc(sizeof(float));

  while(fscanf(fin, "%f", &num) != EOF) {

    X[i] = num;
    i++;

    X = realloc(X, ++tam * sizeof(float));

  }

  for(int j=tam-1; j>=0; j--) {
    X[j+1] = X[j];
  } 

  float soma = 0;

  for (int k=1; k<tam; k++) {

    if (X[k] > 0) {
      soma += X[k];
    }

  }

  X[0] = soma;

  for (int l=0; l<tam; l++) {

    fprintf(fout, "%f\n", X[l]);

  }

  return 1;

}
