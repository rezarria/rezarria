#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ***cutStr(char *string);

int main()
{
    return EXIT_SUCCESS;
}

char ***cutStr(char *string)
{
    char ***list = (char ***)calloc(255llu, sizeof(char **));
    size_t n = 0;
    return realloc((void *)list, sizeof(char **) * n);
}