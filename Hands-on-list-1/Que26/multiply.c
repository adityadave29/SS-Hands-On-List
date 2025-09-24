#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int number1 = atoi(argv[1]);
    int number2 = atoi(argv[2]);
    int result = number1 * number2;
    printf("%d X %d = %d\n", number1, number2, result);
    return 0;
}