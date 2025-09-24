/*
============================================================================================================================================================
Name : 9.c
Author : Aditya Dave
Description: Write a program to print the following information about a given file: inode, hard links, uid, gid, size, block size, blocks, last access, last modification, last change.
Date: 17th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct stat file_stat_q9;
    stat(argv[1], &file_stat_q9);

    printf("Inode of file %s is: %ld\n", argv[1], file_stat_q9.st_ino);
    printf("Number of hard link file %s have is : %ld\n", argv[1], file_stat_q9.st_nlink);
    printf("User Id of file %s is : %d\n", argv[1], file_stat_q9.st_uid);
    printf("Group Id of file %s is : %d\n", argv[1], file_stat_q9.st_gid);
    printf("Size of the file %s is : %ld bytes\n", argv[1], file_stat_q9.st_size);
    printf("Block size of the file %s is : %lld\n", argv[1], file_stat_q9.st_blksize);
    printf("No of Blocks of the file %s is : %lld\n", argv[1], file_stat_q9.st_blocks);
    printf("\n");
    printf("Last access happeneded on file %s : %s\n", argv[1], ctime(&file_stat_q9.st_atime));
    printf("Last modification done on file %s : %s\n", argv[1], ctime(&file_stat_q9.st_mtime));
    printf("Last change happeneded on file %s : %s\n", argv[1], ctime(&file_stat_q9.st_ctime));
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que9 % ./9 file.txt
Inode of file file.txt is: 49632556
Number of hard link file file.txt have is : 3
User Id of file file.txt is : 501
Group Id of file file.txt is : 20
Size of the file file.txt is : 5 bytes
Block size of the file file.txt is : 4096
No of Blocks of the file file.txt is : 8

Last access happeneded on file file.txt : Mon Aug 18 22:59:13 2025
Last modification done on file file.txt : Sat Aug 16 18:50:18 2025

Last change happeneded on file file.txt : Mon Aug 18 22:59:13 2025
*/