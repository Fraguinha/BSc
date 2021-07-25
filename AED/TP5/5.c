#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct NODE
{
    int id;
    int level;
    struct NODE *prev[5];
    struct NODE *next[5];

} Node;

typedef struct DIGIT
{
    int num;
    struct DIGIT *prev;
    struct DIGIT *next;
} Digit;

Digit *insertFirst();
Digit *clearList();
Digit *makeNode();

int biggestJump(Node *L)
{
    int max = 0;
    int count;
    int i;

    Node *aux;

    while (L != NULL)
    {
        for (i = L->level - 1; i >= 0; i--)
        {
            if (L->next[i] != NULL)
            {
                aux = L;

                L = L->next[i];

                count = 0;
                while (aux != L->next[i])
                {
                    count++;
                    aux = aux->next[0];
                }

                if (count > max)
                {
                    max = count;
                }

                break;
            }
        }
        if (i < 0)
        {
            return max;
        }
    }

    return max;
}

Digit *add(Digit *A, Digit *B)
{
    Digit *R = NULL;

    int sum, carry = 0;

    while (A != NULL && A->next != NULL)
    {
        A = A->next;
    }

    while (B != NULL && B->next != NULL)
    {
        B = B->next;
    }

    while (A != NULL || B != NULL)
    {
        sum = 0;

        if (A != NULL)
            sum += A->num;

        if (B != NULL)
            sum += B->num;

        R = insertFirst(R, makeNode((sum % 10) + carry));
        carry = sum / 10;

        if (A != NULL)
            A = A->prev;

        if (B != NULL)
            B = B->prev;
    }

    if (carry > 0)
    {
        R = insertFirst(R, makeNode(carry));
    }

    return R;
}

Digit *productAux(Digit *A, int d)
{
    Digit *R = NULL;
    Digit *temp;

    for (int i = 0; i < d; i++)
    {
        temp = R;
        R = add(R, A);
        temp = clearList(temp);
    }

    return R;
}

Digit *product(Digit *A, Digit *B)
{
    Digit *R = NULL, *aux = NULL, *temp = NULL;

    int count = 0;

    while (B != NULL && B->next != NULL)
    {
        B = B->next;
    }

    while (B != NULL)
    {
        aux = productAux(A, B->num);

        for (int i = 0; i < count; i++)
        {
            aux = insertFirst(aux, makeNode(0));
        }

        temp = R;

        R = add(R, aux);

        aux = clearList(aux);
        R = clearList(R);
    }

    return R;
}