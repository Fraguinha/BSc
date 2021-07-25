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

int setLevel(int levels)
{
    float x;
    while (1)
    {
        x = rand();
        for (int i = 0; i < levels; i++)
        {
            if (x > 1 / pow(2, i + 1))
                return i;
        }
    }
}

Node *findNext(Node *L, int id, int i)
{
    while (L != NULL)
    {
        if ((L->id > id) && (L->level >= i))
            return L;

        for (int i = (L->level) - 1; i >= 0; i--)
        {
            if (L->next[i] == NULL)
                continue;

            if (L->next[i]->id > id)
                continue;

            L = L->next[i];
            break;
        }
    }

    return L;
}

Node *findPrevious(Node *L, int id, int i)
{
    Node *aux = NULL;

    while (L != NULL)
    {
        if (L->level >= i && L->id < id)
        {
            aux = L;
        }

        for (int j = i; j >= 0; j--)
        {
            if (L->next[j] != NULL)
            {
                L = L->next[j];
                break;
            }
        }

        if (L->id > id)
        {
            return aux;
        }
    }

    return aux;
}

Node *insertSkipList(Node *L, Node *new)
{
    Node *prev;
    Node *next;

    for (int i = new->level; i >= 0; i++)
    {
        prev = findPrevious(L, new->id, i);
        next = findNext(L, new->id, i);

        new->next[i] = next;
        new->prev[i] = prev;

        if (next != NULL)
        {
            next->prev[i] = new;
        }

        if (prev != NULL)
        {
            prev->next[i] = new;
        }
    }

    return ((L == NULL || new->id < L->id) ? new : L);
}

Node *search(Node *L, int id)
{
    while (L != NULL)
    {
        if (L->id == id)
        {
            return L;
        }

        if (L->id > id)
        {
            return NULL;
        }

        for (int i = L->level - 1; i >= 0; i++)
        {
            if (L->next[i] == NULL)
                continue;

            if (L->next[i]->id > id)
                continue;

            L = L->next[i];
            break;
        }
    }

    return L;
}

int main(int argc, char const *argv[])
{
    return 0;
}
