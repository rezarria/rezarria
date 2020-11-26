#include "cutStr.h"
#include "rezar.h"

int main()
{
    char **list = importListString();
    char ***cutList = cutStrList(list);
    countList(cutList);
    return 0;
}