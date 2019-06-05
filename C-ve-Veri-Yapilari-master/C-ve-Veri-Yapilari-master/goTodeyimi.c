#include <stdio.h>

int main()
{
	int i; char ch;
	for (i = 0; i <= 20; i++){
		ch = getch();
	if (ch == 'a')
		goto lalala;
	printf("\n %d", i);
}lalala:;
	getch();
}