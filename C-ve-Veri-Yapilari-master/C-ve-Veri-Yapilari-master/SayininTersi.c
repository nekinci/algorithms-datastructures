#include <stdio.h>

int tersiniAl(int c)
{

	int toplam = 0;
	int kalan = 0;
	while (c != 0)
	{
		toplam = toplam * 10;
		kalan = c % 10;
		toplam = toplam + kalan;
		c = c / 10;

	}
	return toplam;
}

int main()
{
	int n;
	scanf_s("%d", &n);
	printf("Sayýnýn tersi %d", tersiniAl(n));
	getch();
	return 0;
	
}
