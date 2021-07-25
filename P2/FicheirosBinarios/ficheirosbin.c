#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fp;

    fp = fopen("file.bin", "w+b");

    int *v1 = (int *) malloc(10 * sizeof(int));
    int *v2 = (int *) malloc(10 * sizeof(int));

    int i, j;

    for(i=0; i<10; ++i) {

        v1[i] = i + 1;

    }

    for(j=0; j<i; ++j) {

        printf("%d\n", v1[j]);

    }

    fwrite(v1, sizeof(int), 10, fp);

    rewind(fp);

    fread(v2, sizeof(int), 10, fp);

    for(j=0; j<i; ++j) {

        printf("%d\n", v2[j]);

    }

    free(v1);
    free(v2);

    fclose(fp);

    return 0;

}