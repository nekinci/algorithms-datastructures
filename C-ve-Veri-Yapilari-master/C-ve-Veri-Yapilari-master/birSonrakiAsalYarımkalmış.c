#include<stdio.h>

int asalSayi(int argument)
{
	int i = 1,f=0;
		while (i < (argument - 1))
		{
			i++;
			if (argument%i == 0)
			{
				f = 0;
				break;
			}
			else
				f = 1;
		}
		while (f == 0)
		{
			argument++;
			while (i < (argument - 1))
			{
				i++;
				if (argument%i == 0)
				{
					f = 0;
					break;
				}
				else
					f = 1;
			}
		}

		printf("%d", f);
		printf("\n%d", argument);
	
}
int main()
{
	int a;
	scanf_s("%d", &a);
	printf("", asalSayi(a));
	getch();
}
