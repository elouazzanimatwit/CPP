#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

atomic_int counter = 0;

void* thread_i(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        atomic_fetch_add(&counter, 1);
    }
    return NULL;
}

void* thread_k(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        atomic_fetch_sub(&counter, 1);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread_i, NULL);
    pthread_create(&t2, NULL, thread_k, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("Final Counter: %d\n", counter);
    
    return 0;