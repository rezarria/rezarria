#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* a = calloc(2llu, sizeof(int));
    a[0] = 1;
    a[1] = 2;
    printf("0x%08x\n", a);
    a = realloc(a, sizeof(int));
    printf("0x%08x\n", a);
    printf("%d\n", a[1]);
    free(a);
    printf("0x%08x\n", a);
    printf("%d\n", a[1]);
    return EXIT_SUCCESS;
}