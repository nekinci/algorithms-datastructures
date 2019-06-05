#include<stdio.h>

int bolmeFonksiyonu(int, int);
int main()
{
	bolmeFonksiyonu(39, 4);
	getch();
}
int bolmeFonksiyonu(int sayi, int bolen)
{
	int bolum=0;
	while (sayi >= bolen)
	{
		sayi = sayi - bolen;
		bolum++;
		
	}
	printf("%d", bolum);
	printf("\nkalan= %d", sayi);
}
