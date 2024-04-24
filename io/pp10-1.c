#include "../csapp.h"

int Open(const char *pathname, int flags, mode_t mode) {
    return open(pathname, flags, mode); // returns new fd if OK, -1 on err
}
void Close(int fd) {
    close(fd);
    return;
}

int main()
{
    int fd1, fd2;

    fd1 = Open("foo.txt", O_RDONLY, 0);
    Close(fd1);
    fd2 = Open("baz.txt", O_RDONLY, 0);
    printf("fd2 = %d\n", fd2);
    exit(0);
}