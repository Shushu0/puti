#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("open.log", O_CREAT);
    write(fd, "Hello", 6);
    return  0;
}
