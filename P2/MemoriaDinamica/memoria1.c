#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    
    float f;

    float *v1;
    float *v2;

    printf("%s\n", "Indique o tamanho do vector: ");
    scanf("%d", &n);

    v1 = (float *) malloc(n * sizeof(float));
    v2 = (float *) calloc(n, sizeof(float));

    printf("%s\n", "Introduza os numeros no vector: ");

    for (int i=0; i<n; ++i) {

        scanf("%f", &f);

        v1[i] = f;
        v2[i] = f;

    }

    v1 = (float *) realloc(v1, (n/2) * sizeof(float));
    v2 = (float *) realloc(v2, (n/2) * sizeof(float));

    for (int j=0; j<(n/2); ++j) {

        printf("v1 = %f v2 = %f\n", v1[j], v2[j]);

    }

    free(v1);
    free(v2);

    return 0;

}