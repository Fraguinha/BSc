#include<stdio.h>

int maior (int i, int j) {

    if (i > j) {

        return i;

    } else {

        return j;

    }
}

int main() 
{
    
    int a, b, ans;

    printf("Numero 1: ");
    scanf("%d",&a);
    printf("Numero 2: ");
    scanf("%d",&b);

    ans = maior(a, b);

    printf("O maior e: %d\n",ans);
    return 0;
}
