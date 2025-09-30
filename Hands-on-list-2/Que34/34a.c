/*
============================================================================================================================================================
Name : 34a.c
Author : Aditya Dave
Description: Write a program to create a concurrent server using fork.
Date: 30th sep 2025
============================================================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

void handle_client(int client_sock)
{
    char buffer[1024];
    int n;
    while ((n = read(client_sock, buffer, 1024)) > 0)
    {
        write(client_sock, buffer, n);
    }
    close(client_sock);
}

int main()
{
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_sock, 5);

    while (1)
    {
        int client_sock = accept(server_sock, NULL, NULL);
        if (fork() == 0)
        {
            close(server_sock);
            handle_client(client_sock);
            return 0;
        }
        close(client_sock);
    }
}

/*

adityadave@Adityas-MacBook-Air-3 Que34 % ./34a

adityadave@Adityas-MacBook-Air-3 Que34 % ps -ef | grep 34a

  501  6338  3833   0 12:07AM ttys005    0:00.01 ./34a
  501  6691  6338   0 12:09AM ttys005    0:00.00 ./34a
  501  7042  6696   0 12:09AM ttys007    0:00.00 grep 34a
adityadave@Adityas-MacBook-Air-3 Que34 % ps -ef | grep 34a

  501  6338  3833   0 12:07AM ttys005    0:00.01 ./34a
  501  7070  6696   0 12:11AM ttys007    0:00.00 grep 34a


adityadave@Adityas-MacBook-Air-3 Que34 % nc localhost 8080

Hello
Hello


Hello
Hello
How are you?
How are you?
*/