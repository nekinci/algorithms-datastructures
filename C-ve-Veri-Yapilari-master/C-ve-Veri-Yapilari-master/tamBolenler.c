#include<stdio.h>

int main()
{
	int x, i = 1;
	scanf_s("%d",&x);
	while (i <= x)
	{
		if (x%i == 0)
		{
			printf("%d\t", i);
		}
		i++;
	}
	getch();
}