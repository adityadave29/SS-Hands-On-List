/*
============================================================================================================================================================
Name : 6.c
Author : Aditya Dave
Description: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 17th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char buff[99];
    int count = read(0, buff, 99);
    write(1, buff, count);
    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que6 % ./6
Hello, I am testing question 6
Hello, I am testing question 6
*/