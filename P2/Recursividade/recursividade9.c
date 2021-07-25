#include <stdio.h>

int normal(int n1, int n2);
int terminal(int n1, int n2);

int main() {

    int n1, n2, norm, term;

    printf("%s\n", "Introduza dois n: ");
    scanf("%d %d", &n1, &n2);

    norm = normal(n1, n2);
    term = terminal(n1, n2);

    printf("%s%d%s%d\n", "Normal: ", norm, " Terminal: ", term);

    return 0;
}

int normal(int n1, int n2) {

    // ???

}


int terminal(int n1, int n2) {

    if (n2 == 0) {

        return n1;

    }
        
    return terminal(n2, n1 % n2);
        
}