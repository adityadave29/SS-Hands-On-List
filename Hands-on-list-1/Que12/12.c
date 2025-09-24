/*
============================================================================================================================================================
Name : 12.c
Author : Aditya Dave
Description: Write a program to find out the opening mode of a file using fcntl.
Date: 18th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);

    int flag = fcntl(fd, F_GETFL);
    printf("Original flags: %d\n", flag);

    int check = flag & O_ACCMODE;
    if (check == 0)
        printf("Current Mode is Read Only Mode\n");
    else if (check == 1)
        printf("Current Mode is Write Only Mode\n");
    else if (check == 2)
        printf("Current Mode is Read Write Mode\n");
    close(fd);
    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que12 % ./12 file.txt
Original flags: 0
Current Mode is Read Only Mode
*/