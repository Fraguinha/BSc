#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pixel
{
    /* Info */
    int *layer;

    /* Coords */
    int X;
    int Y;

    /* Neighbours */
    struct _pixel *neighbour[4];

} Pixel;

typedef struct _list
{
    Pixel *p;

    struct _list *next;

} List;

typedef struct _stack
{
    Pixel *p;

    struct _stack *next;

} Stack;

typedef struct _frame
{
    /* Info */
    char *name;

    int rows;
    int columns;
    int layers;

    /* Image */
    Pixel ***pixels;

    /* Index */
    List ****index;

    /* Next frame */
    struct _frame *next;

} Frame;

typedef struct _region
{
    /* Coords */
    int X;
    int Y;

    /* Number of pixels */
    int count;

} Region;

List *makeList(Pixel *p);
List *addList(List *L, List *new);

Stack *makeStack(Pixel *p);
Stack *push(Stack *S, Stack *new);
Stack *pop(Stack **S);

Frame *makeFrame(char *name, int rows, int columns, int layers);
Frame *addFrame(Frame *start, Frame *new);

Frame *readInput(FILE *input);

void explore(Pixel *p, int R, int G, int B, int T, int **visited, Region *region, int r);
void search(Frame *f, int R, int G, int B, int T);

void mergesort_dec(Region *r, int start, int end);
void merge(Region *v, int start, int middle, int end);

int main(int argc, char const *argv[])
{
    /* Check for input file in commandline arguments */
    if (argc < 2)
    {
        printf("Please provide the images as a commandline argument\nEx: %s input.txt\n", argv[0]);
        return 1;
    }

    /* Open file */
    FILE *input = fopen(argv[1], "r");

    /* Read input from file */
    Frame *video = readInput(input);

    /* Close file */
    fclose(input);

    /* While you want to search */
    int exit = 0;
    char option;
    while (!exit)
    {
        /* Ask for user input */
        int R, G, B, T;
        printf("Insert the RGB value of the color region you want to search:\n");

        printf("R [0-255]: ");
        scanf(" %d", &R);
        R = (R <= 255 ? (R >= 0 ? R : 0) : 255);

        printf("G [0-255]: ");
        scanf(" %d", &G);
        G = (G <= 255 ? (G >= 0 ? G : 0) : 255);

        printf("B [0-255]: ");
        scanf(" %d", &B);
        B = (B <= 255 ? (B >= 0 ? B : 0) : 255);

        printf("Insert the tolerance value:\n");
        printf("T[0 - 255]: ");
        scanf(" %d", &T);
        T = (T <= 255 ? (T >= 0 ? T : 0) : 255);

        /* Search for regions */
        search(video, R, G, B, T);

        /* Again? */
        printf("Search again? [Y/n] ");
        scanf(" %c", &option);

        if (option == 'n' || option == 'N')
            exit = 1;
    }

    /* Success */
    return 0;
}

List *makeList(Pixel *p)
{
    /* Create list */
    List *new = malloc(sizeof(List));

    /* Assign the pixel */
    new->p = p;

    /* Null the next */
    new->next = NULL;

    /* Return new list*/
    return new;
}

List *addList(List *L, List *new)
{
    /* Point to the rest of the list */
    new->next = L;

    /* Return new list */
    return new;
}

Stack *makeStack(Pixel *p)
{
    /* Create stack */
    Stack *new = malloc(sizeof(Stack));

    /* Assign pixel */
    new->p = p;

    /* Null the next */
    new->next = NULL;

    /* Return new stack */
    return new;
}

Stack *push(Stack *S, Stack *new)
{
    /* Add to top */
    new->next = S;

    /* Return updated stack */
    return new;
}

Stack *pop(Stack **S)
{
    /* if stack is empty */
    if (*S == NULL)
    {
        return *S;
    }

    /* Save top of stack */
    Stack *aux = *S;

    /* Update stack */
    *S = (*S)->next;

    /* Return the top of the stack */
    return aux;
}

Frame *makeFrame(char *name, int rows, int columns, int layers)
{
    /* Create Frame */
    Frame *new = malloc(sizeof(Frame));

    /* Assign frame information */
    new->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(new->name, name);

    new->rows = rows;
    new->columns = columns;
    new->layers = layers;

    /* Create matrix of pixel pointers */
    new->pixels = malloc(rows * sizeof(Pixel *));
    for (int i = 0; i < rows; i++)
    {
        new->pixels[i] = malloc(columns * sizeof(Pixel *));

        /* Assign them pixels */
        for (int j = 0; j < columns; j++)
        {
            new->pixels[i][j] = malloc(sizeof(Pixel));
        }
    }

    /* Create index */
    new->index = malloc(256 * sizeof(List **
                                         *));
    for (int i = 0; i < 256; i++)
    {
        new->index[i] = malloc(256 * sizeof(List **));
        for (int j = 0; j < 256; j++)
        {
            new->index[i][j] = malloc(256 * sizeof(List *));
            for (int k = 0; k < 256; k++)
            {
                new->index[i][j][k] = NULL;
            }
        }
    }

    /* Assign pixel information */
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            /* Create array of layers */
            new->pixels[i][j]->layer = malloc(layers * sizeof(int));

            /* Set coords */
            new->pixels[i][j]->X = i;
            new->pixels[i][j]->Y = j;

            /* Set neighbours */
            // Top
            if (i - 1 >= 0)
                new->pixels[i][j]->neighbour[0] = new->pixels[i - 1][j];
            else
                new->pixels[i][j]->neighbour[0] = NULL;

            // Right
            if (j + 1 < columns)
                new->pixels[i][j]->neighbour[1] = new->pixels[i][j + 1];
            else
                new->pixels[i][j]->neighbour[1] = NULL;

            // Bottom
            if (i + 1 < rows)
                new->pixels[i][j]->neighbour[2] = new->pixels[i + 1][j];
            else
                new->pixels[i][j]->neighbour[2] = NULL;

            // Left
            if (j - 1 >= 0)
                new->pixels[i][j]->neighbour[3] = new->pixels[i][j - 1];
            else
                new->pixels[i][j]->neighbour[3] = NULL;
        }
    }

    /* Null the next */
    new->next = NULL;

    /* Return new frame */
    return new;
}

Frame *addFrame(Frame *start, Frame *new)
{
    /* If list is empty */
    if (start == NULL)
        return new;

    /* Traveler pointer */
    Frame *f = start;

    /* Go to last frame of list */
    while (f->next != NULL)
    {
        f = f->next;
    }

    /* Add new frame */
    f->next = new;

    /* Return the updated list */
    return start;
}

Frame *readInput(FILE *input)
{
    /* List of frames */
    Frame *video = NULL;

    /* Auxiliar variables */
    Frame *f;
    char buffer[300];
    int rows, columns, layers;

    /* While there are frames */
    while (fscanf(input, " %s\n", buffer) != EOF)
    {
        /* Read rows, columns and layers */
        fscanf(input, " %d %d %d", &rows, &columns, &layers);

        /* Create a frame that size */
        f = makeFrame(buffer, rows, columns, layers);

        /* Read rgb value of each pixel */
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                for (int k = 0; k < layers; k++)
                {
                    /* Scan values */
                    fscanf(input, " %d", &(f->pixels[i][j]->layer[k]));
                }
                /* Add pixel to index */
                int r = f->pixels[i][j]->layer[0];
                int g = f->pixels[i][j]->layer[1];
                int b = f->pixels[i][j]->layer[2];
                f->index[r][g][b] = addList(f->index[r][g][b], makeList(f->pixels[i][j]));
            }
        }

        /* Add frame to list */
        video = addFrame(video, f);
    }

    /* Return the list of frames */
    return video;
}

void mergesort_dec(Region *r, int start, int end)
{
    int middle;

    if (start < end)
    {
        /* calculate middle */
        middle = (start + end) / 2;

        /* merge left */
        mergesort_dec(r, start, middle);

        /* merge right */
        mergesort_dec(r, middle + 1, end);

        /* merge all */
        merge(r, start, middle, end);
    }
}

void merge(Region *v, int start, int middle, int end)
/* Use intructions from the internet to perform this wizardry */
{
    int left = start;
    int right = middle + 1;

    Region *aux = malloc((end - start + 1) * sizeof(Region));
    int k = 0;

    while ((left <= middle) && (right <= end))
    {
        if (v[left].count > v[right].count)
        {
            aux[k] = v[left];
            left++;
        }
        else
        {
            aux[k] = v[right];
            right++;
        }
        k++;
    }
    if (left > middle)
    {
        for (int i = right; i <= end; i++)
        {
            aux[k] = v[i];
            k++;
        }
    }
    else
    {
        for (int i = left; i <= middle; i++)
        {
            aux[k] = v[i];
            k++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        v[start + i] = aux[i];
    }
    free(aux);
}

void explore(Pixel *p, int R, int G, int B, int T, int **visited, Region *region, int r)
{
    /* Create pixel pointer stack */
    Stack *S = NULL;
    S = push(S, makeStack(p));

    /* While there are pixels to explore */
    while (S != NULL)
    {
        /* Get pixel from stack */
        p = pop(&S)->p;

        /* If not visited & pixel within tolerance */
        if (p != NULL && !visited[p->X][p->Y] &&
            p->layer[0] >= R - T &&
            p->layer[0] <= R + T &&
            p->layer[1] >= G - T &&
            p->layer[1] <= G + T &&
            p->layer[2] >= B - T &&
            p->layer[2] <= B + T)
        {
            /* Mark as visited */
            visited[p->X][p->Y] = 1;

            /* Update region info */
            region[r].count += 1;

            region[r].X += p->X;
            region[r].Y += p->Y;

            /* mark neighbours for exploration */
            for (int i = 0; i < 4; i++)
            {
                /* add neighbour to pointer stack */
                S = push(S, makeStack(p->neighbour[i]));
            }
        }
    }
}

void search(Frame *frames, int R, int G, int B, int T)
{
    /* Run through the frames */
    while (frames != NULL)
    {
        /* Create visited flag matrix */
        int **visited = malloc(frames->rows * sizeof(int *));
        for (int i = 0; i < frames->rows; i++)
        {
            visited[i] = calloc(frames->columns, sizeof(int));
        }

        /* Create region array */
        Region *region = malloc(sizeof(Region));
        int r = 0;
        region[r].count = 0;
        region[r].X = 0;
        region[r].Y = 0;

        /* Search frames within region for regions */
        List *L;
        for (int i = (R - T >= 0 ? R - T : 0); i <= (R + T <= 255 ? R + T : 255); i++)
        {
            for (int j = (G - T >= 0 ? G - T : 0); j <= (G + T <= 255 ? G + T : 255); j++)
            {
                for (int k = (B - T >= 0 ? B - T : 0); k <= (B + T <= 255 ? B + T : 255); k++)
                {
                    L = frames->index[i][j][k];
                    while (L != NULL)
                    {
                        /* If not visited & pixel within tolerance */
                        if (!visited[L->p->X][L->p->Y])
                        {
                            /* explore region */
                            explore(L->p, R, G, B, T, visited, region, r);

                            /* Set region center */
                            if (region[r].count > 0)
                            {
                                region[r].X = region[r].X / region[r].count;
                                region[r].Y = region[r].Y / region[r].count;
                            }

                            /* Increment region array */
                            region = realloc(region, (++r + 1) * sizeof(Region));
                            region[r].count = 0;
                            region[r].X = 0;
                            region[r].Y = 0;
                        }

                        /* Move to next pixel */
                        L = L->next;
                    }
                }
            }
        }

        /* Decrement region array */
        region = realloc(region, r * sizeof(Region));

        /* Sort regions by number of pixels */
        mergesort_dec(region, 0, r);

        /* Print sorted regions */
        for (int i = 0; i < r; i++)
        {
            printf("%s; (%d, %d): %d pixels\n", frames->name, region[i].X, region[i].Y, region[i].count);
        }

        /* Free auxiliary matrix */
        for (int i = 0; i < frames->rows; i++)
        {
            free(visited[i]);
        }
        free(visited);

        /* Free auxiliary array */
        free(region);

        /* Move to next frame */
        frames = frames->next;
    }
}
