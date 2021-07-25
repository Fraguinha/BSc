#include<stdio.h>

int par (int n) {

    if (n % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() 
{
    
    int n, ans;

    printf("Numero: ");
    scanf("%d",&n);

    ans = par(n);

    printf("%d\n",ans);

    return 0;
}
