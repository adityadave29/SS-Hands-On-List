#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{

    const char *fifo_name = "fifo_pipe";
    mkfifo(fifo_name, 0666);
    printf("FIFO named pipe created: %s\n", fifo_name);

    const char *mknod_name = "mknod_pipe";
    mknod(mknod_name, S_IFIFO | 0666, 0);
    printf("FIFO named pipe created using mknod: %s\n", mknod_name);
    return 0;
}

/*
adityadave@Adityas-MacBook-Air-3 Que19 % ./a.out
FIFO named pipe created: fifo_pipe
FIFO named pipe created using mknod: mknod_pipe
*/

/*
Under the hood mkfifo is implemented using mknod system call. It's is just a wrapper around mknod to make it easier to create named pipes.
So mkfifo is better to use as it is more readable and easier to understand.
*/