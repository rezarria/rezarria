#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

uint32_t importUi32();
bool isPrime(uint32_t n);
void display(uint32_t n);

int32_t main()
{

    uint32_t n = importUi32();
    display(n);
    return EXIT_SUCCESS;
}

uint32_t importUi32()
{
    uint32_t n;
    fputs("> ", stdout);
    scanf("%u", &n);
    return n;
}

bool isPrime(uint32_t n)
{
    bool check = true;
    switch (n)
    {
    case 2:
    case 3:
    case 5:
    case 7:
    case 11:
        break;
    default:
        if (n % 2)
        {
            for (uint32_t i = sqrt(n); i > 2u; i--)
                if ((n % i) == 0)
                {
                    check = false;
                    break;
                }
        }
        else check = false;
    }
    return check;
}

void display(uint32_t n)
{
    if (isPrime(n))
        printf("> %u la so prime!\n", n);
    else
        printf("> %u khong phai la so prime!\n", n);
}
