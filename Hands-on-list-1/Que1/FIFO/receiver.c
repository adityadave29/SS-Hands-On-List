#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int response, n;
    char buffer[100];
    response = open("pipeline", O_RDONLY);
    n = read(response, buffer, 100);
    printf("Data received by receiver process with pid %d \n The message is: %s\n", getpid(), buffer);
}