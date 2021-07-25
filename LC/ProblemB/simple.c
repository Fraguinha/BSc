#include <stdlib.h>
#include <stdio.h>

int matrixIsFull(int n, int matrix[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int insideMatrix(int n, int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < n);
}

int positionAvailable(int n, int matrix[n][n], int i, int j)
{
    return (insideMatrix(n, i, j) && matrix[i][j] == 0);
}

int numberPossibleJumps(int n, int matrix[n][n], int i, int j)
{
    int deltaX[8] = {1, 1, 2, 2, -1, -1, -2, -2};
    int deltaY[8] = {2, -2, 1, -1, 2, -2, 1, -1};

    int num = 10;
    if (positionAvailable(n, matrix, i, j))
    {
        num = 0;
        for (int a = 0; a < 8; a++)
        {
            if (positionAvailable(n, matrix, i + deltaX[a], j + deltaY[a]))
                num += 1;
        }
    }

    return num;
}

void sortJumps(int n, int matrix[n][n], int i, int j, int deltaX[8], int deltaY[8])
{
    int min;
    int temp;
    for (int a = 0; a < 8; a++)
    {
        min = numberPossibleJumps(n, matrix, i + deltaX[a], j + deltaY[a]);
        for (int b = a + 1; b < 8; b++)
        {
            temp = numberPossibleJumps(n, matrix, i + deltaX[b], j + deltaY[b]);
            if (temp < min)
            {
                min = temp;

                temp = deltaX[a];
                deltaX[a] = deltaX[b];
                deltaX[b] = temp;

                temp = deltaY[a];
                deltaY[a] = deltaY[b];
                deltaY[b] = temp;
            }
        }
    }
}

int backtrack(int n, int matrix[n][n], int i, int j)
{
    if (positionAvailable(n, matrix, i, j))
    {
        int deltaX[8] = {1, 1, 2, 2, -1, -1, -2, -2};
        int deltaY[8] = {2, -2, 1, -1, 2, -2, 1, -1};

        sortJumps(n, matrix, i, j, deltaX, deltaY);

        matrix[i][j] = 1;

        if (matrixIsFull(n, matrix))
            return 1;

        for (int c = 0; c < 8; c++)
        {
            // printf("(%d, %d) -> (%d, %d)\n", i, j, i + deltaX[c], j + deltaY[c]);
            if (backtrack(n, matrix, i + deltaX[c], j + deltaY[c]))
                return 1;
            // printf("(%d, %d) <- (%d, %d)\n", i, j, i + deltaX[c], j + deltaY[c]);
        }

        matrix[i][j] = 0;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    /* Reading input */

    int n;
    scanf("%d", &n);

    int matrix[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)

            matrix[i][j] = 0;

    int x, y;
    scanf("%d %d", &x, &y);

    int k;
    scanf("%d", &k);

    int a, b;
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &a, &b);
        matrix[a][b] = -1;
    }

    /* Backtracking */

    if (backtrack(n, matrix, x, y))

        printf("YES\n");

    else

        printf("NO\n");

    return 0;
}
