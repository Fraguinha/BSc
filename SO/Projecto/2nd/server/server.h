#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef SERVER_H
#define SERVER_H

#define SECRET_DIR "root/secret/"
#define FILE_DIR "root/files/"
#define TMP_DIR "/tmp/"

#define FIFO2 "/tmp/fifo.W"
#define FIFO1 "/tmp/fifo.R"

#define PASSWORD "1234"

#define MESSAGE_LENGTH 4096
#define MAX_QUEUES 256
#define FILE_SIZE 1024
#define PERMS 0666

#define SI sizeof(int)

typedef struct linkedList {
  int id;
  char *message;
  struct linkedList *next;
} linkedList;

linkedList *make_node(int id, const char *message, int size);
linkedList *push(linkedList *L, linkedList *new);
linkedList *pop(linkedList **L, int id);

typedef struct serverArgs {
  char f1[FILE_SIZE];
  char f2[FILE_SIZE];
  int fd1;
  int fd2;
} serverArgs;

int start();

void nothing();

void get_filename(char *filename, const char *directory, int thread_id,
                  int read_flag);

void *server(void *args);

void server_file(char *msg, int writefd, int readfd);

void print_file(char *msg, int fd, int writefd);

void server_queue(char *msg, int writefd, int readfd);
void create_queue(char *msg, int writefd, int readfd);
void check_queue(char *msg, int writefd, int readfd);
void check_messages(char *msg, int writefd, int readfd);
void insert_message(char *msg, int writefd, int readfd);
void print_message(char *msg, int writefd, int readfd);
void delete_message(char *msg, int writefd, int readfd);

int is_empty_list(linkedList **arr);
void print_list(linkedList *L, char *msg);
void count_list(linkedList *L, int *c);
void print_message_list(linkedList *L, int id, char *msg);

#endif
