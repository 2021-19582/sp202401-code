#include "../../csapp.h"

static char *mem_heap;
static char *mem_brk;
static char *mem_max_addr;

#define MAX_HEAP 15213

void *Malloc(size_t size) {
    return malloc(size);
}

void mem_init (void) {
    mem_heap = (char *)Malloc (MAX_HEAP);
    mem_brk = (char *)mem_heap;
    mem_max_addr = (char *)(mem_heap + MAX_HEAP);
}

void *mem_sbrk(int incr) {
    char *old_brk = mem_brk;

    if ((incr < 0) || ((mem_brk + incr) > mem_max_addr)) {
        errno = ENOMEM;
        fprintf(stderr, "ERROR: mem_sbrk failed. Ran out of memory...\n");
        return (void *)-1;
    }
    mem_brk += incr;
    return (void *)old_brk;
}

// int main()
// {
//     int *array, i, n;

//     scanf("%d", &n);
//     array = (int *)Malloc(n * sizeof(int));

//     for (i = 0; i < n; i++)
//         scanf("%d", &array[i]);
//     free(array);
//     exit(0);
// }