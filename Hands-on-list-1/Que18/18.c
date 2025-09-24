/*
============================================================================================================================================================
Name : 17.c
Author : Aditya Dave
Description: Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 18th Aug, 2025.
============================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

struct Course
{
    int course;
    int number_of_students;
};

int main()
{
    int fd, input;
    struct Course db;
    struct flock lock;

    fd = open("record.txt", O_RDWR);

    printf("Enter course number (1-3) to increment student count: ");
    scanf("%d", &input);

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (input - 1) * sizeof(db);
    lock.l_len = sizeof(db);
    lock.l_pid = getpid();

    lseek(fd, (input - 1) * sizeof(db), SEEK_SET);
    read(fd, &db, sizeof(db));

    printf("Before entering critical section...\n");

    fcntl(fd, F_SETLKW, &lock);

    printf("Current student count for course %d: %d\n", db.course, db.number_of_students);

    db.number_of_students++;

    lseek(fd, (input - 1) * sizeof(db), SEEK_SET);
    write(fd, &db, sizeof(db));

    printf("To confirm booking, press Enter...\n");
    getchar();
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Ticket booked for course %d, total students: %d\n", db.course, db.number_of_students);

    close(fd);
    return 0;
}

/*
Output:
./18
Enter course number (1-3) to increment student count: 2
Before entering critical section...
Current student count for course 2: 3
To confirm booking, press Enter...

Ticket booked for course 2, total students: 4
*/