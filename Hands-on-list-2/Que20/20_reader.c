#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int fd = open("myfifo_pipe", O_RDONLY);
    char buffer[100];
    read(fd, buffer, sizeof(buffer));
    printf("Received: %s", buffer);
    close(fd);
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que20 % ./20r
Received: I am sending data through myfifo_pipe
*/