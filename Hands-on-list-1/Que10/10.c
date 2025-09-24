/*
============================================================================================================================================================
Name : 10.c
Author : Aditya Dave
Description: Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek), and write again 10 bytes. Verify using od.
Date: 17th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("lseek.txt", O_RDWR);

    char first_10_bytes[10] = "ADITYADAVE";
    char next_10_bytes[10] = "DAVEADITYA";

    off_t pos0 = lseek(fd, 0, SEEK_CUR);
    printf("Lseek position : %lld\n", pos0);

    write(fd, first_10_bytes, 10);

    off_t pos1 = lseek(fd, 10, SEEK_CUR);
    // off_t pos = lseek(fd, 10, SEEK_SET); for starting

    printf("Lseek position : %lld\n", pos1);

    write(fd, next_10_bytes, 10);

    off_t pos2 = lseek(fd, 0, SEEK_CUR);
    printf("Lseek position : %lld\n", pos2);

    printf("File content of lseek.txt: \n");
    int fd2 = open("lseek.txt", O_RDONLY);
    char buff[1];
    while (read(fd2, buff, 1) > 0)
    {
        write(1, buff, 1);
    }
    printf("\n");
    close(fd2);
    close(fd);
    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que10 % ./10
Lseek position : 0
Lseek position : 20
Lseek position : 30
File content of lseek.txt:
ADITYADAVE          DAVEADITYA
// od -c lseek.txt
adityadave@Adityas-MacBook-Air-3 Que10 % od -c lseek.txt

0000000    A   D   I   T   Y   A   D   A   V   E  \0  \0  \0  \0  \0  \0
0000020   \0  \0  \0  \0   D   A   V   E   A   D   I   T   Y   A
0000036
*/