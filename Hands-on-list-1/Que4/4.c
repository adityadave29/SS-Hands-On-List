/*
============================================================================================================================================================
Name : 4.c
Author : Aditya Dave
Description: Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 15th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int filedesc;
    filedesc = open(argv[1], O_RDWR, 0644);
    printf("File descriptor for given opened file is: %d\n", filedesc);
    close(filedesc);

    filedesc = open(argv[1], O_RDWR | O_CREAT | O_EXCL, 0644);
    printf("File descriptor for given opened file with O_EXCL is : %d\n", filedesc);
    close(filedesc);

    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que4 % ./4 file2.txt
File descriptor for given opened file is: -1
File descriptor for given opened file with O_EXCL is : 3
adityadave@Adityas-MacBook-Air-3 Que4 % ./4 file2.txt
File descriptor for given opened file is: 3
File descriptor for given opened file with O_EXCL is : -1
*/