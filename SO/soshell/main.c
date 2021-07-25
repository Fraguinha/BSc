#include "shell.h"

char prompt[100];

int main() {
  int len;
  char buf[1024]; /* um comando */
  char *args[64]; /* com um maximo de 64 argumentos */

  strcpy(prompt, "SOSHELL: Introduza um comando : prompt>");

  while (1) {
    printf("%s", prompt);

    if (fgets(buf, 1023, stdin) == NULL) {
      printf("\n");
      exit(0);
    }
    len = strlen(buf);
    if (1 == len) continue;  // string is only a barra n
    if (buf[len - 1] == '\n') buf[len - 1] = '\0';

    int numargs = parse(buf, args); /* particiona a string em argumentos */

    if (!builtin(args)) execute(numargs, args); /* executa o comando */
  }
  return 0;
}

int builtin(char **args) {
  if (strcmp(args[0], "sair") == 0) {
    exit(0);
    return 1;
  }

  if (strcmp(args[0], "obterinfo") == 0) {
    printf("SoShell 2018 versao 1.0\n");
    return 1;
  }

  if (strlen(args[0]) > 4 && strncmp(args[0], "PS1=", 4) == 0) {
    strcpy(prompt, args[0] + 4);
    return 1;
  }

  if (strcmp(args[0], "quemsoueu") == 0) {
    system("id");
    return 1;
  }

  if (0 == strcmp(args[0], "cd")) {
    int err;
    if (args[1] == NULL || strcmp(args[1], "~") == 0)
      err = chdir(getenv("HOME"));
    else
      err = chdir(args[1]);
    if (err < 0) perror("chdir failed");
    return 1;  // comando embutido
  }

  if (0 == strcmp(args[0], "bits")) {
    bits(args[1], args[2], args[3]);
    return 1;
  }

  if (strcmp(args[0], "socp") == 0) {
    pthread_t th;
    copiar_t *ptr = (copiar_t *)malloc(sizeof(aviso_t));
    strcpy(ptr->src, args[1]);
    strcpy(ptr->dst, args[2]);
    pthread_create(&th, NULL, socpwrapper, (void *)ptr);
    return 1;
  }

  if (strcmp(args[0], "aviso") == 0) {
    pthread_t th;
    aviso_t *ptr = (aviso_t *)malloc(sizeof(aviso_t));
    strcpy(ptr->msg, args[1]);
    ptr->tempo = atoi(args[2]);
    pthread_create(&th, NULL, avisowrapper, (void *)ptr);
    return 1;
  }

  // devolver 0 indique que nao ha comando embutido
  return 0;
}
