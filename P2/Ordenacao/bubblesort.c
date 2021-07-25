#include <stdio.h>
#include <stdlib.h>

int *LerVector(const char *fich, int *N);

void bubblesort_dec(int v[], int n);
void bubblesort_asc(int v[], int n);

int main() {

    int *v, n;
    
    v = LerVector("Inteiros.txt", &n);

    bubblesort_dec(v, n);

    for(int i=0; i<n; i++) {
        
        printf("%d\n", v[i]);

    }

    return 0;

}

void bubblesort_dec(int v[], int n) {

    int ultima_troca, fim = n-1, aux;

    do {

        ultima_troca = 0;

        for (int i=0; i<fim; i++) {

            if(v[i] < v[i+1]) {

                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;

                ultima_troca = i;

            }

        }

        fim = ultima_troca;

    } while (ultima_troca != 0);

}

void bubblesort_asc(int v[], int n) {

    int ultima_troca, fim = n-1, aux;

    do {

        ultima_troca = 0;

        for (int i=0; i<fim; i++) {

            if(v[i] > v[i+1]) {

                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;

                ultima_troca = i;

            }

        }

        fim = ultima_troca;

    } while (ultima_troca != 0);

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