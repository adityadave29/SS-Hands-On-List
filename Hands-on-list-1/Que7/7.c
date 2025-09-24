/*
============================================================================================================================================================
Name : 7.c
Author : Aditya Dave
Description: Write a program to copy file1 into file2 ($cp file1 file2).
Date: 17th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char buff[1];
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_WRONLY);
    while (read(fd1, buff, 1) > 0)
    {
        write(fd2, buff, 1);
    }
    printf("Successfully Copied  Content of file %s to file %s\n", argv[1], argv[2]);
    close(fd1);
    close(fd2);
    return 0;
}

/*
// cp file1 file2
Output:
adityadave@Adityas-MacBook-Air-3 Que7 % ./7 main_file.txt copy_file.txt
Successfully Copied  Content of file main_file.txt to file copy_file.txt
*/