#include <stdio.h>
#include <stdlib.h>

int *LerVector(const char *fich, int *N);

void mergesort_dec(int v[], int inicio, int fim);
void mergesort_asc(int v[], int inicio, int fim);
void merge_dec(int v[], int inicio, int meio, int fim);
void merge_asc(int v[], int inicio, int meio, int fim);

int main() {

    int *v, n;

    v = LerVector("Inteiros.txt", &n);

    mergesort_dec(v, 0, n);

    for(int i=0; i<n; i++) {
        
        printf("%d\n", v[i]);

    }

    return 0;

}

void mergesort_dec(int v[], int inicio, int fim) {

    int  meio;
    
    if (inicio < fim) {
        
        meio = (inicio + fim) / 2;
        mergesort_dec(v, inicio, meio);
        mergesort_dec(v, meio+1, fim);
        merge_dec(v, inicio, meio, fim);
    
    }
    
}

void mergesort_asc(int v[], int inicio, int fim) {

    int  meio;
    
    if (inicio < fim) {
        
        meio = (inicio + fim) / 2;
        mergesort_asc(v, inicio, meio);
        mergesort_asc(v, meio+1, fim);
        merge_asc(v, inicio, meio, fim);
    
    }

}

void merge_dec(int v[], int inicio, int meio, int fim) {

    int  esq = inicio, dir = meio+1, k = 0, aux[fim-inicio+1];
    
    while ((esq <= meio) && (dir <= fim)) {
        
        if (v[esq] > v[dir]) {
            
            aux[k] = v[esq]; 
            esq++; 

        } else {
            
            aux[k] = v[dir]; 
            dir++;
        }
    
        k++;

    }
    
    if (esq > meio) {
    
        for (int i = dir; i <= fim; i++) { 
    
            aux[k] = v[i]; 
            k++;

        }

    } else {
        
        for (int i = esq; i <= meio; i++) { 
            
            aux[k] = v[i];
            k++; 
        }
    
    }
    
    for (int i = 0; i < k; i++) {
        
        v[inicio+i] = aux[i];

    }

}

void merge_asc(int v[], int inicio, int meio, int fim) {

    int  esq = inicio, dir = meio+1, k = 0, aux[fim-inicio+1];
    
    while ((esq <= meio) && (dir <= fim)) {
        
        if (v[esq] < v[dir]) {
            
            aux[k] = v[esq]; 
            esq++; 

        } else {
            
            aux[k] = v[dir]; 
            dir++;
        }
    
        k++;

    }
    
    if (esq > meio) {
    
        for (int i = dir; i <= fim; i++) { 
    
            aux[k] = v[i]; 
            k++;

        }

    } else {
        
        for (int i = esq; i <= meio; i++) { 
            
            aux[k] = v[i];
            k++;

        }
    
    }
    
    for (int i = 0; i < k; i++) {
        
        v[inicio+i] = aux[i];

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