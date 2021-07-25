#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int id;
    struct NODE *next;

} Node;

Node *push(Node *Q, Node *new)
{
    Node *aux = Q;

    if (Q == NULL)
    {
        Q = new;
        return Q;
    }

    while (Q->next != NULL)
    {
        Q = Q->next;
    }

    Q->next = new;

    return aux;
}

Node *pop(Node **Q)
{
    if (*Q == NULL)
    {
        return *Q;
    }

    Node *aux = *Q;

    *Q = (*Q)->next;

    return aux;
}

Node *divideQueue(Node *F, Node **M, Node **m)
{
    while (F != NULL)
    {
        if (F->id > 20)
        {
            *M = push(*M, pop(&F));
        }
        else
        {
            *m = push(*m, pop(&F));
        }
    }

    return F;
}

Node *joinQueue(Node **A, Node **B)
{
    Node *Q;

    while (*A != NULL && *B != NULL)
    {
        Q = push(Q, pop(A));
        Q = push(Q, pop(B));
    }

    while (*A != NULL)
    {
        Q = push(Q, pop(A));
    }

    while (*B != NULL)
    {
        Q = push(Q, pop(B));
    }

    return Q;
}

int main(int argc, char const *argv[])
{

    return 0;
}
