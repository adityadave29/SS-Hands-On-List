/*
============================================================================================================================================================
Name : 2.c
Author : Aditya Dave
Description: Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 15th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    do
    {

    } while (1);
    return 0;
}

/*

Output:

instead of proc use "top -pid <PID>"
instead of proc use "lsof -p <PID>"

PID   COMMAND      %CPU  TIME     #TH  #WQ  #POR MEM  PURG CMPRS PGRP PPID STATE   BOOSTS    %CPU_ME
3742  2            100.4 00:23.58 1/1  0    11   753K 0B   496K  3742 2579 running *0[1]     0.00000

adityadave@Adityas-MacBook-Air-3 Que2 % lsof -p 6924
COMMAND  PID       USER   FD   TYPE DEVICE SIZE/OFF                NODE NAME
2       6924 adityadave  cwd    DIR   1,14      128            49553897 /Users/adityadave/IIITB/SEM1/SS/HandsOn1/Que2
2       6924 adityadave  txt    REG   1,14    16832            52143324 /Users/adityadave/IIITB/SEM1/SS/HandsOn1/Que2/2
2       6924 adityadave  txt    REG   1,14  2289328 1152921500312524246 /usr/lib/dyld
2       6924 adityadave    0u   CHR   16,3   0t6699                 735 /dev/ttys003
2       6924 adityadave    1u   CHR   16,3   0t6699                 735 /dev/ttys003
2       6924 adityadave    2u   CHR   16,3   0t6699                 735 /dev/ttys003
*/
