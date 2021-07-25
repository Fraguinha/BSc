#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 80

void main(int argc, char *argv[]) 
{

    if (argc != 3) {

        printf("usage: %s [file1] [file2]\n", argv[0]);
        exit(1);

    } else {
        
        FILE *file1, *file2;

        char f1[size][size];
        char f2[size][size];

        int cont;

        file1 = fopen(argv[1], "r");
        file2 = fopen(argv[2], "r");

        if (file1 == NULL || file2 == NULL) {
            
            printf("Error opening file\n");
            exit(2);
        }

        cont = 0;

        while (fgets(f1[cont], sizeof f1, file1)) {
            
            cont++;
        }
        
        cont = 0;

        while (fgets(f2[cont], sizeof f2, file2)) {

            cont++;
        }

        fclose(file1);
        fclose(file2);

        for (int i = 0; i < cont; i++) {
            
            if (!strcmp(f1[i],f2[i])) {

                printf("%s", f1[i]);
            }
        }
    }

    return 0;
}
