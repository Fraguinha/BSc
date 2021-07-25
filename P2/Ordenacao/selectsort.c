#include <stdio.h>
#include <stdlib.h>

int *LerVector(const char *fich, int *N);

void selectsort_dec(int v[], int n);
void selectsort_asc(int v[], int n);

int main() {

    int *v, n;

    v = LerVector("Inteiros.txt", &n);

    selectsort_dec(v, n);

    for(int i=0; i<n; i++) {
        
        printf("%d\n", v[i]);

    }

    return 0;

}

void selectsort_dec(int v[], int n) {

    int posicao_maior, aux;

    for (int i=0; i<n-1; i++) {

        posicao_maior = i;

        for (int j=i+1; j<n; j++) {

            if (v[j] > v[posicao_maior]) {

                posicao_maior = j;

            }

        }
        
        if(posicao_maior != i) {

            aux = v[posicao_maior];
            v[posicao_maior] = v[i];
            v[i] = aux;

        }

    }

}

void selectsort_asc(int v[], int n) {

    int posicao_menor, aux;

    for (int i=0; i<n-1; i++) {

        posicao_menor = i;

        for (int j=i+1; j<n; j++) {

            if (v[j] < v[posicao_menor]) {

                posicao_menor = j;

            }

        }
        
        if(posicao_menor != i) {

            aux = v[posicao_menor];
            v[posicao_menor] = v[i];
            v[i] = aux;

        }

    }

}

int *LerVector (const char *fich, int *N) {
    
    FILE *f = fopen(fich, "r");

    if (f == NULL) {
        
        return NULL;

    }

    int *V = (int *) malloc(sizeof(int));

    if (V == NULL) {
        
        return NULL;

    }
    
    *N = 0;
    
    while (fscanf(f, "%d\n", &V[*N]) != EOF) {
        
        V = (int *) realloc(V, (++(*N) + 1) * sizeof(int));

        if (V == NULL) {
        
            return NULL;

        }

    }

    V = (int *) realloc(V, *N * sizeof(int));

    fclose(f);
    
    return V;

}