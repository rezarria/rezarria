#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void swap(void *a, void *b, size_t size)
{
    void *c = malloc(size);
    memcpy(c, a, size);
    memcpy(a, b, size);
    memcpy(b, c, size);
    free(c);
}

int main()
{
    float a, b;
    printf("Nhap gia tri vao a va b : ");
    scanf("%f%f", &a, &b);
    printf("a : %f\nb : %f\n", a, b);
    printf("trao bien\n");
    swap(&a, &b, sizeof(float));
    printf("a : %f\nb : %f\n", a, b);
    return 0;
}