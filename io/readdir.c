#include "../csapp.h"


DIR *Opendir(const char *name) {
    return opendir(name);
}

void unix_error(char *msg) {
    char *result = malloc(strlen("ERROR: ") + strlen(msg) + 2);
    strcat(result, "ERROR: ");
    strcat(result, msg);
    strcat(result, "\n");
    perror(result);
}

int Closedir(DIR *dirp) {
    return closedir(dirp);
}

int main ( int argc, char **argv ) {
    DIR *streamp;
    struct dirent *dep;

    streamp = Opendir(argv[1]);

    errno = 0;

    while ((dep = readdir(streamp)) != NULL) {
        printf("Found file: %s\n", dep->d_name);
    }
    if (errno != 0) // when no error, errno == 0;
        unix_error("readdir error");

    Closedir(streamp);
    exit(0);
}