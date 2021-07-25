#include <stdio.h>
#include <stdlib.h>

float normal(float *v, int n);
float terminal(float *v, int n, float r);

int main() {

    FILE *fp = fopen("ReaisPositivos.txt", "r");

    float *v = malloc(sizeof(float));

    int n=0;

    while(fscanf(fp, "%f", &v[n]) != EOF) {

        v = realloc(v, (++n + 1) * sizeof(float));

    }

    v = realloc(v, n);

    float norm = normal(v, n);
    float term = terminal(v, n, 0);

    printf("%s%f%s%f\n", "Normal: ", norm, " Terminal: ", term);

    return 0;

}

float normal(float *v, int n) {

    if (n == 0) {

        return v[n];

    } else {

        return v[n] + normal(v, n-1);

    }

}

float terminal(float *v, int n, float r) {

    r += v[n];

    if (n == 0) {

        return r;

    } else {

        return terminal(v, n-1, r);

    }

}