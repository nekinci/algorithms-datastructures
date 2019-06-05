#include<stdio.h>

int sayi_degerlerinin_karesi_toplami(int);
int main()
{
	int c;
	scanf("%d",&c);
	printf("%d",sayi_degerlerinin_karesi_toplami(c));
		
}
int sayi_degerlerinin_karesi_toplami(int sayi)
{
	int kalan=sayi%10 ;
	if(sayi==0)
		return 0;
	else
		return kalan*kalan + sayi_degerlerinin_karesi_toplami(sayi/10);
}
