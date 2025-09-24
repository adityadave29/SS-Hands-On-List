/*
============================================================================================================================================================
Name : 22.c
Author : Aditya Dave
Description: Write a program, open a file, call fork, and then write to the file by both child and parent processes. Check the output of the file.
Date: 29th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    int file_desc;
    file_desc = open("output_file.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    char child_buffer[99] = "This sentence is written by child process.\n";
    char parent_buffer[99] = "This sentence is written by parent process.\n";

    pid_t q;
    q = fork();

    if (q == 0)
    {
        write(file_desc, child_buffer, strlen(child_buffer));
        printf("Successfully Written by child process on file 'output_file.txt'\n");
    }
    else
    {
        write(file_desc, parent_buffer, strlen(parent_buffer));
        printf("Successfully Written by parent process on file 'output_file.txt'\n");
    }

    close(file_desc);
    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que22 % ./22
Successfully Written by parent process on file 'output_file.txt'
Successfully Written by child process on file 'output_file.txt'
*/