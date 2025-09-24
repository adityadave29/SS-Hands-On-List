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
        int fd1 = open("pipe1", O_RDONLY);
        read(fd1, buffer, sizeof(buffer));
        close(fd1);

        printf("Process A: %s\n", buffer);
        if (strncmp(buffer, "exit", 4) == 0)
            break;
        printf("Process B: Enter reply: ");
        fgets(buffer, sizeof(buffer), stdin);

        int fd2 = open("pipe2", O_WRONLY);
        write(fd2, buffer, strlen(buffer) + 1);
        close(fd2);

        if (strncmp(buffer, "exit", 4) == 0)
            break;
    }

    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que21 % ./21b
Process A: Hello I am Process A

Process B: Enter reply: I am Process B
Process A: How to implement FIFO in bi-direction?

Process B: Enter reply: I'dont know bye.
Process A: exit
*/