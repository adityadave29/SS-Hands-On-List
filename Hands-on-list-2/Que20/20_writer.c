#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("myfifo_pipe", O_WRONLY);
    char message[] = "I am sending data through myfifo_pipe\n";
    write(fd, message, sizeof(message));
    close(fd);
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que20 % ./20w
*/