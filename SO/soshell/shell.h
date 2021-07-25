#include <ctype.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int parse(char *buf, char **args);

void execute(int numargs, char **args);

int builtin(char **args);

void socp(char *src, char *dst);

void *socpwrapper(void *args);

int ioCopy(int in, int out, int BUFFSIZE);

int redirects(int numargs, char *args[]);

int containsPipe(int numArgs, char **args);

void aviso(char *mesg, int tempo);

void *avisowrapper(void *args);

void bits(char *op1, char *op, char *op2);

void calc(char *value1, char *op, char *value2);

/* constantes que podem tornar uteis*/

#define BG 0
#define FG 1

typedef struct {
  char msg[100];
  int tempo;
} aviso_t;

typedef struct {
  char src[100];
  char dst[100];
} copiar_t;
