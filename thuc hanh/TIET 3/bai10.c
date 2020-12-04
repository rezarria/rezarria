#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct observer
{
    uint64_t n;
    bool bit[64];
    uint8_t p;
} observerT;

observerT* nhapNDuong();
observerT* decToBin(observerT* observer);
observerT* printfResult(observerT* observerT);
void clean(observerT* observer);

int main()
{
    clean(printfResult(decToBin(nhapNDuong())));
    return EXIT_SUCCESS;
}

observerT* nhapNDuong()
{
    observerT* observer = (observerT*)malloc(sizeof(observerT));
    observer->n = 0llu;
    observer->p = 64;
    while (observer->n < 1llu)
    {
        printf("Nhap n : ");
        scanf("%llu", &observer->n);
    }
    return observer;
}

observerT* decToBin(observerT* observer)
{
    uint64_t n = observer->n;
    while (n)
    {
        observer->p--;
        observer->bit[observer->p] = n % 2llu;
        n /= 2llu;
    }
    return observer;
}

observerT* printfResult(observerT* observer)
{
    printf("%5llu\t", observer->n);
    for (uint8_t i = observer->p; i < 64; i++)
        printf("%d", observer->bit[i]);
    printf("\n");
    return observer;
}

void clean(observerT* observer)
{
    free(observer);
}