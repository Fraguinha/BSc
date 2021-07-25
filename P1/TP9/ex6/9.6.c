#include <stdio.h>
#include <stdlib.h>

#define size 80

void main(int argc, char *argv[]) 
{

    if (argc != 4) {

        printf("usage: %s [file1] [file2] [file3]\n", argv[0]);  
        exit(1);

    } else {

        FILE *fin1, *fin2, *fout;

        char line[size];

        fin1 = fopen(argv[1], "r");
        fin2 = fopen(argv[2], "r");
        fout = fopen(argv[3], "w");

        if (fin1 == NULL || fin2 == NULL || fout == NULL) {

            printf("Error opening file\n");
            exit(2);
        }

        while (fgets(line, sizeof line, fin1)) {
            
            fprintf(fout, "%s", line);
        }

        while (fgets(line, sizeof line, fin2)) {
            
            fprintf(fout, "%s", line);
        }

        fclose(fin1);
        fclose(fin2);
        fclose(fout);	
    }

    return 0;
}
