//205748010310003
//VÕ TÁ NAM
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool laTamGiac(float a, float b, float c);
void nhapFloat(float *n, char *ten);

int main()
{
	float a, b, c;
	printf("Nhap cac canh tam giac : \n");
	nhapFloat(&a, "a");
	nhapFloat(&b, "b");
	nhapFloat(&c, "c");
	printf("%s tam giac\n", laTamGiac(a, b, c) ? "La" : "Khong la");
	return 0;
}


bool laTamGiac(float a, float b, float c)
{
	return (a > 0.0f && b > 0.0f && c > 0.0f) ? ( abs(a - b) < c ) : false;
}

void nhapFloat(float *n, char *ten)
{
	printf("Nhap va %s\t: ", ten);
	scanf("%f", n);
}
