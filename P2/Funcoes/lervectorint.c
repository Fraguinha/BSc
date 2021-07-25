#include <stdio.h>
#include <stdlib.h>

int *LerVector(const char *fich, int *N);

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