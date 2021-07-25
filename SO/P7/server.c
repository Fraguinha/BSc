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
  int pid, status;
  while (1) {
    pid = fork();
    if (pid == 0) {
      mknod(FIFO1, S_IFIFO | PERMS, 0);
      mknod(FIFO2, S_IFIFO | PERMS, 0);
      int readfd = open(FIFO1, 0);
      int writefd = open(FIFO2, 1);
      float op1, op2, res;
      char op;
      read(readfd, &op1, SR);
      read(readfd, &op2, SR);
      read(readfd, &op, 1);
      switch (op) {
        case '+':
          res = op1 + op2;
          break;
        case '-':
          res = op1 - op2;
        case '*':
          res = op1 * op2;
          break;
        case '/':
          res = op1 / op2;
          break;
        default:
          printf("Invalid operation\n");
          break;
      }
      write(writefd, &res, SR);
      exit(0);
    } else {
      wait(&status);
    }
  }
  return 0;
}
