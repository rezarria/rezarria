#include <stdio.h>
int main()
{
	int a = 4, b = 6, n;
	n = a + b;
	printf("n = a + b\n%d = %d + %d\n", n, a, b);
	// a + b = 4 + 6 = 10
	n = ++a + b;
	printf("n = ++a + b\n%d = %d + %d\n", n, a, b);
	/*
		++a + b
		++a + 6
		5 + 6		( a = 5; b = 6 )
		11
	*/
	n = a++ + b;
	printf("n = a++ + b\n%d = %d + %d\n", n, a, b);
	/*
		a++ + b
		a++ + 6
		5 + 6		(a = 6; b = 6 )
		11
	*/
	n = --a + b;
	printf("n = --a + b\n%d = %d + %d\n", n, a, b);
	/*
		--a + b
		--a + 6
		5 + 6		( a = 5; b = 6 )
		11
	*/
	n = a-- + b;
	printf("n = a-- + b\n%d = %d + %d\n", n, a, b);
	/*
		a-- + b
		a-- + 6
		5 + 6		( a = 4; b = 6 )
		11
	*/
	n = a + b;
	printf("n = a + b\n%d = %d + %d\n", n, a, b);
	//	a + b = 4 + 6 = 10
	return 0;
}
