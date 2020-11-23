/*
	Thông báo số phần tử viết hoa có sâu
*/
#include <conio.h>

#include <stdio.h>
#include <string.h>
int main()
{
	char s[20] = "AbcdEFGH";
	// Khởi tạo biến số nguyên dem với giá trị ban đầu = 0 để cho việc đếm
	// Biến số nguyên n dùng để chứa giá trị là số ký tự có trong xâu s.
	int i = 0, dem = 0, n;
	// Dùng strlen để có số ký tự có trong xâu
	n = strlen(s);
	//	Tạo vòng lặp để kiểm tra từng ký tự một co s trong xâu
	for (i = 0; i < n; i++)
		// Nếu ký tự đó thuộc phạm vi từ 'A' đến 'Z' thì đếm lại
		if ((s[i] >= 'A') && (s[i] <= 'Z'))
			dem++;
	// Thông báo số lần đã đếm được
	printf("%5d", dem);
	getch();
	return 0;
}
