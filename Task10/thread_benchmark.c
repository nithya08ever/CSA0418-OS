#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define COUNT 1000

void *worker(void *arg) {
    return NULL;
}

int main(void) {
    pthread_t threads[COUNT];

    for (int i = 0; i < COUNT; i++) {
        int result = pthread_create(&threads[i], NULL, worker, NULL);

        if (result != 0) {
            printf("Thread creation failed at %d\n", i);
            return 1;
        }
    }

    for (int i = 0; i < COUNT; i++)
        pthread_join(threads[i], NULL);

    printf("Created and completed %d threads\n", COUNT);
    return 0;
}