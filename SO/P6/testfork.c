#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int pid, x = 2;
  if ((pid = fork()) == 0) {
    fork();
    pid = fork();
    if (0 == pid)
      x--;
  } else {
    execl("/bin/date", "date", 0);
    x = x + 2;
  }
  printf("x=%d\n", x);
}
