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

uint64_t makeOdd(uint64_t n);
observerT* importN();
observerT* isPrime(observerT* observer);
observerT* printfResult(observerT* observer);
void clean(observerT* observer);

int main()
{
    clean(printfResult(isPrime(importN())));
    return EXIT_SUCCESS;
}

uint64_t makeOdd(uint64_t n)
{
    return (n % 2llu) ? (n) : (n - 1llu);
}

observerT* importN()
{
    observerT* observer = (observerT*)malloc(sizeof(observerT));
    observer->n = 0llu;
    while (observer->n < 1llu)
    {
        printf("Nhap n : ");
        scanf("%llu", &observer->n);
    }
    return observer;
}

observerT* isPrime(observerT* observer)
{
    if (observer->n % 2llu)
        switch (observer->n)
        {
        case 1llu:
            observer->cons = false;
        case 2llu:
        case 3llu:
        case 5llu:
        case 7llu:
        case 11llu:
            observer->cons = true;
            break;
        default:
        {
            uint64_t m = sqrtl(observer->n);
            if (observer->n % m)
                for (uint64_t i = makeOdd(observer->n); i > 2llu; i -= 2llu)
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

observerT* printfResult(observerT* observer)
{
    printf("%llu", observer->n);
    if (observer->cons)
        printf(" la so nguyen to\n");
    else
        printf("khong phai la so nguyen to\n");
    return observer;
}

void clean(observerT* observer)
{
    free(observer);
}