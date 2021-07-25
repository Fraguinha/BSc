#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int fd;
  int buf[10];

  fd = open("test.bin", O_RDONLY);

  read(fd, buf, sizeof(int) * 10);

  for (int i = 0; i < 10; i++) {
    printf("%d\n", buf[i]);
  }

  return 0;
}
