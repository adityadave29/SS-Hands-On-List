#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char buffer[100];
    while (1)
    {
        printf("Process A: Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);

        int fd1 = open("pipe1", O_WRONLY);
        write(fd1, buffer, strlen(buffer) + 1);
        close(fd1);

        if (strncmp(buffer, "exit", 4) == 0)
            break;

        int fd2 = open("pipe2", O_RDONLY);
        read(fd2, buffer, sizeof(buffer));
        close(fd2);

        printf("Process B: %s\n", buffer);
    }

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que21 % ./21a
Process A: Enter message: Hello I am Process A
Process B: I am Process B

Process A: Enter message: How to implement FIFO in bi-direction?
Process B: I'dont know bye.

Process A: Enter message: exit
*/