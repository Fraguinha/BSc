#include <stdio.h>

int normal(int n);
int terminal(int n, int r1, int r2);

int main() {

    int n, norm, term;

    printf("%s", "Introduza um n: ");
    scanf("%d", &n);

    norm = normal(n);
    term = terminal(n, 0, 1);

    printf("%s%d%s%d\n", "Normal: ", norm, " Terminal: ", term);

    return 0;
}

int normal(int n) {

    if (n == 0) {

        return 0;

    }
    
    if (n == 1) {

        return 1;

    }
        
    return (normal(n-2) + normal(n-1));

}

int terminal(int n, int r1, int r2) {

    if (n == 0) {

        return r1;

    }

    if (n == 1) {

        return r2;

    }
        
    return terminal(n-1, r2, r1 + r2);
        
}