/*
============================================================================================================================================================
Name : 26.c
Author : Aditya Dave
Description: Write a program to execute an executable program. Pass input arguments if needed (example: ./a.out name).
Date: 29th Aug, 2025.
============================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Question 26: Trying command execl to execute another program\n");
    execl("./multiply", "multiply", argv[1], argv[2], NULL);
    printf("Am I printed?\n");
    return 0;
}

/*
Output:
adityadave@Adityas-MacBook-Air-3 Que26 % ./26 3 4
Question 26: Trying command execl to execute another program
3 X 4 = 12
*/
