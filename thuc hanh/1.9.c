//205748010310003
//VÕ TÁ NAM
#include <stdio.h>
#include <math.h>

int sauNnam(int tienGoc, float tiLe, int nam);

int main()
{
	printf("Nhap so tien goc\t: ");
	float tienGoc;
	scanf("%f", &tienGoc);
	printf("Nhap nam\t\t: ");
	int nam;
	scanf("%d", &nam);
	float tiLe = 0.1f;
	float tienMoi = sauNnam(tienGoc, tiLe, nam);
	printf("tien goc la\t: %10.3f vnd\n", tienGoc);
	printf("tien sau %d nam\t: %10.3f vnd\n", nam, tienMoi);
	printf("tien lai la\t: %10.3f vnd\n", tienMoi - tienGoc);
	return 0;	
}

int sauNnam(int tienGoc, float tiLe, int nam)
{
	return tienGoc * pow((1.0f + tiLe), nam);
}

