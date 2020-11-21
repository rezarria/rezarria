#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    uint64_t n;
    bool cons;
} observerT;

uint64_t lamLe(uint64_t n);
observerT *nhapN();
observerT *isPrime(observerT *observer);
observerT *inKetQua(observerT *observer);
void clean(observerT *observer);

int main()
{
    clean(inKetQua(isPrime(nhapN())));
    return 0;
}

uint64_t lamLe(uint64_t n)
{
    return (n % 2) ? (n) : (n - 1);
}

observerT *nhapN()
{
    observerT *observer = (observerT *)malloc(sizeof(observerT));
    observer->n = 0;
    while (observer->n < 1)
    {
        printf("Nhap n : ");
        scanf("%llu", &observer->n);
    }
    return observer;
}

observerT *isPrime(observerT *observer)
{
    if (observer->n % 2)
        switch (observer->n)
        {
        case 1:
            observer->cons = false;
        case 2:
        case 3:
        case 5:
        case 7:
        case 11:
            observer->cons = true;
            break;
        default:
        {
            uint64_t m = sqrtl(observer->n);
            if (observer->n % m)
                for (uint64_t i = lamLe(observer->n); i > 2; i -= 2)
                    if (observer->n % i)
                    {
                        observer->cons = false;
                        break;
                    }
                    else
                        observer->cons = false;
            observer->cons = true;
            break;
        }
        }
    else
        observer->cons = false;
    return observer;
}

observerT *inKetQua(observerT *observer)
{
    printf("%llu", observer->n);
    if (observer->cons)
        printf(" la so nguyen to\n");
    else
        printf("khong phai la so nguyen to\n");
    return observer;
}

void clean(observerT *observer)
{
    free(observer);
}