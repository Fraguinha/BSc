#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fin, *fout;

    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    int *v = (int *) malloc(sizeof(int));

    int i=0;

    while(fscanf(fin, "%d\n", &v[i]) != EOF) { 

        v = (int *) realloc(v, (++i + 1) * sizeof(int));

    }

    v = (int *) realloc(v, i * sizeof(int));

    for (int j=0; j<i; ++j) {

        printf("%d\n", v[j]);
        fprintf(fout, "%d\n", v[j]);

    }

    free(v);

    fclose(fin);
    fclose(fout);

    return 0;

}