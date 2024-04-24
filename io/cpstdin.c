#include "../csapp.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

ssize_t Read(int fd, void *buf, size_t count) {
    return read(fd, buf, count);
}
ssize_t Write(int fd, const void *buf, size_t count){
    return write(fd, buf, count);
}

int main (int argc, char* argv[]) {
    // cpstdin
    char c;
    while (Read (STDIN_FILENO, &c, 1) != 0) {
        Write(STDOUT_FILENO, &c, 1);
    }

    // myDummy
    // const char * text = "hi, my name is Amy\n";
    // int dummy_fd = open ("dummy.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR);
    // write(dummy_fd, text, strlen(text));
    // close(dummy_fd);

    exit(0);
}