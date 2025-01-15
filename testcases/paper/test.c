
#include <stdlib.h>

#define SZ 100

int* mem_alloc(unsigned sz)
{
    int *buf = (int *)malloc(sizeof(int) * sz);
    return buf;
}

void set_mem(int *ar, int x)
{
    ar[0] = x;
    ar[x] = 0;
}

void baz(int arg)
{
    int *buf = mem_alloc(SZ);
    set_mem(buf, 1);
    int t1 = buf[0];
    int t2 = buf[1];
    buf[t1-1] = 0;
    buf[t2-1] = 0;
}