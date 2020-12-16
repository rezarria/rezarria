//VÕ TÁ NAM
//205748010310003
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

int32_t* importI32Arr(FILE* input, int32_t* n);
void exportI32Arr(FILE* output, int32_t* arr, size_t n);
void editI32Arr(size_t x, int32_t* arr, int32_t n);
void editUI(int32_t* arr, int32_t n);
void displayArr(int32_t* arr, size_t n);

int32_t main()
{
    FILE* f = fopen("input.txt", "r");
    int32_t n = 0;
    int* arr = importI32Arr(f, &n);
    fclose(f);
    displayArr(arr, n);
    editUI(arr, n);
    displayArr(arr, n);
    f = fopen("output.txt", "r");
    exportI32Arr(f, arr, n);
    fclose(f);
    return EXIT_SUCCESS;
}

void displayArr(int32_t * arr, size_t n)
{
    printf("---------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
}

int32_t* importI32Arr(FILE* input, int32_t* n)
{
    *n = 0;
    int32_t* arr = (int32_t*)calloc(256llu, sizeof(int32_t));
    while (!feof(input))
        fscanf(input, "%d", &arr[(*n)++]);
    return (int32_t*)realloc((void*)arr, sizeof(int32_t) * (*n));
}
void exportI32Arr(FILE* output, int32_t* arr, size_t n)
{
    for (size_t i = 0llu; i < n; i++)
        fprintf(output, "%d ", arr[i]);
}
void editI32Arr(size_t x, int32_t* arr, int32_t n)
{
    arr[x] = n;
}
void editUI(int32_t* arr, int32_t n)
{
    char* str = (char*)calloc(256llu, sizeof(char));
    bool run = true;
    printf("nhap \\ de thoat\n");
    while (run)
    {
        printf("Vi tri x:\n");
        printf("int> ");
        scanf("%s", str);
        if (str[0] == '\\')
            run = false;
        else
        {
            int a = atoi(str);
            printf("arr[%d] = %d\n> ", a, arr[a]);
            scanf("%d", &arr[a]);
        }

    }
}