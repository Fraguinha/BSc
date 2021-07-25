#include <stdio.h>

void streamCopy(FILE *input, FILE *output);

int main(int argc, char *argv[]) {
  if(argc != 3) {
    fprintf(stderr, "usage: %s [source] [destination]\n", argv[0]);
    return 1;
  }

  FILE *input=fopen(argv[1], "r");
  if (input == NULL) {
    fprintf(stderr, "invalid file: %s\n", argv[1]);
    return 1;
  }
  FILE *output=fopen(argv[2], "w");
  if (output == NULL) {
    fprintf(stderr, "cannot open file: %s\n", argv[2]);
    return 1;
  }
  streamCopy(input, output);
  return 0;
}

void streamCopy(FILE *input, FILE *output) {
  int ch;
  while((ch=fgetc(input)) != EOF) {
    fputc(ch, output);
  }
} 
