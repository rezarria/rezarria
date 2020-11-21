nclude <conio.h>
#include <stdio.h>
#include <string.h>
int main()
{
	char s[20] = "AbcdEFGH";
	int i = 0, dem = 0, n;
	n = strlen(s);
	for(i = 0; i < n; i++)
		if ((s[i] >= 'A') && (s[i] <= 'Z'))
			dem++;
	printf("%5d", dem);
	getch();
	return 0;
}
