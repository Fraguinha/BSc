#include <stdio.h>
#include <stdlib.h>

#define size 80

void main(int argc, char *argv[]) 
{
    
    if (argc != 2) {

        printf("usage: %s [file]\n", argv[0]);
        exit(1);

    } else {
        
        FILE *file;

        char line[size];

        int cont=0;

        file = fopen(argv[1], "r");

        if (file == NULL) {

            printf("Error opening file\n");
            exit(2);
        }

        while (fgets(line, sizeof line, file)) {

            printf("%s", line);
            cont++;

            if (cont % 20 == 0) {

                getchar();
            }
        }

        fclose(file);
    }

    return 0;
}
