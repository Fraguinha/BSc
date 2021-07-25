#include "server.h"

linkedList *queues[MAX_QUEUES];
int used_lists[MAX_QUEUES];

pthread_mutex_t lock;

int start() {
  pthread_mutex_init(&lock, NULL);
  signal(SIGPIPE, SIG_IGN);

  for (int i = 0; i < MAX_QUEUES; i++) {
    used_lists[i] = 0;
  }

  char *msg = malloc(MESSAGE_LENGTH);

  pthread_t t;
  int writefd, readfd;
  int id = 0;

  while (1) {
    // create fifo
    mkfifo(FIFO1, PERMS);
    mkfifo(FIFO2, PERMS);
    // open fifo
    readfd = open(FIFO1, 0);
    writefd = open(FIFO2, 1);
    // Handle connection
    read(readfd, msg, MESSAGE_LENGTH);
    if (strcmp(msg, "connect") == 0) {
      // Create arguments
      serverArgs *args = malloc(sizeof(serverArgs));
      args->fd1 = readfd;
      args->fd2 = writefd;
      // get_id(&(args->idx));
      get_filename(args->f1, TMP_DIR, id, 1);
      get_filename(args->f2, TMP_DIR, id, 0);
      // Send info to client
      write(writefd, args->f1, MESSAGE_LENGTH);
      write(writefd, args->f2, MESSAGE_LENGTH);
      // Switch client to thread
      pthread_create(&t, NULL, server, args);
      id++;
      // delete fifo
      unlink(FIFO1);
      unlink(FIFO2);
    }
  }
  return 0;
}

void nothing() {}

linkedList *make_node(int id, const char *message, int size) {
  linkedList *new = malloc(sizeof(linkedList));
  new->id = id;
  new->message = malloc(size * sizeof(char));
  strcpy(new->message, message);
  return new;
}

linkedList *push(linkedList *L, linkedList *new) {
  linkedList *hd = L;
  if (L != NULL) {
    while (L->next != NULL) {
      L = L->next;
    }
    L->next = new;
  } else {
    hd = new;
  }
  return hd;
}

linkedList *pop(linkedList **L, int id) {
  linkedList *el = NULL;
  if (*L != NULL) {
    if (id == 0) {
      el = *L;
      *L = (*L)->next;
    } else {
      linkedList *tl = *L;
      while (tl->next != NULL) {
        if (tl->next->id == id) {
          el = tl->next;
          tl->next = tl->next->next;
        } else {
          tl = tl->next;
        }
      }
    }
  }
  return el;
}

void get_filename(char *filename, const char *directory, int thread_id,
                  int read_flag) {
  filename[0] = '\0';
  char num[4];
  sprintf(num, "%d", thread_id);
  char extension[3];
  if (read_flag)
    strcpy(extension, ".R");
  else
    strcpy(extension, ".W");
  strcat(filename, directory);
  strcat(filename, num);
  strcat(filename, extension);
}

void *server(void *args) {
  char *option_file = "1: files";
  char *option_queue = "2: queues";
  serverArgs *p = (serverArgs *)args;
  char msg[MESSAGE_LENGTH];
  int option = 1;
  msg[0] = '\0';
  // create fifo
  mkfifo(p->f1, PERMS);
  mkfifo(p->f2, PERMS);
  write(p->fd2, "ready", MESSAGE_LENGTH);
  int readfd = open(p->f1, 0);
  int writefd = open(p->f2, 1);
  // handle client
  while (option != 0) {
    if (strcmp(msg, "back") == 0) {
      strcpy(msg, "menu");
    } else {
      read(readfd, msg, MESSAGE_LENGTH);
    }
    if (strcmp(msg, "menu") == 0) {
      strcpy(msg, option_file);
      strcat(msg, "\n");
      strcat(msg, option_queue);
      ssize_t rc;
      rc = write(writefd, msg, MESSAGE_LENGTH);
      if (rc == -1) {
        option = 0;
      }
      read(readfd, &option, SI);
      switch (option) {
        case 0:
          break;
        case 1:
          server_file(msg, writefd, readfd);
          break;
        case 2:
          server_queue(msg, writefd, readfd);
          break;
        default:
          strcpy(msg, "invalid");
          write(writefd, msg, MESSAGE_LENGTH);
          strcpy(msg, "back");
      }
    }
  }
  // send disconnect
  strcpy(msg, "disconnect");
  write(writefd, msg, MESSAGE_LENGTH);
  // delete fifo
  unlink(p->f1);
  unlink(p->f2);
  return NULL;
}

void server_file(char *msg, int writefd, int readfd) {
  char file[FILE_SIZE];
  strcpy(msg, "filename");
  write(writefd, msg, MESSAGE_LENGTH);
  read(readfd, msg, MESSAGE_LENGTH);

  strcpy(file, FILE_DIR);
  strcat(file, msg);

  int fd = open(file, O_RDONLY);

  if (fd == -1) {
    strcpy(file, SECRET_DIR);
    strcat(file, msg);

    int fd = open(file, O_RDONLY);

    if (fd == -1) {
      strcpy(msg, "error");
      write(writefd, msg, MESSAGE_LENGTH);
    } else {
      strcpy(msg, "password");
      write(writefd, msg, MESSAGE_LENGTH);
      read(readfd, msg, MESSAGE_LENGTH);

      if (strcmp(msg, PASSWORD) == 0) {
        print_file(msg, fd, writefd);
      } else {
        strcpy(msg, "error");
        write(writefd, msg, MESSAGE_LENGTH);
      }
    }
  } else {
    print_file(msg, fd, writefd);
  }
}

void print_file(char *msg, int fd, int writefd) {
  int n;
  strcpy(msg, "file");
  write(writefd, msg, MESSAGE_LENGTH);
  while ((n = read(fd, msg, MESSAGE_LENGTH)) > 0) {
    write(writefd, msg, MESSAGE_LENGTH);
  }
  strcpy(msg, "eof");
  write(writefd, msg, MESSAGE_LENGTH);
}

void server_queue(char *msg, int writefd, int readfd) {
  char *option_1 = "1: create queue";
  char *option_2 = "2: check queues";
  char *option_3 = "3: check messages";
  char *option_4 = "4: insert message";
  char *option_5 = "5: print message";
  char *option_6 = "6: delete message";
  int option = 1;
  ssize_t rc;
  while (option != 0) {
    strcpy(msg, option_1);
    strcat(msg, "\n");
    if (!is_empty_list(queues)) {
      strcat(msg, option_2);
      strcat(msg, "\n");
      strcat(msg, option_3);
      strcat(msg, "\n");
      strcat(msg, option_4);
      strcat(msg, "\n");
      strcat(msg, option_5);
      strcat(msg, "\n");
      strcat(msg, option_6);
      strcat(msg, "\n");
    }

    rc = write(writefd, msg, MESSAGE_LENGTH);
    if (rc == -1) {
      return;
    }
    read(readfd, &option, SI);

    switch (option) {
      case 0:
        strcpy(msg, "back");
        break;
      case 1:
        create_queue(msg, writefd, readfd);
        break;
      case 2:
        check_queue(msg, writefd, readfd);
        break;
      case 3:
        check_messages(msg, writefd, readfd);
        break;
      case 4:
        insert_message(msg, writefd, readfd);
        break;
      case 5:
        print_message(msg, writefd, readfd);
        break;
      case 6:
        delete_message(msg, writefd, readfd);
        break;
      default:
        strcpy(msg, "invalid");
        write(writefd, msg, MESSAGE_LENGTH);
    }
  }
}

void create_queue(char *msg, int writefd, int readfd) {
  pthread_mutex_lock(&lock);
  for (int i = 0; i < MAX_QUEUES; i++) {
    if (used_lists[i] == 0) {
      used_lists[i] = 1;
      strcpy(msg, "print");
      write(writefd, msg, MESSAGE_LENGTH);
      sprintf(msg, "Queue %d created successfully", i);
      write(writefd, msg, MESSAGE_LENGTH);
      break;
    }
  }
  pthread_mutex_unlock(&lock);
}

void check_queue(char *msg, int writefd, int readfd) {
  pthread_mutex_lock(&lock);
  strcpy(msg, "print");
  write(writefd, msg, MESSAGE_LENGTH);
  msg[0] = '\0';
  for (int i = 0; i < MAX_QUEUES; i++) {
    if (used_lists[i] == 1) {
      char str[MESSAGE_LENGTH];
      sprintf(str, "%d", i);
      strcat(msg, str);
      strcat(msg, "\n");
    }
  }
  write(writefd, msg, MESSAGE_LENGTH);
  pthread_mutex_unlock(&lock);
}

void check_messages(char *msg, int writefd, int readfd) {
  pthread_mutex_lock(&lock);
  int id;
  msg[0] = '\0';
  strcpy(msg, "id");
  write(writefd, msg, MESSAGE_LENGTH);
  read(readfd, &id, SI);
  if (id < MAX_QUEUES && id >= 0) {
    strcpy(msg, "print");
    write(writefd, msg, MESSAGE_LENGTH);
    strcpy(msg, "");
    print_list(queues[id], msg);
    write(writefd, msg, MESSAGE_LENGTH);
  }
  pthread_mutex_unlock(&lock);
}

void insert_message(char *msg, int writefd, int readfd) {
  pthread_mutex_lock(&lock);
  int id;
  msg[0] = '\0';
  strcpy(msg, "id");
  write(writefd, msg, MESSAGE_LENGTH);
  read(readfd, &id, SI);
  if (id < MAX_QUEUES && id >= 0) {
    strcpy(msg, "message");
    write(writefd, msg, MESSAGE_LENGTH);
    read(readfd, msg, MESSAGE_LENGTH);
    int c = 0;
    count_list(queues[id], &c);
    linkedList *new = make_node(c, msg, strlen(msg) + 1);
    queues[id] = push(queues[id], new);
    strcpy(msg, "print");
    write(writefd, msg, MESSAGE_LENGTH);
    strcpy(msg, "Message inserted successfuly");
    write(writefd, msg, MESSAGE_LENGTH);
  }
  pthread_mutex_unlock(&lock);
}

void print_message(char *msg, int writefd, int readfd) {
  pthread_mutex_lock(&lock);
  int id, idx;
  msg[0] = '\0';
  strcpy(msg, "id");
  write(writefd, msg, MESSAGE_LENGTH);
  read(readfd, &id, SI);
  if (id < MAX_QUEUES && id >= 0) {
    strcpy(msg, "idp");
    write(writefd, msg, MESSAGE_LENGTH);
    read(readfd, &idx, SI);
    strcpy(msg, "print");
    write(writefd, msg, MESSAGE_LENGTH);
    print_message_list(queues[id], idx, msg);
    write(writefd, msg, MESSAGE_LENGTH);
  }
  pthread_mutex_unlock(&lock);
}

void delete_message(char *msg, int writefd, int readfd) {
  pthread_mutex_lock(&lock);
  int id, idx;
  msg[0] = '\0';
  strcpy(msg, "id");
  write(writefd, msg, MESSAGE_LENGTH);
  read(readfd, &id, SI);
  if (id < MAX_QUEUES && id >= 0) {
    strcpy(msg, "idp");
    write(writefd, msg, MESSAGE_LENGTH);
    read(readfd, &idx, SI);
    linkedList *el = pop(&queues[id], idx);
    free(el);
    strcpy(msg, "print");
    write(writefd, msg, MESSAGE_LENGTH);
    strcpy(msg, "Message deleted successfuly");
    write(writefd, msg, MESSAGE_LENGTH);
  }
  pthread_mutex_unlock(&lock);
}

int is_empty_list(linkedList **arr) {
  for (int i = 0; i < MAX_QUEUES; i++) {
    if (used_lists[i] == 1) return 0;
  }
  return 1;
}

void print_list(linkedList *L, char *msg) {
  if (L != NULL) {
    char str[MESSAGE_LENGTH];
    sprintf(str, "%d", L->id);
    strcat(msg, str);
    strcat(msg, "\n");
    print_list(L->next, msg);
  }
}

void count_list(linkedList *L, int *c) {
  if (L != NULL) {
    count_list(L->next, ++c);
  }
}

void print_message_list(linkedList *L, int id, char *msg) {
  if (L != NULL) {
    if (L->id == id) {
      strcpy(msg, L->message);
    } else {
      print_message_list(L->next, id, msg);
    }
  }
}
