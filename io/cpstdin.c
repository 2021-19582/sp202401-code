#include "../csapp.h"

ssize_t Read(int fd, void *buf, size_t count) {
    return read(fd, buf, count);
}
ssize_t Write(int fd, const void *buf, size_t count){
    return write(fd, buf, count);
}

int main (int argc, char* argv[]) {
    char c;
    while (Read (STDIN_FILENO, &c, 1) != 0) {
        Write(STDOUT_FILENO, &c, 1);
    }
    exit(0);
}