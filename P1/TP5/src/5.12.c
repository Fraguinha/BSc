#include <stdio.h>

void escreveCaracter (char a, int i) {
    for (int j=0; j < i; j++) {
        printf("%c",a);
    }
}

void triangulo1 (int i) {
    int k=i-1;
    for (int j=1; j <= i; j++) {
        escreveCaracter(' ',k);
        k--;
        escreveCaracter('T',j);
        printf("\n");
    }
}

void triangulo2 (int i) {
    int k=0;
    for (int j=i; j > 0; j--) {
        escreveCaracter(' ',k);
        k++;
        escreveCaracter('T',j);
        printf("\n");
    }
}

int main() 
{
    
    int n;

    printf("Numero: ");
    scanf("%d",&n);
    
    triangulo2(n);
    printf("\n");
    triangulo1(n); 
    return 0;
}
