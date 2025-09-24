/*
============================================================================================================================================================
Name : 11.c
Author : Aditya Dave
Description: Write a program to open a file, duplicate the file descriptor and append using dup, dup2, and fcntl. Verify updates in the file.
Date: 18th Aug, 2025.
============================================================================================================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int filedesc = open(argv[1], O_RDWR);
    printf("original Value of File descriptor is : %d\n", filedesc);

    int dup_filedesc = dup(filedesc);
    printf("New Value of file descriptor using dup() system call is : %d\n", dup_filedesc);

    int dup2_filedesc = dup2(filedesc, 7);
    printf("New Value of file descriptor using dup2() system call is : %d\n", dup2_filedesc);

    int fcntl_filedesc = fcntl(filedesc, F_DUPFD, 0);
    printf("New Value of file descriptor using fcntl() system call is : %d\n", fcntl_filedesc);

    write(filedesc, "Hello from original FD\n", 23);
    write(dup_filedesc, "Hello from dup FD\n", 19);
    write(dup2_filedesc, "Hello from dup2 FD\n", 20);
    write(fcntl_filedesc, "Hello from fcntl FD\n", 21);

    close(filedesc);
    close(dup_filedesc);
    close(dup2_filedesc);
    close(fcntl_filedesc);

    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que11 % ./11 file.txt
original Value of File descriptor is : 3
New Value of file descriptor using dup() system call is : 4
New Value of file descriptor using dup2() system call is : 7
New Value of file descriptor using fcntl() system call is : 5
*/