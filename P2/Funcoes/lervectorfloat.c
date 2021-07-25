#include <stdio.h>
#include <stdlib.h>

float *LerVector(const char *fich, int *N);

float *LerVector (const char *fich, int *N) {
    
    FILE *f = fopen(fich, "r");

    if (f == NULL) {
        
        return NULL;

    }

    float *V = (float *) malloc(sizeof(float));

    if (V == NULL) {
        
        return NULL;

    }
    
    *N = 0;
    
    while (fscanf(f, "%f\n", &V[*N]) != EOF) {
        
        V = (float *) realloc(V, (++(*N) + 1) * sizeof(float));

        if (V == NULL) {
        
            return NULL;

        }

    }

    V = (float *) realloc(V, *N * sizeof(float));

    fclose(f);
    
    return V;

}