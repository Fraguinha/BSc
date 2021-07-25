#include <stdio.h>

int normal(int n);
int terminal(int n, int r);

int main() {

    int n, norm, term;

    printf("%s", "Introduza um n: ");
    scanf("%d", &n);

    norm = normal(n);
    term = terminal(n, 0);

    printf("%s%d%s%d\n", "Normal: ", norm, " Terminal: ", term);

    return 0;
}

int normal(int n) {

    if (n == 0) {

        return 0;

    } else {
        
        return (1 + normal((n / 10)));

    }
}

int terminal(int n, int r) {

    if (n == 0) {
        
        return r;

    } else {
        
        return terminal((n / 10), r+1);

    }
}