#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/select.h>
#include <string.h>

int main()
{
    char buffer[100];
    int fd = open("pipe", O_RDONLY | O_NONBLOCK);

    fd_set readfds;
    struct timeval timeout;

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for data in FIFO for 10 seconds...\n");

    int ret = select(fd + 1, &readfds, NULL, NULL, &timeout);

    if (ret == 0)
    {
        printf("Timeout: No data written in 10 seconds.\n");
    }
    else
    {
        if (FD_ISSET(fd, &readfds))
        {
            int n = read(fd, buffer, sizeof(buffer));
            buffer[n] = '\0';
            printf("Received: %s\n", buffer);
        }
    }

    close(fd);
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que22 % ./22
Waiting for data in FIFO for 10 seconds...
Received: Hello from writer process!
*/