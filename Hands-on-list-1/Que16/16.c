/*
============================================================================================================================================================
Name : 16.c
Author : Aditya Dave
Description:Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
Date: 18th Aug, 2025.
============================================================================================================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (strcmp(argv[1], "read_lock") == 0)
    {
        int fd = open(argv[2], O_RDONLY);
        struct flock fl = {0};
        fl.l_type = F_RDLCK;
        fl.l_whence = SEEK_SET;
        fl.l_start = 0;
        fl.l_len = 0;

        fcntl(fd, F_SETLKW, &fl);

        puts("Read lock is active if you want to release lock just press any key.");
        getchar();

        fl.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &fl);
        close(fd);
    }
    else if (strcmp(argv[1], "write_lock") == 0)
    {
        int fd = open(argv[2], O_RDWR);
        struct flock file_lock = {0};
        file_lock.l_type = F_WRLCK;
        file_lock.l_whence = SEEK_SET;
        file_lock.l_start = 0;
        file_lock.l_len = 0;

        fcntl(fd, F_SETLKW, &file_lock);

        puts("Write lock is active if you want to release lock just press any key.");
        getchar();

        file_lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &file_lock);
        close(fd);
    }
    return 0;
}

/*
Output:
Terminal 1:
adityadave@Adityas-MacBook-Air-3 Que16 % ./16 write_lock lockdemo.txt
Write lock held. Press Enter to unlock...
Terminal 2:
adityadave@Adityas-MacBook-Air-3 Que16 %  ./16 write_lock lockdemo.txt

*/