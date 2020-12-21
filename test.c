#include <stdio.h>

void empty_stdin(void) /* simple helper-function to empty stdin */
{
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

int main(void)
{
    int input = 0,
        rtn = 0;    /* variable to save scanf return */
    // domainEntry *myDomains = buildDomainDB();

    for (;;) {  /* loop continually until valid input or EOF */
        printf("\nSelect top level domain:\n"
            "  1-EDU\n"
            "  2-COM\n"
            "  3-ORG\n"
            "  4-GOV\n"
            "  5-MIL\n"
            "  6-CN\n"
            "  7-COM.CN\n"
            "  8.CAN\n\n"
            "choice: ");
        rtn = scanf(" %d", &input);    /* save return */

        if (rtn == EOF) {   /* user generates manual EOF */
            fputs("(user canceled input.)\n", stderr);
            return 1;
        }
        else if (rtn == 0) {    /* matching failure */
            fputs(" error: invalid integer input.\n", stderr);
            empty_stdin();
        }
        else if (input < 1 || 8 < input) {  /* validate range */
            fputs(" error: integer out of range [1-8]\n", stderr);
            empty_stdin();
        }
        else {  /* good input */
            empty_stdin();
            break;
        }
    }

    printf("\nvalid input: %d\n", input);
}