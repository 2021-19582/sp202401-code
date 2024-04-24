#include "../csapp.h"

int Open(const char *pathname, int flags, mode_t mode) {
    return open(pathname, flags, mode);
}

void Close(int fd) {
    close(fd);
    return;
}

int main()
{
    int fd1, fd2;

    fd1 = Open("foo.txt", O_RDONLY, 0);
    printf("fd1 foo = %d\n", fd1);
    fd2 = Open("bar.txt", O_RDONLY, 0);
    printf("fd2 bar = %d\n", fd2);
    Close(fd2);
    fd2 = Open("baz.txt", O_RDONLY, 0);
    printf("fd2 baz = %d\n", fd2);
    exit(0);
}