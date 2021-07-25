#include <stdio.h>

typedef struct NODOAB
{
    int ID;
    int nChave;
    struct NODOAB *L;
    struct NODOAB *R;

} NodoAB;

NodoAB *findNode(NodoAB *A, int ID);
int completa(NodoAB *A);
int profundidade(NodoAB *A);
int cheia(NodoAB *A);
int contarNodos(NodoAB *A);
int maxID(NodoAB *A);
int equilibrada(NodoAB *A);
NodoAB *findNode_NaoChave(NodoAB *A, int x); // O x não é o id, a árvore está ordenada por IDs
int max_NaoChave(NodoAB *A);                 // Vamos avaliar o max de um parametro que não o ID

main(int argc, char const *argv[])
{
    return 0;
}

NodoAB *findNode(NodoAB *A, int ID)
{
    if (A == NULL || A->ID == ID)
    {
        return A;
    }

    if (ID > A->ID)
    {
        return findNode(A->R, ID);
    }
    else
    {
        return findNode(A->L, ID);
    }
}

int cheia(NodoAB *A)
{
    if (A == NULL)
    {
        return 1;
    }

    if (A->R == NULL && A->L == NULL)
        return 1;
    else if (A->R == NULL || A->L == NULL)
        return 0;
    else
        return cheia(A->L) * cheia(A->R);
}

int maxID(NodoAB *A)
{
    if (A == NULL)
    {
        return -1; //nao há máximo
    }

    if (A->R != NULL)
    {
        return maxID(A->R);
    }

    return A->ID;
}

int contarNodos(NodoAB *A)
{
    if (A == NULL)
        return 0;

    return 1 + contarNodos(A->R) + contarNodos(A->L);
}
int equilibrada(NodoAB *A)
{
    int dif;
    if (A == NULL)
        return 1;

    dif = contarNodos(A->R) - contarNodos(A->L);
    if (dif > 1 || dif < -1)
        return 0;

    return equilibrada(A->R) * equilibrada(A->L);
}

NodoAB *findNode_NaoChave(NodoAB *A, int x)
{
    NodoAB *R, *L;
    if (A == NULL || A->nChave == x)
        return A;

    R = findNode_NaoChave(A->R, x);

    return (R == NULL ? findNode_NaoChave(A->L, x) : R);
}

int max_NaoChave(NodoAB *A)
{
    if (A == NULL)
    {
        return -1;
    }

    return max3int(A->nChave, max_NaoChave(A->R), max_NaoChave(A->L));
}

int max3int(int a, int b, int c)
{
    return (a > b ? (a > c ? a : c) : (b > c ? b : c));
}

int completa(NodoAB *A) //ACABAR
{
    if (A == NULL || !equilibrada(A))
        return 0;

    if (cheia(A))
        return 1;

    return 0;
}

int profundidade(NodoAB *A)
{
    int R, L;
    if (A == NULL)
    {
        return 0;
    }

    R = profundidade(A->R);
    L = profundidade(A->L);
    return 1 + (R > L ? R : L);
}