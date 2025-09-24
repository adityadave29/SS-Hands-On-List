/*
============================================================================================================================================================
Name : 1.c
Author : Aditya Dave
Description: Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 15th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if (strcmp(argv[1], "softlink") == 0 && symlink(argv[2], argv[3]) != -1) // 0->success, -1->failure
    {
        printf("Files have been soft linked using system call symlink.\n");
    }
    else if (strcmp(argv[1], "hardlink") == 0 && link(argv[2], argv[3]) != -1)
    {
        printf("Files have been hard linked using system call link.\n");
    }
    else if (strcmp(argv[1], "pipeline_mkfifo") == 0 && mkfifo(argv[2], 0666) != -1)
    {
        printf("Pipeline Created Successfully using mkfifo syscall.\n");
    }
    else if (strcmp(argv[1], "pipeline_mknod") == 0 && mknod(argv[2], S_IFIFO | 0666, 0) != -1) // For device files  use mknod().
    {
        printf("Pipeline Created Successfully using mknod syscall.\n");
    }
    return 0;
}

/*

Output:

*Shell Commands:
1 -> ln -s souce_file soft_link (for softlink).
2 -> ln source_file hard_link (for hardlink).
3 -> mkfifo myfifo (for named pipe).
4 -> mknod myfifo p (for named pipe).

adityadave@Adityas-MacBook-Air-3 Que1 % ./1 softlink 1.c e
Files have been soft linked using system call symlink.
adityadave@Adityas-MacBook-Air-3 Que1 % ./1 hardlink 1.c hard_lnk
Files have been hard linked using system call link.
adityadave@Adityas-MacBook-Air-3 Que1 % ./1 pipeline_mkfifo pipe_mkfifo
Pipeline Created Successfully using mkfifo syscall.s
adityadave@Adityas-MacBook-Air-3 Que1 % ./1 pipeline_mknod pipe_mknod
Pipeline Created Successfully using mknod syscall.

check file type using ls -l.
permissions link_count owner group size month day time name
*/