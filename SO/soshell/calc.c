#include "shell.h"

void bits(char *op1, char *op, char *op2) {
  int a = atoi(op1);
  int b = atoi(op2);
  char c = op[0];

  switch (c) {
    case '|':
      printf("%d | %d = %d\n", a, b, a | b);
      break;
    case '&':
      printf("%d & %d = %d\n", a, b, a & b);
      break;
    case '^':
      printf("%d ^ %d = %d\n", a, b, a ^ b);
      break;
    default:
      printf("Invalid operation\n");
      break;
  }
}

void calc(char *value1, char *op, char *value2) {
  float v1 = atof(value1);
  float v2 = atof(value2);

  switch (*op) {
    case '+':
      printf("%f\n", v1 + v2);
      break;

    case '-':
      printf("%f\n", v1 - v2);
      break;

    case '/':
      if (floor(v2) == 0)
        printf("Erro: divisão por zero!\n");
      else
        printf("%f\n", v1 / v2);
      break;

    case '*':
      printf("%f\n", v1 * v2);
      break;

    case '^':
      printf("%f\n", pow(v1, v2));
      break;
  }
}
