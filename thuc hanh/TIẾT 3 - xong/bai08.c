#include <stdio.h>
#include <stdlib.h>
typedef struct
{
  int n, m;
  int *min;
  int *max;
  int **matrix;
} observerT;
observerT *nhapMN();
observerT *taoMang(observerT *observer);
observerT *nhapMang(observerT *observer);
observerT *inKetQua(observerT *oberver);
void clean(observerT *observerT);

int main()
{
  clean(inKetQua(nhapMang(taoMang(nhapMN()))));
  return 0;
}

observerT *nhapMN()
{
  observerT *observer = (observerT *)malloc(sizeof(observerT));
  printf("Nhap gia tri n, m : ");
  scanf("%d%d", &observer->n, &observer->m);
  return observer;
}

observerT *taoMang(observerT *observer)
{
  observer->matrix = (int **)malloc(observer->n * sizeof(int *));
  for (int i = 0; i < observer->n; i++)
    observer->matrix[i] = (int *)calloc(observer->m, sizeof(int));
  return observer;
}

observerT *nhapMang(observerT *observer)
{
  observer->min = &observer->matrix[0][0];
  observer->max = observer->min;
  for (int i = 0; i < observer->n; i++)
    for (int j = 0; j < observer->m; j++)
    {
      printf("Nhap phan tu [%2d,%2d] : ", i, j);
      scanf("%d", &observer->matrix[i][j]);
      if (*observer->max < observer->matrix[i][j])
        observer->max = &observer->matrix[i][j];
      if (*observer->min > observer->matrix[i][j])
        observer->min = &observer->matrix[i][j];
    }
  return observer;
}

observerT *inKetQua(observerT *observer)
{
  printf("Gia tri lon nhat trong mang la %d\n", *observer->max);
  printf("Gia tri nho nhat trong mang la %d\n", *observer->min);
  return observer;
}

void clean(observerT *observer)
{
  for (int i = 0; i < observer->n; i++)
    free(observer->matrix[i]);
  free(observer->matrix);
  free(observer);
}