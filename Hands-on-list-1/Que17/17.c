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
    struct
    {
        int ticket_no;
    } database;

    struct flock lock;
    int fd = open("database", O_RDWR);

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("This line is executed before entering into critical section\n");
    fcntl(fd, F_SETLKW, &lock);

    printf("We are currently in critical section\n");

    lseek(fd, 0, SEEK_SET);
    read(fd, &database, sizeof(database));
    printf("Ticket number as of now :%d\n", database.ticket_no);

    database.ticket_no++;

    lseek(fd, 0, SEEK_SET);
    write(fd, &database, sizeof(database));
    fsync(fd);

    printf("New ticket number written: %d\n", database.ticket_no);

    printf("Press Enter to release the lock\n");
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("We are out of critical section.\n");

    close(fd);
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que17 % ./inc
Before entering into critical section
Inside the critical section
Current ticket number: 1
New ticket number written: 2
Press Enter to unlock...

Exited critical section
*/