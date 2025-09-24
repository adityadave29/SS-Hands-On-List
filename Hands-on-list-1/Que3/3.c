/*
============================================================================================================================================================
Name : 3.c
Author : Aditya Dave
Description: Write a program to create a file and print the file descriptor value. Use creat() system call.
Date: 15th Aug, 2025.
============================================================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int filedesc;
    filedesc = creat(argv[1], 0644);
    printf("File descriptor for generated file %s is : %d\n", argv[1], filedesc);
    close(filedesc);
    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que3 % ./3 new_file.txt
File descriptor for generated file new_file.txt is : 3
*/

/*
0 - for input
1 - for output
2 - for erro
*/