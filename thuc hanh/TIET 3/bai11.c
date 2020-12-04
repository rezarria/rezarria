#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

uint32_t nhapUi32();
bool laPrime(uint32_t n);
void hienThi(uint32_t n);

int32_t main()
{

    uint32_t n = nhapUi32();
    hienThi(n);
    return EXIT_SUCCESS;
}

uint32_t nhapUi32()
{
    uint32_t n;
    fputs("> ", stdout);
    scanf("%u", &n);
    return n;
}

bool laPrime(uint32_t n)
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
            for (uint32_t i = sqrt(n); i > 2; i--)
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

void hienThi(uint32_t n)
{
    if (laPrime(n))
        printf("> %u la so prime!\n", n);
    else
        printf("> %u khong phai la so prime!\n", n);
}