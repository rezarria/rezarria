#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b);
void displayArr(int* arr, unsigned int n);
void importArr(int* arr, unsigned int n);

int main()
{
	unsigned int n;
	printf("Nhap so n : ");
	scanf("%u", &n);

	int* arr = (int*)calloc(n + 1llu, 4llu);
	//	Tạo mảng số nguyên
	// Hơi giống int arr[n] nhưng cách này thì các phần tử đều có giá trị bằng 0
	// Tạo mảng n + 1 phần tử
	// Trong đó n phần tử được nhập vào trước
	// Còn 1 phần tử coi là phần tử x sẽ được nhập vào sausau

	importArr(arr, n);
	// Hàm để nhập giá trị vào biến mảng số nguyên

	qsort(arr, n, 4, cmp);
	// Hàm sắp xếp lại vị trí phần tự theo thứ tự tăng dần
	// Dùng để xếp lại n phần tử của mảng, trừ phần tự cuối trên n không xếp để nhập giá trị x 

	displayArr(arr, n);
	// Hàm hiện thị các giá trị của biến mảng

	printf("Nhap phan tu x\t:\t");
	scanf("%d", &arr[n]);
	// Nhập phần tự x cũng chính là phần tự nằm cuối bị trừ ra của mảng

	n++;
	// Vì nãy giờ kích thức thật của mảng là n + 1
	// Dùng lệnh này để chỉnh cho đúng kích cơ thật của mảng
	
	qsort(arr, n, 4llu, &cmp);
	//	Vì phần tử x nằm cuối dùng, phải sắp xếp lại lần nữa để cho các phần tự về đúng vị trí theo thứ tự tăng dần
	displayArr(arr, n);
	// Hiện thị giá trị phần tử có trong mảng

	return EXIT_SUCCESS;
	//	Tức là return 0 đóđó
}

void importArr(int* arr, unsigned int n)
{
	printf("Nhap mang\n");
	for (unsigned int i = 0; i < n; i++)
	{
		printf("Nhap phan tu %5d\t:\t", i);
		scanf("%d", &arr[i]);
	}
}

void displayArr(int* arr, unsigned int n)
{
	printf("\n----------------------\n");
	for (unsigned int i = 0; i < n; i++)
		printf("phan tu %2u\t:\t%4d\n", i, arr[i]);
}

int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}