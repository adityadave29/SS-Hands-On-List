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
    int fd;
    struct Course db[3];

    for (int i = 0; i < 3; i++)
    {
        db[i].course = i + 1;
        db[i].number_of_students = 0;
    }

    fd = open("record.txt", O_RDWR | O_CREAT | O_TRUNC, 0744);
    write(fd, db, sizeof(db));
    close(fd);
    printf("Database initialized with 3 courses.\n");
    return 0;
}
