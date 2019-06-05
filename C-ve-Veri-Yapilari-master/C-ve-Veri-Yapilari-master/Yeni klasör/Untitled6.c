#include<stdio.h>
int sayi_degerleri_15ten_buyuk(int);
int toplam=0,kalan,bolum;
int sayi_toplam=0;
int main()
{
	int sayi,c;
	
	while(sayi!=-1)
	{
		scanf("%d",&sayi);
		c=sayi;
		if(sayi_degerleri_15ten_buyuk(sayi))
			sayi_toplam=sayi_toplam+c;
		else
			sayi_toplam+=0;
		
	}
	printf("%d",sayi_toplam);
	
}
int sayi_degerleri_15ten_buyuk(int a)
{
	
	
	while(a!=0)
	{
		
		kalan=a%10;
		bolum=a/10;
		toplam=toplam+kalan;
		a=bolum;
		
	}
	if(toplam>15)
	{
		
		return 1;
	}
	
		
	else
		return 0;
	
	
}
