#include "client.h"

int main() {
  char menu[MESSAGE_LENGTH];
  int writefd, readfd;

  connect(&writefd, &readfd);
  get_menu(menu, writefd, readfd);
  do_while(menu, writefd, readfd);

  return 0;
}

void connect(int *writefd, int *readfd) {
  *writefd = open(FIFO1, 1);
  *readfd = open(FIFO2, 0);
  char msg[MESSAGE_LENGTH];
  char *f1 = malloc(FILE_SIZE);
  char *f2 = malloc(FILE_SIZE);

  strcpy(msg, "connect");
  write(*writefd, msg, MESSAGE_LENGTH);

  read(*readfd, f1, MESSAGE_LENGTH);
  read(*readfd, f2, MESSAGE_LENGTH);
  read(*readfd, msg, MESSAGE_LENGTH);

  if (strcmp(msg, "ready") == 0) {
    *writefd = open(f1, 1);
    *readfd = open(f2, 0);
  }
}

void get_menu(char *menu, int writefd, int readfd) {
  strcpy(menu, "menu");
  write(writefd, menu, MESSAGE_LENGTH);
  read(readfd, menu, MESSAGE_LENGTH);
}

void do_while(char *menu, int writefd, int readfd) {
  int option = 1;
  do {
    printf("Menu Client\n\n%s\n\n0: Exit\n\n> ", menu);
    scanf(" %d", &option);
    send_option(&option, menu, writefd, readfd);
    if (option == 0) sleep(3);
  } while (option);
}

void send_option(int *option, char *output, int writefd, int readfd) {
  write(writefd, option, SI);
  read(readfd, output, MESSAGE_LENGTH);
  parse_output(output, writefd, readfd);
  if (strcmp(output, "disconnect") != 0) *option = 1;
}

void parse_output(char *output, int writefd, int readfd) {
  int n;
  char str[MESSAGE_LENGTH];
  if (strcmp(output, "id") == 0) {
    printf("\nList id: ");
    scanf(" %d", &n);
    write(writefd, &n, SI);
    read(readfd, output, MESSAGE_LENGTH);
  }
  if (strcmp(output, "idp") == 0) {
    printf("\nMessage id: ");
    scanf(" %d", &n);
    write(writefd, &n, SI);
    read(readfd, output, MESSAGE_LENGTH);
  }
  if (strcmp(output, "filename") == 0) {
    printf("\nfilename: ");
    scanf(" %s", str);
    write(writefd, str, MESSAGE_LENGTH);
    read(readfd, output, MESSAGE_LENGTH);
  }
  if (strcmp(output, "message") == 0) {
    printf("\nmessage: ");
    scanf("%s", str);
    write(writefd, str, MESSAGE_LENGTH);
    read(readfd, output, MESSAGE_LENGTH);
  }
  if (strcmp(output, "password") == 0) {
    printf("\npassword: ");
    scanf(" %s", str);
    write(writefd, str, MESSAGE_LENGTH);
    read(readfd, output, MESSAGE_LENGTH);
  }
  if (strcmp(output, "invalid") == 0) {
    printf("\ninvalid option\n");
    read(readfd, output, MESSAGE_LENGTH);
  }
  if (strcmp(output, "print") == 0) {
    read(readfd, output, MESSAGE_LENGTH);
    printf("\n%s\n\n", output);
    // TODO press enter to continue
    read(readfd, output, MESSAGE_LENGTH);
  }
  if (strcmp(output, "error") == 0) {
    printf("An error as occurred!\n");
    get_menu(output, writefd, readfd);
  }
  if (strcmp(output, "file") == 0) {
    printf("\n");
    read_file(output, writefd, readfd);
  }
  if (strcmp(output, "disconnect") == 0) {
    exit(0);
  }
}

void read_file(char *msg, int writefd, int readfd) {
  read(readfd, msg, MESSAGE_LENGTH);
  if (strcmp(msg, "error") != 0) {
    if (strcmp(msg, "eof") == 0) {
      get_menu(msg, writefd, readfd);
    } else {
      printf("%s\n", msg);
      read_file(msg, writefd, readfd);
    }
  } else {
    parse_output(msg, writefd, readfd);
  }
}
