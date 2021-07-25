#include "../server/server.h"

#ifndef CLIENT_H
#define CLIENT_H

void connect(int *writefd, int *readfd);
void get_menu(char *menu, int writefd, int readfd);
void do_while(char *menu, int writefd, int readfd);
void send_option(int *option, char *menu, int writefd, int readfd);
void parse_output(char *output, int writefd, int readfd);
void read_file(char *msg, int writefd, int readfd);

#endif
