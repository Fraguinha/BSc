#include <stdio.h>
#include <stdlib.h>

float normal(float *v, int n, float x);
float terminal(float *v, int n, float x, float r);

int main() {

    int n;

    float x;

    printf("Introduza o grau: ");
    scanf("%d", &n);

    float *v = (float *) malloc((n+1) * sizeof(float));

    for(int i=n; i>=0; --i) {

        printf("P[%d] = ", i);
        scanf("%f", &v[i]);

    }

    printf("Introduza o valor de x: ");
    scanf("%f", &x);

    float norm = normal(v, n, x);
    float term = terminal(v, n, x, v[n]);

    printf("%s%f%s%f\n", "Normal: ", norm, " Terminal: ", term);

    return 0;

}

float normal(float *v, int n, float x) {

    if (n == 0) {

        return x * v[n];

    } else {

        return (v[n-1] + normal(v, n-1, x));

    }

}

float terminal(float *v, int n, float x, float r) {

    if (n == 0) {

        return r;

    } else {

        return terminal(v, n-1, x, v[n-1] + x * r);

    }
}