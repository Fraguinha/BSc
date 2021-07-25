#include<stdio.h>
#include<math.h>

int main() 
{

    double x,y,ans;
    
    printf("x: ");
    scanf("%lf",&x);
    printf("y: ");
    scanf("%lf",&y);

    ans = 2 * sin(x) + cos(y) - tan(x+y);

    printf("Ans: %lf\n",ans);

    return 0;
}
