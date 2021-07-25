#include <stdio.h>
#include <stdlib.h>

#define size 80

void main(int argc, char *argv[]) 
{

	if (argc != 3) {
		
		printf("usage: %s [file1] [file2]\n", argv[0]);  
		exit(1);

	} else {
		
		FILE *file;
		FILE *copy;

		char line[size];

		file = fopen(argv[1], "r");

		if (file == NULL) {
			
			printf("Error opening file");
			exit(2);
		}

		copy = fopen(argv[2], "w");
		
		if (copy == NULL) {
			
			printf("Error opening file");
			exit(2);
		}

		while(fgets(line, sizeof line, file)) {
			
		    fprintf(copy, "%s", line);
		}

		fclose(file);
		fclose(copy);
	}

        return 0;
}
