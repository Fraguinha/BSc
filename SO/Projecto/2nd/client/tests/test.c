#include "test.h"

pthread_t threads[NUM_TESTS];
int del = 0;

int main(int argc, char const *argv[]) {
  test(create_queue_test, NUM_TESTS);
  test(insert_messages_test, NUM_TESTS);
  test(delete_messages_test, NUM_TESTS);

  printf("\n\nPASSED: %s\n", argv[0]);
  return 0;
}

void test(void *f(void *), int n) {
  for (int i = 0; i < n; i++) {
    pthread_create(&threads[i], NULL, *f, NULL);
  }
  sleep(1);
}

void *create_queue_test(void *args) {
  int writefd, readfd;
  connect(&writefd, &readfd);
  char msg[MESSAGE_LENGTH];
  create_queue(msg, writefd, readfd);
  read(readfd, msg, MESSAGE_LENGTH);
  read(readfd, msg, MESSAGE_LENGTH);
  return NULL;
}

void *insert_messages_test(void *args) {
  int writefd, readfd;
  connect(&writefd, &readfd);
  char msg[MESSAGE_LENGTH];
  strcpy(msg, "test");
  insert_message(msg, writefd, readfd);
  read(readfd, msg, MESSAGE_LENGTH);
  write(writefd, 0, SI);
  read(readfd, msg, MESSAGE_LENGTH);
  write(writefd, msg, MESSAGE_LENGTH);
  read(readfd, msg, MESSAGE_LENGTH);
  read(readfd, msg, MESSAGE_LENGTH);
  return NULL;
}

void *delete_messages_test(void *args) {
  int writefd, readfd;
  connect(&writefd, &readfd);
  char msg[MESSAGE_LENGTH];
  delete_message(msg, writefd, readfd);
  write(writefd, 0, SI);
  int i = del++;
  write(writefd, &i, SI);
  read(readfd, msg, MESSAGE_LENGTH);
  read(readfd, msg, MESSAGE_LENGTH);
  read(readfd, msg, MESSAGE_LENGTH);
  read(readfd, msg, MESSAGE_LENGTH);
  return NULL;
}
