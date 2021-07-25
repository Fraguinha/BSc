#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int id;
    struct _node *next;

} Node;

typedef struct _nodebt
{
    int id;
    Node *node;
    struct _nodebt *left;
    struct _nodebt *right;

} NodeBT;

int totalNotIndexed(Node *L, NodeBT *T)
{
    int count = 0;
    while (L != NULL)
    {
        if (findNodeBT(T, L) == NULL)
            count++;
    }
    return count;
}

int checkSubTree(NodeBT *A, NodeBT *B)
{
    if (B == NULL)
        return 1;
    if (A == NULL || A != NULL && A->id != B->id)
        return 0;
    else
        return checkSubTree(A->left, B->left) && checkSubTree(A->right, B->right);
}

int SubTree(NodeBT *A, NodeBT *B)
{
    NodeBT *aux = findNodeBT(A, B->id);
    return checkSubTree(aux, B);
}

NodeBT *BalanceVeryUnbalanced(NodeBT *T)
{
    NodeBT *m;
    if (T == NULL)
        return T;

    m = findMedian(T);
    m = removeTree(&T, m);

    while (T != NULL)
    {
        m = insertTree(m, removeTree(&T, T));
    }

    m->left = BalanceVeryUnbalanced(m->left);
    m->right = BalanceVeryUnbalanced(m->right);

    return m;
}