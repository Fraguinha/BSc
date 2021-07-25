#include <stdio.h>
#include <stdlib.h>

#define size 80

void main(int argc, char *argv[]) 
{

    if (argc != 3) {

        printf("usage: %s -n [file]\n", argv[0]);  
        exit(1);

    } else {

        FILE *file;

        char line[size];

        char ch;		

        int n, lines, cont;

        file = fopen(argv[2], "r");

        if (file == NULL) {

            printf("Error opening file\n");
            exit(2);
        }

        sscanf(argv[1], "%c%d", &ch, &n);

        while (fgets(line, sizeof line, file)) {

            lines++;
        }

        rewind(file);

        cont=0;

        while(fgets(line, sizeof line, file)) {

            if (cont >= (lines - n)) {

                printf("%s", line);
            }

            cont++;			
        }	

        fclose(file);
    }

    return 0;
}
