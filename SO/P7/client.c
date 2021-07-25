#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO1 "/tmp/fifo.1"
#define FIFO2 "/tmp/fifo.2"
#define PERMS 0666

#define SR sizeof(float)

int main(int argc, char const *argv[]) {
  int writefd = open(FIFO1, 1);
  int readfd = open(FIFO2, 0);
  float op1, op2, res;
  char op;
  scanf("%f %f %c", &op1, &op2, &op);
  write(writefd, &op1, SR);
  write(writefd, &op2, SR);
  write(writefd, &op, 1);
  read(readfd, &res, SR);
  printf("Result %f\n", res);
  return 0;
}
