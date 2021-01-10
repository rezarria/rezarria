//205748010310003
//VÕ TÁ NAM
#include <stdio.h>
#define max(a,b) (a > b) ? a : b

void nhapFloat(float *n, char* ten);

int main()
{
	float a, b, c;
	nhapFloat(&a, "a");
	nhapFloat(&b, "b");
	nhapFloat(&c, "c");
	printf("So lon nhat trong 3 so la %3.2f\n", max(a, (max(b, c))));
	return 0;
}

void nhapFloat(float *n, char* ten)
{
	printf("Nhap vao %s\t: ");
	scanf("%f", n);
}
