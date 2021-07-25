#include <stdio.h>
#include <stdlib.h>

float normal(float *v, int n, int i);
float terminal(float *v, int n, int i, float r);

int main() {

    FILE *fp = fopen("ReaisPositivos.txt", "r");

    float *v = malloc(sizeof(float));

    int n=0;

    while(fscanf(fp, "%f", &v[n]) != EOF) {

        v = realloc(v, (++n + 1) * sizeof(float));

    }

    v = realloc(v, n);

    float norm = normal(v, n, n);
    float term = terminal(v, n, n, 0);

    printf("%s%f%s%f\n", "Normal: ", norm, " Terminal: ", term);

    return 0;

}

float normal(float *v, int n, int i) {

    if (i == 1) {

        return v[i-1]/n;

    } else {

        return (v[i-1]/n + normal(v, n, i-1));

    }

}

float terminal(float *v, int n, int i, float r) {

    if (i == 0) {

        return r;

    } else {

        return terminal(v, n, i-1, r + v[i-1]/n);

    }

}