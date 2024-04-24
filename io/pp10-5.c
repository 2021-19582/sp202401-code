#include "../csapp.h"

int Open(const char *pathname, int flags, mode_t mode) {
    return open(pathname, flags, mode);
}

ssize_t Read(int fd, void *buf, size_t count) {
    return read(fd, buf, count);
}

int Dup2(int fd1, int fd2) {
    return dup2 (fd1, fd2);
}

int main() {
    int fd1, fd2;
    char c;

    fd1 = Open ("foobar.txt", O_RDONLY, 0);
    fd2 = Open ("foobar.txt", O_RDONLY, 0);
    Read(fd2, &c, 1);
    Dup2(fd2, fd1);
    Read(fd1, &c, 1);
    printf("c = %c\n", c);
    exit(0);
}