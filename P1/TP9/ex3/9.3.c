#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 80

void main(int argc, char *argv[]) 
{
    
    if (argc !=3) {

        printf("usage: %s [pattern] [file]\n", argv[0]);
        exit(1);

    } else {
        
        FILE *file;

        char line[size];

        char *sp;

        file = fopen(argv[2], "r");

        if (file == NULL) {

            printf("Error opening file\n");
            exit(2);
        }

        while (fgets(line, sizeof line, file)) {
            
            sp = strstr(line, argv[1]);

            if (sp != NULL) {
                
                printf("%s", line);
            }
        }

        fclose(file);
    }

    return 0;
}
