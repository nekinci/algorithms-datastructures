#include<stdio.h>

int asalSayi(int argument)
{
	int i = 1,f=0;
	if (argument == 2)
	{
		f= 1;
	}
	
	else
	{
		while (i < (argument - 1))
		{
			i++;
			if (argument%i == 0)
			{
				f = 0;
				break;
			}
			else
			{
				f = 1;


			}
			

		}
	}
	
	if (f == 1)
		printf("sayi asal");
	else
		printf("sayi asal degil");
	return argument;
}
int main()
{
	int a;
	scanf_s("%d", &a);
	printf("", asalSayi(a));
	getch();
}
