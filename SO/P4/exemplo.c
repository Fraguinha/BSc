#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  int i, fd, vec[10];
  for (i = 0; i < 10; ++i) {
    vec[i] = i + 512;
  }
  fd = creat("test.bin", S_IRUSR| S_IWUSR);
  write(fd, vec, sizeof(int) * 10);
  return 0;
}
