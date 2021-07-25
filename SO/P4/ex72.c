#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistdc.h>
#define BUFFSIZE 128

int main() {
  int n;
  char buf[BUFFSIZE];
  while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
    fprintf(stderr, "\n*** N=%d dados lidos ***\n", n);

    if (write(STDOUT_FILENO, buf, n) != n) {
      perror("Erro de escrita!\n");
    }
  }
  if (n < 0) perror("Erro de leitura!\n");
  return (0);
}