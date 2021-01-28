#include <stdio.h>
#include <math.h>

void nhapSo(float *so, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%d]\t: ", i);
        scanf("%f", so + i); // "so + i" co the thay bang " &so[i] "
    }
}

void ghiRaTep(char *ten, float *so, int n)
{
    //tao lien ket tep
    FILE *f = fopen(ten, "w");

    //kiem tra so thuc duong
    for (int i = 0; i < n; i++)
        if (so[i] > 0.0f)
            fprintf(f, "%f\n", so[i]);

    fclose(f);
}

int main()
{

    //nhap n
    int n;
    printf("Bao nhieu so : ");
    scanf("%d", &n);

    //tao mang so thuc
    float so[n];

    //nhap mang so vao
    nhapSo(so, n);

    //ghi ra tep
    ghiRaTep("output.txt", so, n);

    return 0;
}