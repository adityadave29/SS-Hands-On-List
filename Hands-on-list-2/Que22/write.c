#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd = open("pipe", O_WRONLY);
    char *message = "Hello from writer process!";
    write(fd, message, strlen(message));
    close(fd);
    return 0;
}