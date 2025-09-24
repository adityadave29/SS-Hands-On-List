#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char* argv[]){
    int response,n;
    response = open("pipeline",O_WRONLY);
    write(response,argv[1],7);
    printf("Sender with PID %d sent data",getpid());
}