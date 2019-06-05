#include<stdio.h>

int OBEB(int a,int b);
int main()
{
	int c, d;
	printf("Buyuk ve kucuk sayilari sirasiyla giriniz: ");
	scanf_s("%d %d",&c,&d);

	OBEB(c,d );
	getch();
		
}
int OBEB(int sayi,int sayi2)
{
	if (sayi2 == 0)
	{
		printf("Sifirdan farkli bir deger girmeniz gerekiyor.");
		goto EXIT;
	}
	int kalan = 1;
	while (kalan != 0)
	{
		kalan = sayi % sayi2;
		sayi = sayi2;
		sayi2 = kalan;
	}
	printf("Obeb: %d", sayi); EXIT:;
}