//VÕ TÁ NAM
//205748010310003
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
// Tinh tong cac so duong chan duoc lay tu tep
int32_t main()
{
    FILE * f = fopen("bai02.inp", "r");
    int32_t s = 0;
    while (!feof(f))
    {
        int32_t a = 0;
        fscanf(f, "%d", &a);
        if ((a > 0) && (a % 2 == 0))
            s += a;
    }
    printf("%5d\n", s);
    return EXIT_SUCCESS;
}