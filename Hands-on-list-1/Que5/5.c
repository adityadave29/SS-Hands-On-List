/*
============================================================================================================================================================
Name : 5.c
Author : Aditya Dave
Description: Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 15th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int filedesc[5];
    const char *files[] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};
    for (int i = 0; i < 5; i++)
    {
        filedesc[i] = creat(files[i], 0644);
        printf("Created %s with the file descriptor value of : %d\n", files[i], filedesc[i]);
    }
    while (1)
        ;
    close(filedesc[0]);
    close(filedesc[1]);
    close(filedesc[2]);
    close(filedesc[3]);
    close(filedesc[4]);
    return 0;
}

// lsof -p <PID> to check file descriptor

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que5 % ./5
Created file1.txt with the file descriptor value of : 3
Created file2.txt with the file descriptor value of : 4
Created file3.txt with the file descriptor value of : 5
Created file4.txt with the file descriptor value of : 6
Created file5.txt with the file descriptor value of : 7

adityadave@Adityas-MacBook-Air-3 Que5 % lsof -p 3010
COMMAND  PID       USER   FD   TYPE DEVICE SIZE/OFF                NODE NAME
5       3010 adityadave  cwd    DIR   1,15      288            49576076 /Users/adityadave/IIITB/SEM1/SS/HandsOn1/Que5
5       3010 adityadave  txt    REG   1,15    33504            53698706 /Users/adityadave/IIITB/SEM1/SS/HandsOn1/Que5/5
5       3010 adityadave  txt    REG   1,15  2289328 1152921500312524573 /usr/lib/dyld
5       3010 adityadave    0u   CHR   16,1    0t788                 721 /dev/ttys001
5       3010 adityadave    1u   CHR   16,1    0t788                 721 /dev/ttys001
5       3010 adityadave    2u   CHR   16,1    0t788                 721 /dev/ttys001
5       3010 adityadave    3w   REG   1,15        0            49577943 /Users/adityadave/IIITB/SEM1/SS/HandsOn1/Que5/file1.txt
5       3010 adityadave    4w   REG   1,15        0            49577944 /Users/adityadave/IIITB/SEM1/SS/HandsOn1/Que5/file2.txt
5       3010 adityadave    5w   REG   1,15        0            49577945 /Users/adityadave/IIITB/SEM1/SS/HandsOn1/Que5/file3.txt
5       3010 adityadave    6w   REG   1,15        0            49577946 /Users/adityadave/IIITB/SEM1/SS/HandsOn1/Que5/file4.txt
5       3010 adityadave    7w   REG   1,15        0            49577947 /Users/adityadave/IIITB/SEM1/SS/HandsOn1/Que5/file5.txt
*/