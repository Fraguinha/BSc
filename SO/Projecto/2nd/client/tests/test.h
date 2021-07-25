#include <assert.h>

#include "../../server/server.h"
#include "../client.h"

#ifndef TESTCLIENT_H
#define TESTCLIENT_H

#define NUM_TESTS 10

void test(void *f(void *), int n);

void *insert_messages_test(void *args);
void *delete_messages_test(void *args);
void *create_queue_test(void *args);

#endif
