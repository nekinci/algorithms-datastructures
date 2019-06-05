#include<stdio.h>
int genel_toplam=0;
int basamakToplam(int);

int main()
{
	int sayi,c;
	while(sayi!=-1)
	{
		printf("Bir sayi gir: ");
		scanf("%d",&sayi);
		c=sayi;
		if(basamakToplam(sayi))
			genel_toplam=genel_toplam+sayi;
		else
			genel_toplam+=0;
		
	}
	printf("%d",genel_toplam);
}
int basamakToplam(int a)
{
	int toplam=0,kalan,bolum;
	while(a!=0)
	{
		bolum=a/10;
		kalan=a%10;
		toplam=toplam+kalan;
		a=bolum;
	}
	if(toplam>15)
		return 1;
	else
		return 0;
}
