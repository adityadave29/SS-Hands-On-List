/*
============================================================================================================================================================
Name : 14.c
Author : Aditya Dave
Description: Write a program to find the type of a file. Input should be from command line. Program should identify any type of file.
Date: 18th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct stat file_type;
    stat(argv[1], &file_type);
    if (S_ISREG(file_type.st_mode))
        printf("File %s is regular file.\n", argv[1]);
    else if (S_ISDIR(file_type.st_mode))
        printf("File %s is directory.\n", argv[1]);
    else if (S_ISCHR(file_type.st_mode))
        printf("File %s is character device.\n", argv[1]);
    else if (S_ISBLK(file_type.st_mode))
        printf("File %s is block file.\n", argv[1]);
    else if (S_ISFIFO(file_type.st_mode))
        printf("File %s is fifo pipeline file.\n", argv[1]);
    else if (S_ISLNK(file_type.st_mode))
        printf("File %s is symbolic link.\n", argv[1]);
    else if (S_ISSOCK(file_type.st_mode))
        printf("File %s is socket file.\n", argv[1]);
    else
        printf("%s is of unknown type.\n", argv[1]);
    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que14 % ./14 myfifo
File myfifo is fifo pipeline file.
*/