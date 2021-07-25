
//  PROGRAMA��O II - TESTE PR�TICO 4
//
//  Identifica��o do estudante
//      N�mero:
//      Nome:
    

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// construcao de um vetor a partir dos dados de um ficheiro - a usar se quiserem
int *LerVector (int *N, char *fich){
    int *V, num, k;
    FILE *f;
    
    f = fopen(fich, "r");
    if (f == NULL)
      return NULL;
    V = (int *) malloc(0*sizeof(int));
    if (V == NULL)
      return NULL;
    *N = 0;
    while (fscanf(f, "%d", &num) == 1){
    	*N = *N + 1;
        V = (int *) realloc(V, (*N) * sizeof(int));
        if (V == NULL)
            return NULL;
        V[*N-1] = num;
    }
    fclose(f);
    return V;
}

// escrita no monitor de um vetor de inteiros com tam elementos - a usar se quiserem
void EscreverVetor(int V[], int tam){
   int k;
   for (k = 0; k < tam; k++)
      printf("%4d", V[k]);
   printf("\n");   
}

void order(int v[], int n) {

    int prox = 0, ant =0, k=0;

    while(k < n-1) {

      if(v[k] > v[k+1]) {
        ant = k;
        prox = k+1;
      }

      while(v[ant]>v[prox]) {

        int a = v[ant];
        v[ant] = v[prox];
        v[prox] = a;

        if(ant > 0) {
          ant = ant - 1;
        }

        if(prox > 0) {
          prox = prox-1;
        }

      }

      k = k+1;

    }

}


// construir o programa em C - podem usar as funcoes de cima se quiserem
int main(){

  int n;
  printf("N: ");
  scanf("%d", &n);

  int v[n];

  for (int i=0; i<n; i++) {

    scanf("%d", &v[i]);

  }

  for (int i=0; i<n; i++) {

    printf("%d\n", v[i]);

  }

  order(v, n);

  for (int i=0; i<n; i++) {

    printf("%d\n", v[i]);

  }
  
  return 1;
}
