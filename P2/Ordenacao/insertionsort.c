#include <stdio.h>
#include <stdlib.h>

int *LerVector(const char *fich, int *N);

void insertionsort_dec(int v[], int n);
void insertionsort_asc(int v[], int n);

int main() {

    int *v, n;
    
    v = LerVector("Inteiros.txt", &n);

    insertionsort_dec(v, n);

    for(int i=0; i<n; i++) {
        
        printf("%d\n", v[i]);

    }

    return 0;

}

void insertionsort_dec(int v[], int n) {

    int j, aux;
    
    for (int i=1; i<n; i++) {
        
        aux = v[i];

        for (j=i-1; j>=0 && v[j] < aux; j--) {

            v[j+1] = v[j];

        }

        v[j+1] = aux;

    }

}

void insertionsort_asc(int v[], int n) {

    int j, aux;

    for (int i=1; i<n; i++) {
        
        aux = v[i];

        for (j=i-1; j>=0 && v[j] > aux; j--) {

            v[j+1] = v[j];

        }

        v[j+1] = aux;

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