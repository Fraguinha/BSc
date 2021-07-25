#include <stdio.h>
#include <stdlib.h>

int *LerVector(const char *fich, int *N);

void quicksort_dec(int v[], int inicio, int fim);
void quicksort_asc(int v[], int inicio, int fim);

int  determinarpivot_dec(int v[], int inicio, int fim);
int  determinarpivot_asc(int v[], int inicio, int fim);
void trocar(int *a, int *b);

int main() {

    int *v, n;

    v = LerVector("Inteiros.txt", &n);

    quicksort_dec(v, 0, n);

    for(int i=0; i<n; i++) {
        
        printf("%d\n", v[i]);

    }

    return 0;

}

void quicksort_dec(int v[], int inicio, int fim) {

    int  pivot;
    
    if (inicio < fim) {
        
        pivot = determinarpivot_dec(v, inicio, fim);
        quicksort_dec(v, inicio, pivot-1);
        quicksort_dec(v, pivot+1, fim);
    
    }

}

void quicksort_asc(int v[], int inicio, int fim) {

    int  pivot;
    
    if (inicio < fim) {
        
        pivot = determinarpivot_asc(v, inicio, fim);
        quicksort_asc(v, inicio, pivot-1);
        quicksort_asc(v, pivot+1, fim);
    
    }    

}

void  trocar(int  *a, int  *b) {
    
    int  aux;
    
    aux = *a;
    *a = *b;
    *b = aux;

}

int  determinarpivot_dec(int  v[],  int  inicio, int  fim) {
    
    int  i, pivot = inicio;
    
    for (i = inicio+1; i <= fim; i++) {
        
        if (v[i] > v[inicio]) {
        
            pivot++;
            trocar(&v[i], &v[pivot]); 
        }

    }
    
    trocar(&v[inicio], &v[pivot]);
    
    return (pivot);

}

int  determinarpivot_asc(int  v[],  int  inicio, int  fim) {
    
    int  i, pivot = inicio;
    
    for (i = inicio+1; i <= fim; i++) {
        
        if (v[i] < v[inicio]) {
        
            pivot++;
            trocar(&v[i], &v[pivot]); 
        }

    }
    
    trocar(&v[inicio], &v[pivot]);
    
    return (pivot);

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