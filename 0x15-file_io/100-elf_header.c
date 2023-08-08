#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void exit_with_error(int code, const char *file);

int main(int argc, char *argv[])
{
    int fd_from, fd_to, bytes_read, bytes_written;
    char buffer[1024];

    if (argc != 3)
        exit_with_error(97, "Usage: cp file_from file_to");

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        exit_with_error(98, argv[1]);

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
        exit_with_error(99, argv[2]);

    while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
    {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written == -1)
            exit_with_error(99, argv[2]);
    }

    if (bytes_read == -1)
        exit_with_error(98, argv[1]);

    if (close(fd_from) == -1 || close(fd_to) == -1)
        exit_with_error(100, "");

    return 0;
}

void exit_with_error(int code, const char *file)
{
    if (code == 97 || code == 100)
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
    else if (code == 98)
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
    else if (code == 99)
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);

    exit(code);
}

