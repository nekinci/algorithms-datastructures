#include<stdio.h>

int fibonacci(int);
int us_al(int,int);
int main()
{
	
	printf("%d",us_al(3,4));
}
int fibonacci(int sayi)
{
	if(sayi==1||sayi==2)
		return 1;
	else
		return fibonacci(sayi-1)+fibonacci(sayi-2);
}
int us_al(int sayi,int us)
{
	if(us==1)
		return sayi;
	else if(us==0)
		return 1;
	else
		return sayi* us_al(sayi,us-1);
}
