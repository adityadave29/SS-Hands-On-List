#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd;
    struct
    {
        int ticket_no;
    } database;

    database.ticket_no = 0;

    fd = open("database", O_RDWR | O_CREAT | O_TRUNC, 0644);
    write(fd, &database, sizeof(database));
    close(fd);

    printf("Database initialized with ticket number = 0\n");
    return 0;
}
