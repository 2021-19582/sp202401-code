#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;
extern void show_bytes (byte_pointer start, size_t len);

int main () {
    const char *m = "mnopqr"; // 6d 6e 6f 70 71 72 // is not affected by endian-ness
    show_bytes ((byte_pointer) m, (size_t) strlen (m));
}