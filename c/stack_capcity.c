// test stack capacity size
#include <stdio.h>
#include <pthread.h>

int i = 0;

void *test(void * s)
{
    int buffer[1024];

    printf("i=%d\n",   i);
    i++;

   buffer[0]=i;
    test(s);
}

int main()
{
    pthread_t p;

    pthread_create(&p, NULL, &test, NULL);
    sleep(100);
    return 0;
}
