#include <stdio.h>

void escreveCaracter (char a, int i) {
    for (int j=0; j < i; j++) {
        printf("%c",a);
    }
}

void triangulo1 (int i) {
    for (int j=1; j <= i; j++) {
        escreveCaracter('T',j);
        printf("\n");
    }
}

void triangulo2 (int i) {
    for (int j=i; j > 0; j--) {
        escreveCaracter('T',j);
        printf("\n");
    }
}

int main() 
{
    
    int n;

    printf("Numero: ");
    scanf("%d",&n);
    
    triangulo1(n);
    printf("\n");
    triangulo2(n); 
    return 0;
}
