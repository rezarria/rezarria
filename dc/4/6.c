#include <stdio.h>
#include <ctype.h>

int soKyTuInHoa(FILE *f)
{
    fseek(f, 0l, SEEK_SET);
    int dem = 0;
    while (!feof(f))
        if (isupper(fgetc(f)))
            dem++;
    return dem;
}

int main()
{
    FILE *f = fopen("input.txt", "r");
    printf("%d\n", soKyTuInHoa(f));
    fclose(f);
    return 0;
}