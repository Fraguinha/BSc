#include "shell.h"

void socp(char *src, char *dst) {
  int fd1 = open(src, O_RDONLY);
  int fd2 = creat(dst, S_IRUSR | S_IWUSR);
  ioCopy(fd1, fd2, 128);
}

int ioCopy(int in, int out, int BUFFSIZE) {
  clock_t inicio, fim;
  float tempoUsado;
  inicio = clock();
  int n;
  char buf[BUFFSIZE];
  while ((n = read(in, buf, BUFFSIZE)) > 0) {
    // fprintf(stderr, "\n*** N=%d dados lidos ***\n", n);
    if (write(out, buf, n) != n) perror("Erro de escrita!\n");
  }
  if (n < 0) perror("Erro de leitura!\n");
  fim = clock();
  tempoUsado = (float)(fim - inicio) / (float)CLOCKS_PER_SEC;
  fprintf(stderr, "%f\n", tempoUsado);
  return (0);
}

void *socpwrapper(void *args) {
  copiar_t *ptr = (copiar_t *)args;
  socp(ptr->src, ptr->dst);
  free(ptr);
  return NULL;
}
