/*
 * Problem statement: Implement a job scheduler that takes in a function f and
 * an integer n and calls f after n milliseconds.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void* f(int n) {
  sleep(n / 1000);

  printf("CALLED WHEN n = %d\n", n);
}

int main() {
  srand(time(NULL));

  pthread_t id;
  int i;

  for (i = 0; i < 10; i++) {
    int random_milliseconds = rand() % 10000;

    pthread_create(&id, NULL, f, (void*) random_milliseconds);
  }

  pthread_exit(NULL);

  return 0;
}
