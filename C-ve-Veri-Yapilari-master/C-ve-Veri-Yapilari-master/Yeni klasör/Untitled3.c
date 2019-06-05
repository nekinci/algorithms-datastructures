#include<stdio.h>

int tersiniAl(int a);
int toplam=0;
int kalan,bolum;
int main()
{
	int sayi1;
	scanf("%d",&sayi1);
	tersiniAl(sayi1);
	printf("\n\n\n%d",sayi1);

}
int tersiniAl(int sayi)
{
	
	while(sayi!=0)
	{
		toplam*=10;
		bolum=sayi/10;
		kalan=sayi%10;
		toplam+=kalan;
		sayi=bolum;
	}
	printf("%d",toplam);
	
}
