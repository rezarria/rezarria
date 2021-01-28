#include <stdio.h>
#include <stdlib.h>

int layDong(char *ten)
{
    int dem = 1;
    FILE *f = fopen(ten, "r");
    while (!feof(f))
        if (fgetc(f) == '\n')
            dem++;
     fclose(f);
    return dem;
}

float **layDuuLieu(char *ten, int soBo)
{
    float **boSo = (float **)malloc(sizeof(float *) * soBo);
    FILE *f = fopen(ten, "r");
    for (int i = 0; i < soBo; i++)
    {
        boSo[i] = (float *)malloc(sizeof(float));
        fscanf(f, "%f%f", &boSo[i][0], &boSo[i][1]);
    }
    fclose(f);
    return boSo;
}

char *nghiemPT1(float a, float b)
{
    static char str[256];
    if (a == 0.0f)
    {
        if (b == 0.0f)
            sprintf(str, "vo so nghiem");
        else
            sprintf(str, "vo nghiem");
    }
    else
    {
        if (b == 0.0f)
            sprintf(str, "0");
        else
            sprintf(str, "%f", -b / a);
    }

    return str;
}

void xuatNghiem(char *ten, float **boSo, int soBo)
{
    FILE *f = fopen(ten, "w");
    for (int i = 0; i < soBo; i++)
        fprintf(f, "%15f %15f %15s\n", boSo[i][0], boSo[i][1], nghiemPT1(boSo[i][0], boSo[i][1]));
    fclose(f);
}

int main()
{

    //lay so dong
    int soBo = layDong("input.txt");
    float **boSo = layDuuLieu("input.txt", soBo);
    putchar('2');
    xuatNghiem("output.txt", boSo, soBo);
    putchar('3');
    return 0;
}