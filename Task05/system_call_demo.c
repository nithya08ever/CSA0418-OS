#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    char buffer[100];

    int fd = open("sample.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    ssize_t bytes = read(fd, buffer, sizeof(buffer) - 1);

    if (bytes == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[bytes] = '\0';

    printf("File content: %s\n", buffer);

    close(fd);

    return 0;
}