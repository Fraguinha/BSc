#include <stdio.h>
#include <stdlib.h>

int normal(int *v, int n);
int terminal(int *v, int n, int r);

int main() {

    FILE *fp = fopen("Inteiros.txt", "r");

    int *v = malloc(sizeof(int));

    int n=0;

    while(fscanf(fp, "%f", &v[n]) != EOF) {

        v = realloc(v, (++n + 1) * sizeof(int));

    }

    v = realloc(v, n);

    int norm = normal(v, n);
    int term = terminal(v, n, 0);

    printf("%s%d%s%d\n", "Normal: ", norm, " Terminal: ", term);

    return 0;

}

int normal(int *v, int n) {

    if (n == 1) {
        
        if (v[n-1] > 0) {
            
            return 1;

        } else {

            return 0;

        }

    } else {

        if (v[n-1] > 0) {

            return (1 + normal(v, n-1));

        } else {

            return normal(v, n-1);

        }

    }

}

int terminal(int *v, int n, int r) {

    if (v[n-1] > 0) {

        r += 1;

    }
    
    if (n == 1) {

        return r;

    } else {

        return terminal(v, n-1, r);

    }

}