#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct observer
{
  int64_t n, m;
  int32_t* min;
  int32_t* max;
  int32_t** matrix;
} observerT;
observerT* nhapMN();
observerT* taoMang(observerT* observer);
observerT* nhapMang(observerT* observer);
observerT* printfResult(observerT* oberver);
void clean(observerT* observerT);

int32_t main()
{
  clean(printfResult(nhapMang(taoMang(nhapMN()))));
  return EXIT_SUCCESS;
}

observerT* nhapMN()
{
  observerT* observer = (observerT*)malloc(sizeof(observerT));
  printf("Nhap gia tri n, m : ");
  scanf("%llu%llu", &observer->n, &observer->m);
  return observer;
}

observerT* taoMang(observerT* observer)
{
  observer->matrix = (int32_t**)malloc(observer->n * sizeof(int32_t*));
  for (uint64_t i = 0llu; i < observer->n; i++)
    observer->matrix[i] = (int32_t*)calloc(observer->m, sizeof(int32_t));
  return observer;
}

observerT* nhapMang(observerT* observer)
{
  observer->min = &observer->matrix[0][0];
  observer->max = observer->min;
  for (uint64_t i = 0llu; i < observer->n; i++)
    for (uint64_t j = 0llu; j < observer->m; j++)
    {
      printf("Nhap phan tu [%2llu,%2llu] : ", i, j);
      scanf("%d", &observer->matrix[i][j]);
      if (*observer->max < observer->matrix[i][j])
        observer->max = &observer->matrix[i][j];
      if (*observer->min > observer->matrix[i][j])
        observer->min = &observer->matrix[i][j];
    }
  return observer;
}

observerT* printfResult(observerT* observer)
{
  printf("Gia tri lon nhat trong mang la %d\n", *observer->max);
  printf("Gia tri nho nhat trong mang la %d\n", *observer->min);
  return observer;
}

void clean(observerT* observer)
{
  for (uint64_t i = 0llu; i < observer->n; i++)
    free(observer->matrix[i]);
  free(observer->matrix);
  free(observer);
}