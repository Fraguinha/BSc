#include<stdio.h>

void escreveCaracter (char a, int i) {

    for (int j=0; j < i; j++) {
        printf("%c",a);
    }
}

void escreveNumerosAsc (int i, int j) {

    for (int k=i; k <= j; k++) {

        printf("%d    ",k);

    }
}

void escreveNumerosDesc (int i, int j) {

    for (int k=i; k >= j; k--) {

        printf("%d    ",k);

    }
}

int main() 
{

    int n;

    printf("Numero: ");
    scanf("%d",&n);
    
    int space = 0;
    int cont=n;
    
    for (int i=0; i < n; i++) {

        for (int j=0; j < space; j++) {

            escreveCaracter(' ',5);

        }
        
        escreveNumerosAsc(1,cont);
        escreveNumerosDesc(cont-1,1);

        printf("\n");

        space++;
        cont--;
    }   
    return 0;
}
