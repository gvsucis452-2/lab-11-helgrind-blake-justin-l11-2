#include <stdio.h>

#include "common_threads.h"

int balance = 0;
int lock = 0;

void spinlock_acquire(int *lock) {
    //I have lock keep lock.
    while (*lock ==1 ) { *lock = 1; } 
}
//release lock by setting it to 0
void spinlock_release(int *lock) { *lock = 0; }
void* worker(void* arg) {
    spinlock_acquire(&lock);
    balance++; // protected access
    spinlock_release(&lock);  
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p;
    Pthread_create(&p, NULL, worker, NULL);
    spinlock_acquire(&lock);
    balance++; // protected access
    spinlock_release(&lock);   
    Pthread_join(p, NULL);
    return 0;
}
