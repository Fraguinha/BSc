#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int id;
    struct NODE *prev;
    struct NODE *next;

} Node;

Node *insertFirst(Node *L, Node *new)
{
    new->next = L;

    L = new;

    return L;
}

Node *insertLast(Node *L, Node *new)
{
    Node *aux = L;

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

    return aux;
}

int isOrdered(Node *L)
{
    if (L == NULL)
    {
        return 1;
    }

    while (L->next != NULL)
    {
        if (L->id < L->next->id)
        {
            return 0;
        }
        L = L->next;
    }

    return 1;
}

int totalDifferentElements(Node *L)
{
    int diff = 0;
    Node *aux;

    while (L != NULL)
    {
        aux = L->prev;

        while (aux != NULL)
        {
            if (aux == L)
                break;

            aux = aux->prev;
        }

        if (aux == NULL)
            diff++;

        L = L->next;
    }

    return diff;
}

Node *invertList(Node *L)
{
    Node *start = L;
    Node *N;

    while (L != NULL)
    {
        N = L;
        L = L->next;

        if (L != NULL)
        {
            if (L->prev != NULL)
            {
                L->prev->next = NULL;
                L->prev = NULL;
            }
        }

        start = insertFirst(start, N);
    }

    return start;
}

Node *removeRepeat(Node *L)
{
    Node *aux;

    while (L != NULL)
    {
        aux = L->prev;
        while (aux != NULL)
        {
            if (aux->id == L->id)
                break;

            aux = aux->prev;
        }

        if (aux != NULL)
        {
            if (L->next != NULL)
                L->next->prev = L->prev;

            Node *count = L;
            L = L->next;
            free(count);
        }
    }

    return aux;
}

int countOccurences(Node *L, int id)
{
    int count = 0;

    while (L != NULL)
    {
        if (L->id == id)
        {
            count++;
        }
    }

    return count;
}

Node *removeNode(Node *L, Node *r)
{
    if (L == r)
        L = L->next;

    if (r->prev != NULL)
    {
        r->prev->next = r->next;
    }
    if (r->next != NULL)
    {
        r->next->prev = r->prev;
    }

    r->prev = NULL;
    r->next = NULL;

    free(r);

    return L;
}

Node *sortOccurences(Node *L)
{
    Node *start = L;
    Node *aux;
    Node *ans;

    int count;
    int max;
    int id;

    while (L != NULL)
    {
        max = 0;

        while (L != NULL)
        {
            count = countOccurences(L, L->id);

            if (count > max)
            {
                max = count;
                id = L->id;
            }

            L = L->next;
        }

        L = start;

        while (L != NULL)
        {
            if (L->id == id)
            {
                aux = L->next;
                start = removeNode(start, L);
                ans = insertLast(ans, L);
                L = aux;
            }
            else
            {
                L = L->next;
            }
        }

        L = start;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    return 0;
}
