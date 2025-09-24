/*
============================================================================================================================================================
Name : 8.c
Author : Aditya Dave
Description: Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.
Date: 17th Aug, 2025.
============================================================================================================================================================
*/
// changed
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    char buff[256];
    char line[1024];
    int n, i, line_index = 0;

    while ((n = read(fd, buff, sizeof(buff))) > 0)
    {
        for (i = 0; i < n; i++)
        {
            line[line_index++] = buff[i];

            if (buff[i] == '\n' || line_index == sizeof(line) - 1)
            {
                write(1, line, line_index);
                line_index = 0;
            }
        }
    }

    if (line_index > 0)
        write(1, line, line_index);

    close(fd);
    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que8 % ./8 read_file.txt
Reading Line 1
Reading Line 2
Reading Line 3
Reading Line 4
Ending.
*/