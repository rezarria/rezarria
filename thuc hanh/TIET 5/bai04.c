//VÕ TÁ NAM
//205748010310003
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

int32_t main()
{
    FILE * f = fopen("bai04.inp", "r");
    size_t n = 0llu;
    while(!feof(f))
        {
            char c = fgetc(f);
            if ((c >= 'A') && ( c <= 'Z'))
                n++;
        }
    printf("So chu viet hoa : %llu\n", n);
    fclose(f);
    return EXIT_SUCCESS;
}
