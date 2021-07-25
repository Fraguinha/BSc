#include <stdio.h>
#include <stdlib.h>

int *LerVector(const char *fich, int *N);

void countsort_dec(int v[], int n);
void countsort_asc(int v[], int n);

int main() {

    int *v, n;

    v = LerVector("Inteiros.txt", &n);

    countsort_dec(v, n);

    for(int i=0; i<n; i++) {
        
        printf("%d\n", v[i]);

    }

    return 0;

}

void countsort_dec(int v[], int n) {

    int aux[n], k;
    
    for (int i=0; i<n; i++) {
        
        k = 0;
        
        for (int j=0; j<n; j++) {
            
            if(v[j] > v[i]) {
                
                k++;

            }
        }
        
        aux[k] = v[i];

    }

    for (int i=0; i<n; i++) {
        
        v[i] = aux[i];
        
    }

}

void countsort_asc(int v[], int n) {

    int aux[n], k;
    
    for (int i=0; i<n; i++) {
        
        k = 0;
        
        for (int j=0; j<n; j++) {
            
            if(v[j] < v[i]) {

                k++;

            }
        }
        
        aux[k] = v[i];

    }

    for (int i=0; i<n; i++) {
        
        v[i] = aux[i];

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