#include<stdio.h>
#define kare(x) (x)*(x)

int cift_mi(int);

int main()
{
	int sayi,i=1,toplam=0,tektoplam=0;
	scanf("%d",&sayi);
	while(i<=sayi)
	{
		if(cift_mi(i))
			toplam+=kare(i);
		else
			tektoplam+=kare(i);
		i++;
	}
	printf("toplam %d",toplam);
	printf("tek toplam %d",tektoplam);
}
int cift_mi(int a)
{
	if(a%2==0)
		return 1;
	else
		return 0;
}
