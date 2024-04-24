#include "../csapp.h"

int Open(const char *pathname, int flags, mode_t mode) {
    return open(pathname, flags, mode);
}

ssize_t Read(int fd, void *buf, size_t count) {
    return read(fd, buf, count);
}

pid_t Fork(void) {
    return fork();
}
pid_t Wait(int *status) {
    return wait(status);
}
int main() {
    int fd;
    char c;

    fd = Open("foobar.txt", O_RDONLY, 0);
    if (Fork() == 0) {
        Read (fd, &c, 1);
        exit(0);
    }
    Wait (NULL);
    Read(fd, &c, 1);
    printf("c = %c\n", c);
    exit(0);
}