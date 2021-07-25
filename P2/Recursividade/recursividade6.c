#include <stdio.h>

int normal(char *str, int i);
int terminal(char *str, int i, int r);

int main() {

    char str[80];
    int norm, term;

    printf("%s", "Introduza uma string: ");
    scanf("%s", str);

    norm = normal(str, 0);
    term = terminal(str, 0, 0);

    printf("%s%d%s%d\n", "Normal: ", norm, " Terminal: ", term);

    return 0;
}

int normal(char *str, int i) {

    if (str[i] == '\0') {

        return 0;

    } else {
        
        return (1 + normal(str, i+1));

    }
}

int terminal(char *str, int i, int r) {

    if (str[i] == '\0') {
        
        return r;

    } else {
        
        return terminal(str, i+1, r+1);

    }
}