#include<stdio.h>

int maiorDeTres(int i, int j, int k) {

    if ((i > j) && (i > k)){

        return i;

    }

    if ((j > i) && (j > k)) {

        return j;

    }

    if ((k > i) && (k > j)) {

        return k;

    }
}

int main () 
{
    
    int a, b, c, ans;

    printf("Numero 1: ");
    scanf("%d",&a);
    printf("Numero 2: ");
    scanf("%d",&b);
    printf("Numero 3: ");
    scanf("%d",&c);

    ans = maiorDeTres(a, b, c);
    
    printf("O maior e: %d\n",ans);

    return 0;
}
