#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;

} Node;

int countNodes(Node *L);

Node *insertFirst(Node *L, Node *new);
Node *insertLast(Node *L, Node *new);
Node *removeFirst(Node *L);
Node *removeLast(Node *L);
Node *clearList(Node *L);

int main(int argc, char const *argv[])
{
    Node *P, *R, *start = NULL;
    int num;

    P = malloc(sizeof(Node));
    P->data = 1245;
    P->next = NULL;

    R = malloc(sizeof(Node));
    R->data = 2323;
    R->next = NULL;

    start = insertLast(start, P);
    start = insertLast(start, R);

    num = countNodes(start);
    printf("%d\n", num);

    start = removeFirst(start);

    num = countNodes(start);
    printf("%d\n", num);

    start = removeLast(start);

    num = countNodes(start);
    printf("%d\n", num);

    start = clearList(start);

    num = countNodes(start);
    printf("%d\n", num);

    return 0;
}

int countNodes(Node *L)
{
    int count = 0;

    while (L != NULL)
    {
        count++;
        L = L->next;
    }

    return count;
}

Node *insertFirst(Node *L, Node *new)
{
    new->next = L;

    return new;
}

Node *insertLast(Node *L, Node *new)
{
    Node *Aux = L;

    if (L == NULL)
    {
        L = new;
        return L;
    }

    while (L->next != NULL)
    {
        L = L->next;
    }

    L->next = new;

    return Aux;
}

Node *removeFirst(Node *L)
{
    Node *aux = L;

    if (L == NULL)
    {
        return L;
    }

    L = L->next;

    free(aux);

    return L;
}

Node *removeLast(Node *L)
{
    if (L == NULL)
    {
        return L;
    }

    Node *aux = L, *B = L;

    while (L->next != NULL)
    {
        B = L;
        L = L->next;
    }

    free(L);
    B->next = NULL;

    return (aux == B ? NULL : aux);
}

Node *clearList(Node *L)
{
    while (L != NULL)
    {
        L = removeFirst(L);
    }

    return (L);
}
