/*
============================================================================================================================================================
Name : 17.c
Author : Aditya Dave
Description: Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 18th Aug, 2025.
============================================================================================================================================================
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd;
    struct
    {
        int ticket_no;
    } database;
    database.ticket_no = 0;
    fd = open("database", O_RDWR | O_CREAT | O_EXEC, 0744);
    write(fd, &database, sizeof(database));
    close(fd);
    fd = open("database", O_RDONLY);
    read(fd, &database, sizeof(database));
    printf("Ticket no: %d\n", database.ticket_no);
    close(fd);
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que17 % ./db
Ticket no: 0
*/