#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4 // Number of threads

typedef struct {
    int* arr;
    int start;
    int end;
    int sum;
} ThreadData;

void* thread_sum(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    data->sum = 0;
    for (int i = data->start; i < data->end; i++) {
        data->sum += data->arr[i];
    }
    return NULL;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 25}; // Sample data
    int size = sizeof(arr) / sizeof(arr[0]);
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    int segment_size = size / NUM_THREADS;

    // Measure execution time
    clock_t start = clock();

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].arr = arr;
        thread_data[i].start = i * segment_size;
        thread_data[i].end = (i == NUM_THREADS - 1) ? size : (i + 1) * segment_size;
        pthread_create(&threads[i], NULL, thread_sum, &thread_data[i]);
        pthread_join(threads[i], NULL);
    }

    // Wait for threads to complete and combine results
    int total = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        //
        total += thread_data[i].sum;
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Multi-threaded sum: %d\n", total);
    printf("Execution time: %f seconds\n", time_spent);

    return 0;
}
