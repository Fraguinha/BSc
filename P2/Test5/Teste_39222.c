//
//  PROGRAMA��O II - TESTE PR�TICO 5 - 6
//
//  Identifica��o do estudante
//      N�mero:
//      Nome:

#include <stdio.h>
#include "stdlib.h"

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
        *N = *N + 1;
        V = (int *)realloc(V, (*N) * sizeof(int));
        if (V == NULL)
            return NULL;
        V[*N - 1] = num;
    }
    fclose(f);
    return V;
}

void EscreverVetor(int V[], int tam)
{
    int k;
    for (k = 0; k < tam; k++)
        printf("%4d", V[k]);
    printf("\n");
}

// Sele��o - Ordena por ordem crescente
void Ordenar_Selecao(int V[], int N)
{
    int k, kk, pos_menor, aux;
    for (k = 0; k < N - 1; k++)
    {
        pos_menor = k;
        for (kk = k + 1; kk < N; kk++)
            if (V[kk] < V[pos_menor])
                pos_menor = kk;
        if (pos_menor != k)
        {
            aux = V[k];
            V[k] = V[pos_menor];
            V[pos_menor] = aux;
        }
    }
}

// Bubblesort - ordena por ordem decrescente
void Ordenar_Borbulhagem(int V[], int N)
{
    int k, kk, fim, aux;
    fim = N - 1;
    do
    {
        kk = 0;
        for (k = 0; k < fim; k++)
            if (V[k] < V[k + 1])
            {
                aux = V[k];
                V[k] = V[k + 1];
                V[k + 1] = aux;
                kk = k;
            }
        fim = kk;
    } while (kk != 0);
}

// Pesquisa o inteiro Elem no vetor V com N elementos;
//    devolve um dos seus �ndices, se existir, ou -1 se n�o existir
int PesquisaSequencial(int Elem, int V[], int N)
{
    int k = 0;
    while (k < N && V[k] < Elem)
        k = k + 1;
    if (k < N && Elem == V[k])
        return k;
    else
        return -1;
}

// Pesquisa o inteiro Elem no vetor V com N elementos;
//    devolve um dos seus �ndices, se existir, ou -1 se n�o existir
int PesquisaBinaria(int Elem, int V[], int N)
{
    int inicio, fim, meio, k;
    inicio = 0;
    fim = N - 1;
    k = -1;
    while (inicio <= fim && k == -1)
    {
        meio = (inicio + fim) / 2;
        if (Elem == V[meio])
            k = meio;
        else if (Elem < V[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    return k;
}

int main()
{
    int *v, n, k, f, max;

    v = LerVector(&n, "InteirosComRepetidos.txt");

    EscreverVetor(v, n);

    printf("Introduza um valor inteiro k: ");
    scanf("%d", &k);

    Ordenar_Selecao(v, n);

    EscreverVetor(v, n);

    f = PesquisaBinaria(k, v, n);

    if (f == -1)
    {
        printf("Nao existe %d no vector\n", k);
    }
    else
    {
        max = -1;

        for (int i = 0; i < n; i++)
        {
            if (v[i] > max && v[i] < k)
            {
                max = v[i];
            }
        }

        if (max == -1)
        {
            printf("Nao ha elemento < %d\n", k);
        }
        else
        {
            printf("Resultado: %d\n", max);
        }
    }

    return 0;
}
