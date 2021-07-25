#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define SR sizeof(float)

int main(int argc, char const *argv[]) {
  int pid, p1[2], p2[2];

  float op1, op2, res;
  char op;

  pipe(p1);
  pipe(p2);

  pid = fork();

  if (0 == pid) {
    scanf("%f %f %c", &op1, &op2, &op);
    write(p1[1], &op1, SR);
    write(p1[1], &op2, SR);
    write(p1[1], &op, 1);
    read(p2[0], &res, SR);
    printf("Result %f\n", res);
  } else {
    read(p1[0], &op1, SR);
    read(p1[0], &op2, SR);
    read(p1[0], &op, 1);
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
    write(p2[1], &res, SR);
  }
  return 0;
}
