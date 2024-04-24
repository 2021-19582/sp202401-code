#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes (byte_pointer start, size_t len) {
    int i;
    // printf("%ld", len);
    for (i = 0; i < len; i++) 
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer (void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes (int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;

    show_int (ival); // 21 43 65 07
    show_float (fval); // 64 a8 ec 4c
    show_pointer (pval); // 88 34 cf 94 fc 7f 00 00
}

// int main () {
//     test_show_bytes (1 *(16 * 16 * 16 * 16 * 16 * 16 * 7 + 16 * 16 * 16 * 16 * 16 * 6 + 16 * 16 * 16 * 16 * 5 + 16 * 16 * 16 * 4 + 16 * 16 * 3 + 16 * 2 + 1)); // 0x7654321
// //      21 43 65 07
// //      64 a8 ec 4c
// //      c8 f1 9c 4a fc 7f 00 00
//     test_show_bytes (12345); // 12345
//         // 39 30 00 00
//         // 00 e4 40 46
//         // c8 f1 9c 4a fc 7f 00 00
// }