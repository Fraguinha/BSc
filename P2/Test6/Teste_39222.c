
//  PROGRAMA��O II - TESTE PR�TICO 6
//
//  Identifica��o do estudante
//      N�mero:
//      Nome:

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int *LerVector(int *N, char *fich)
{
    int *V, num, k;
    FILE *f;

    f = fopen(fich, "r");
    if (f == NULL)
        return NULL;
    V = (int *)malloc(0 * sizeof(int));
    if (V == NULL)
        return NULL;
    *N = 0;
    while (fscanf(f, "%d", &num) == 1)
    {
        if (num > 0)
        {
            *N = *N + 1;
            V = (int *)realloc(V, (*N) * sizeof(int));
            if (V == NULL)
                return NULL;

            V[*N - 1] = num;
        }
    }
    fclose(f);
    return V;
}

void EscreverVetor(int V[], int tam)
{
    int k;
    for (k = 0; k < tam; k++)
        printf("%d ", V[k]);
    printf("\n");
}

int recursiva(int *v, int n, int k, int r)
{
    // not making the same dumb mistake again ._. plz no 75
    if (v[n - 1] == k)
    {
        r += 1;
    }

    if (n == 1)
    {
        return r;
    }
    else
    {
        recursiva(v, n - 1, k, r);
    }
}

// construir o programa em C - podem usar as funcoes de cima se quiserem
int main()
{
    int *v, n, k, r;

    v = LerVector(&n, "Inteiros.txt");

    EscreverVetor(v, n);

    printf("Introduza um valor inteiro k: ");
    scanf("%d", &k);

    r = recursiva(v, n, k, 0);

    printf("Resultado [%d]: aparece %d vezes\n", k, r);

    return 1;
}
