#include <stdio.h>
#include <stdlib.h>

#define num 10

int main() 
{

    FILE *file;

    float a[num], b[num];

    for (int i = 0; i < num; i++) {

        printf("Num: ");
        scanf("%f",&a[i]);
    }

    file = fopen("bin","w+b");

    if (file == NULL) {

        printf("Error opening file\n");
        exit(1);
    }

    fwrite((const void*)a, sizeof(float), num, file);

    rewind(file);

    fread((void*)b, sizeof(float), num, file);

    for (int i = 0; i < num; i++) {

        printf("%f\n", b[i]);
    }

    fclose(file);

    return 0;
}
