#include <stdio.h>

int normal(int n);
int terminal(int n, int r);

int main() {

    int n, norm, term;

    printf("%s", "Introduza um n: ");
    scanf("%d", &n);

    norm = normal(n);
    term = terminal(n, 1);

    printf("%s%d%s%d\n", "Normal: ", norm, " Terminal: ", term);

    return 0;
}

int normal(int n) {

    if (n == 0) {

        return 1;

    } else {
        
        return (2 * normal(n-1));

    }
}

int terminal(int n, int r) {

    if (n == 0) {
        
        return r;

    } else {
        
        return terminal(n-1, 2 * r);

    }
}