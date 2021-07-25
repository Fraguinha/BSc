#include <stdio.h>

int normal(int n, int i);
int terminal();

int main() {

    int n, norm, term;

    printf("%s", "Introduza um n: ");
    scanf("%d", &n);

    norm = normal(n, n-1);
    term = terminal(n, n-1);

    printf("%s%d%s%d\n", "Normal: ", norm, " Terminal: ", term);

    return 0;

}

int normal(int n, int i) {

    if (i == 1) {

        return 1;

    }
    
    if (n % i == 0) {
        
        return 0;

    }

    return terminal(n, i-1);

}

int terminal() {

    // ???

}