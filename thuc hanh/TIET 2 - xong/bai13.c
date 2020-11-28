#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
	char s[256];
	//	Tạo mảng chữ tức xâu có độ dài 256
	unsigned int *arr = (unsigned int*)calloc(26, sizeof(unsigned int));
	// Giống như lênh int arr[n]
	// Cách này giúp toàn bộ phần tử của mảng đều có giá trị bằng 0
	// Từ A đến Z là 26
	unsigned int i = 0;
	//Dùng cho việc lặp
	unsigned int c = 0;
	//	Dùng để xuống dòng, câu lệnh dưới sẽ giải thích
	printf("Nhap xau:\n");
	gets(s);
	while(s[i] != '\0') // Lặp đến kkí tư '\0' thì dừng lặp '\0' có giá trị = 0 = false
	{
		arr[toupper(s[i]) - 65]++;
		//	Xâu s có các kí tự tứ a đến z và A đến Z, nhưng đề coi a và A là một nên dùng đến lệnh toupper để biến a thành A
		//	A có giá trị 65 nhưng ta sẽ coi nó là số bắt đầu của mảng tức 0 nên phải có - 65
		//	Vì tất cả phần tử của mảng arr đều là 0, số 0 ở đây ý nghĩa là số lần xuất ký tự đó
		//	Coi ký tự là thứ tự, đọc được ký tự nào thì gọi phần tử ở thứ tự đó lên rồi tăng lên 1 đơn vị - tức đếm + 1 vào số lần xuất hiện của kí tự đó

		i++;
	}
	printf("-------------------------------------\n");
	for(i = 0; i < 26; i++)
		if(arr[i]) // Nếu ký tự đó có số lần xuất hiện lớn hơn 0 thì mới thông báo ra
		{
			if(c == 3) //In được 3 thông báo thì xuống dòng cho đẹp
			{
				printf("\n");
				c = 0;
			}
			printf("%5d ky tu '%c'\t", arr[i], i + 'A');
			c++;
		}
	return 0;
}
