
#include<stdio.h>
#include<stdlib.h>

/*
int fac(int n)
{
	if (n == 1 || n == 0)
		return 1;
	else
	{

		return	n*fac(n - 1);

	}
}
int main()
{
	int a;
	scanf_s("%d", &a);
	printf("Faktoriyelin degeri: %d", fac(a));
	getch();
}
*/ //Burdan yukarýsý recursive fonksiyon aþaðýsý ise normal fonksiyondur.


int faktoriyel(int a)
{
	int fak = 1;
	int i = 1;
	while (i <= a)
	{
		fak = fak*i;
		i++;
	}
	return fak;
}

int main()
{
	int c;
	scanf_s("%d", &c);
	printf("Faktoriyelin degeri : %d", faktoriyel(c));
	getch();
}
