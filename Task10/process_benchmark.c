#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define COUNT 1000

int main(void) {
    for (int i = 0; i < COUNT; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            return 1;
        }

        if (pid == 0)
            _exit(0);
    }

    for (int i = 0; i < COUNT; i++) {
        if (wait(NULL) == -1) {
            perror("wait");
            return 1;
        }
    }

    printf("Created and completed %d child processes\n", COUNT);
    return 0;
}