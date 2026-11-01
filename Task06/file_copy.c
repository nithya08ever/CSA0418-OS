#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define FILE_SIZE 10000

int copy_file(const char *source, const char *destination,
              size_t buffer_size) {
    char buf[8192];
    int src, dest;
    int read_calls = 0;

    if (buffer_size == 0 || buffer_size > sizeof(buf)) {
        fprintf(stderr, "Invalid buffer size\n");
        return -1;
    }

    src = open(source, O_RDONLY);
    if (src == -1) {
        perror("open source");
        return -1;
    }

    dest = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest == -1) {
        perror("open destination");
        close(src);
        return -1;
    }

    while (1) {
        ssize_t bytes_read = read(src, buf, buffer_size);
        read_calls++;

        if (bytes_read == 0)
            break;

        if (bytes_read == -1) {
            if (errno == EINTR)
                continue;
            perror("read");
            close(src);
            close(dest);
            return -1;
        }

        ssize_t total_written = 0;

        while (total_written < bytes_read) {
            ssize_t bytes_written =
                write(dest, buf + total_written,
                      bytes_read - total_written);

            if (bytes_written == -1) {
                if (errno == EINTR)
                    continue;
                perror("write");
                close(src);
                close(dest);
                return -1;
            }

            total_written += bytes_written;
        }
    }

    close(src);
    close(dest);

    return read_calls;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <buffer_size>\n", argv[0]);
        return 1;
    }

    size_t buffer_size = (size_t)atoi(argv[1]);

    if (buffer_size == 0 || buffer_size > 8192) {
        printf("Buffer size must be between 1 and 8192\n");
        return 1;
    }

    int fd = open("source.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("create source");
        return 1;
    }

    char data[FILE_SIZE];
    memset(data, 'A', sizeof(data));

    if (write(fd, data, sizeof(data)) != sizeof(data)) {
        perror("write source");
        close(fd);
        return 1;
    }

    close(fd);

    char destination[64];
    snprintf(destination, sizeof(destination),
             "copy_%zu.txt", buffer_size);

    int calls = copy_file("source.txt", destination, buffer_size);

    if (calls == -1)
        return 1;

    printf("Buffer size: %zu bytes\n", buffer_size);
    printf("File size: %d bytes\n", FILE_SIZE);
    printf("Read system calls in copy_file: %d\n", calls);
    printf("Copied successfully to %s\n", destination);

    return 0;
}