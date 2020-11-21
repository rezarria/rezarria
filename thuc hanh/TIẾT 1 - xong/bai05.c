#include <stdio.h>
int main()
{
    printf("x\t\t=\t%2d", -3 + 4 % 5 / 2);
    /*
        x = -3 + 4 % 5 / 2
        x = -3 + 4 / 2
        x = -3 + 2
        x = -1
    */
    int y = 3;
    printf("\ny\t\t=\t%2d", y);
    //  y = 3
    printf("\n!y %% 4\t\t=\t%2d", !y % 4);
    /*
        !y % 4
        0 % 4
        0
    */
    int z = 3;
    printf("\nz\t\t=\t%2d", z);
    //  z = 3
    printf("\n!++z %% 4\t=\t%2d", !++z % 4);
    /*
        !++z % 4
        !4 % 4
        0 % 4
        0
    */
    int t = 3;
    printf("\nt\t\t=\t%2d", t);
    //  t = 3
    printf("\n!(++t %% 4)\t=\t%2d", !(++t % 4));
    /*
        !(++t % 4)
        !(4 % 4)
        !(0)
        1
    */
    return 0;
}
