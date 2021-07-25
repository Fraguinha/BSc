#include "shell.h"

int containsPipe(int numArgs, char **args)
{
    int index;
    for (index = 0; index < numArgs; index++)
        if (args[index][0] == '|')
        {
            args[index] = NULL;
            return index;
        }
    return -1;
}
