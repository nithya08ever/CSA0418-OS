#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid;
    int status;

    printf("shell: running job 1\n");
    fflush(stdout);

    pid = fork();

    if (pid == 0) {
        execlp("expr", "expr", "6", "*", "7", (char *)NULL);
        perror("execlp");
        _exit(127);
    }

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    waitpid(pid, &status, 0);

    if (WIFEXITED(status))
        printf("job 1 exit status %d\n", WEXITSTATUS(status));

    printf("shell: running job 2\n");
    

    pid = fork();

    if (pid == 0)
        exit(3);

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    waitpid(pid, &status, 0);

    if (WIFEXITED(status))
        printf("job 2 exit status %d\n", WEXITSTATUS(status));

    return 0;
}