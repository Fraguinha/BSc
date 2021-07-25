#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    struct _node *children[26];
    int numOccurencesWithinTrie;
    int endOfString;

} TrieNode;

TrieNode *makeTrieNode()
{
    TrieNode *new = malloc(sizeof(TrieNode));

    new->numOccurencesWithinTrie = 0;
    new->endOfString = 0;

    for (int i = 0; i < 26; i++)
    {
        new->children[i] = NULL;
    }

    return new;
}

void insertString(TrieNode *T, char *string)
{
    int length = strlen(string);
    int index;

    for (int i = 0; i < length; i++)
    {
        index = (int)string[i] - (int)'a';

        if (!T->children[index])
            T->children[index] = makeTrieNode();

        T = T->children[index];
    }

    T->endOfString += 1;
}

void insertAllSufixes(TrieNode *T, char *string)
{
    int length = strlen(string);
    char buffer[length];

    for (int i = length - 1; i >= 0; i--)
    {
        memcpy(buffer, &string[i], length);
        buffer[length] = '\0';
        insertString(T, buffer);
    }
}

int setOccurences(TrieNode *T)
{
    int noChildren = 1;
    for (int i = 0; i < 26; i++)
    {
        if (T->children[i] != NULL)
            noChildren = 0;
    }

    if (noChildren)
    {
        T->numOccurencesWithinTrie = T->endOfString;
        return T->numOccurencesWithinTrie;
    }

    int n = T->endOfString;
    for (int i = 0; i < 26; i++)
    {
        if (T->children[i] != NULL)
            n += setOccurences(T->children[i]);
    }
    T->numOccurencesWithinTrie = n;
    return T->numOccurencesWithinTrie;
}

int longestCommonSubstring(TrieNode *T, int numStrings, int i)
{
    if (T->numOccurencesWithinTrie < numStrings)
        return i > 0 ? i : 0;

    int noChildren = 1;
    for (int i = 0; i < 26; i++)
    {
        if (T->children[i] != NULL)
            noChildren = 0;
    }
    if (noChildren)
        return i > 0 ? i : 0;

    int max = i;
    int temp;
    for (int x = 0; x < 26; x++)
    {
        if (T->children[x] != NULL)
        {
            temp = longestCommonSubstring(T->children[x], numStrings, i + 1);
            if (temp > max)
                max = temp;
        }
    }

    return max;
}

int main(int argc, char const *argv[])
{
    /* Reading input */

    char input[100][401];

    int i = 0;
    do
    {
        fgets(input[i], 401, stdin);

    } while (input[i++][0] != '\n');

    /* Removing trailing newlines */

    for (i = 0; i < 100; i++)
    {
        for (int j = 0; j < 401; j++)
        {
            if (input[i][j] == '\n')
            {
                input[i][j] = '\0';
                continue;
            }
        }
    }

    /* Building suffixTrie */

    TrieNode *root = makeTrieNode();
    int numStrings = 0;

    i = 0;
    while (input[i][0] != '\0')
    {
        numStrings++;
        insertAllSufixes(root, input[i++]);
    }

    setOccurences(root);

    /* Get answer */

    printf("%d\n", longestCommonSubstring(root, numStrings, -1));

    return 0;
}
