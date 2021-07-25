#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);
int normal(int *v, int n);
int terminal(int *v, int n, int r);

int main() {

    FILE *fp = fopen("Inteiros.txt", "r");

    int *v = malloc(sizeof(int));

    int n=0;

    while(fscanf(fp, "%d", &v[n]) != EOF) {

        v = realloc(v, (++n + 1) * sizeof(int));

    }

    v = realloc(v, n);

    int norm = normal(v, n);
    int term = terminal(v, n, v[0]);

    printf("%s%d%s%d\n", "Normal: ", norm, " Terminal: ", term);

    return 0;

}

int max(int a, int b) {

    if (a > b) {
        
        return a;

    }

    return b;

}

int normal(int *v, int n) {

    if (n == 0) {

        return v[n];

    } else {

        return max(v[n], normal(v, n-1));

    }

}

int terminal(int *v, int n, int r) {

    if (v[n] > r) {

        r = v[n];

    }

    if (n == 0) {

        return r;

    } else {

        return terminal(v, n-1, r);

    }

}