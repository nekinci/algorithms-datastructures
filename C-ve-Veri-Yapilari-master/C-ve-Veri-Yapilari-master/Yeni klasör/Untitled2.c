#include<stdio.h>

int main()
{
	int sayi,a;
	int kalan,toplam=0,bolum;
	printf("Bir sayi girin: ");
	scanf("%d",&sayi);
	a=sayi;
	while(sayi!=0)
	{
		toplam*=10;
		bolum=sayi/10;
		kalan=sayi%10;
		toplam=toplam+kalan;
		sayi=bolum;
	}
	printf("%d",toplam);
	if(toplam==sayi)
	{
		printf("Palindrom");
	}
	else
		printf("Palindrom degil");
}


