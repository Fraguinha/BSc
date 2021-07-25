#include <stdio.h>

void streamCopy(FILE *input, FILE *output);

int main(int argc, char *argv[]) {
  if(argc == 1)
    streamCopy(stdin, stdout);
  if(argc == 3) {
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
    streamCopy(input, output); 
  }
  return 0;
}

void streamCopy(FILE *input, FILE *output) {
  int ch;
  while ((ch=fgetc(input)) != EOF) {
    fputc(ch, output);
  }
}
