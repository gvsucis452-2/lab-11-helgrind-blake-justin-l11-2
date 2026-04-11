#include <stdio.h>

#include "common_threads.h"

int balance = 0;

void *worker(void *arg) {
	(void)arg;
	balance++;
	return NULL;
}

int main(int argc, char *argv[]) {
	(void)argc;
	(void)argv;
	pthread_t p;

	Pthread_create(&p, NULL, worker, NULL);
	balance++;
	Pthread_join(p, NULL);
	return 0;
}
