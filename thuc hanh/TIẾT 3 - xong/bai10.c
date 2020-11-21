#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct
{
    uint64_t n;
    bool bit[64];
    uint8_t p;
} observerT;

observerT *nhapNDuong();
observerT *decToBin(observerT *observer);
observerT *inKetQua(observerT *observerT);
void clean(observerT *observer);

int main()
{
    clean(inKetQua(decToBin(nhapNDuong())));
    return 0;
}

observerT *nhapNDuong()
{
    observerT *observer = (observerT *)malloc(sizeof(observerT));
    observer->n = 0;
    observer->p = 64;
    while (observer->n < 1)
    {
        printf("Nhap n : ");
        scanf("%d", &observer->n);
    }
    return observer;
}

observerT *decToBin(observerT *observer)
{
    uint64_t n = observer->n;
    while (n)
    {
        observer->p--;
        observer->bit[observer->p] = n % 2;
        n /= 2;
    }
    return observer;
}

observerT *inKetQua(observerT *observer)
{
    printf("%5d\t", observer->n);
    for (uint8_t i = observer->p; i < 64; i++)
        printf("%d", observer->bit[i]);
    printf("\n");
    return observer;
}

void clean(observerT *observer)
{
    free(observer);
}