/*
   execute . cria um processo prog�nito e executa um programa
*/
#include "shell.h"

int ultimo(int numargs, char **args);

void execute(int numargs, char **args)
{
  int fd[2];
  int pid, pidFilho, status = -69, indice;

  int code = ultimo(numargs, args);
  if (code == BG)
    numargs--;

  if ((pid = fork()) < 0)
  {                  /* cria um processo progenito */
    perror("forks"); /* NOTE: perror() produz uma pequema mensagem
                             * de erro para o stream */
    exit(1);         /* estandardizado de erros que descreve o
                             * ultimo erro encontrado */
    /* durante uma chamada ao sistema ou funcao duma biblioteca */
  }

  if (pid == 0)
  {

    indice = containsPipe(numargs, args);
    if (indice == -1)
    {
      numargs = redirects(numargs, args);
      if (numargs == -1)
        exit(1);
      execvp(*args, args); /* NOTE: as versoes execv() e
                            * execvp() de execl() sao uteis
                          * quando */
    }

    else if (indice > 0)
    {
      args[indice] = NULL;
      pipe(fd);
      pidFilho = fork();
      if (pidFilho == 0)
      { //write
        numargs = indice;
        numargs = redirects(numargs, args);
        if (numargs == -1)
          exit(1);
        fprintf(stderr, "cmd write to pipe: %s numArgs=%d\n", args[0], numargs);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
      }
      else
      { //read
        args = args + indice + 1;
        numargs = numargs - indice - 1;
        numargs = redirects(numargs, args);
        if (numargs == -1)
          exit(1);
        fprintf(stderr, "cmd read from pipe: %s numArgs=%d\n", args[0], numargs);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
      }
      execvp(*args, args);
    }

    perror(*args); /* o numero de argumentos nao e. conhecido.
                          * Os argumentos de  */
    exit(1);       /* execv() e execvp() sao o nome do ficheiro
                          * a ser executado e um */
  }                /* vector de strings que contem os
                          * argumentos. O ultimo argumento é NULL */

  if (FG == code)
  {
    while (wait(&status) != pid)
      ; /*spin fazer nada*/
  }
  fprintf(stderr, "status=%d\n", status);
  return;
}

int ultimo(int numargs, char **args)
{
  if (args[numargs - 1][0] == '&')
  {
    args[numargs - 1] = NULL;
    return BG;
  }
  return FG;
}
