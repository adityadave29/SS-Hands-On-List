#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int pline;
    pline = mkfifo(argv[1], 0644);
    printf("Pipeline Created Successfully\n");
}
