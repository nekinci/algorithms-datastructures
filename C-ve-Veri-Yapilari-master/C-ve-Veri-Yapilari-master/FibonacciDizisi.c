#include<stdio.h>

int Fibonacci(int n)

{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}

}
int fibNormal(int n)
{
	int a = 1;
	int b = 1;
	int c;
	int i = 1;
	
	while (i <= n)
	{
		c = a + b;
		a = b;
		b = c;
		i++;
	}
	return c;
}
int main()
{
	int a;
	printf("Kaçýncý elemana kadar görmek istiyorsunuz ? Giriniz : ");
	scanf_s("%d", &a);
	printf("%d", Fibonacci(a));
	printf("%d", fibNormal(a));
	printf("\a\a\a\a\a\a\a\a\a\a\a\a");
	getch();

}