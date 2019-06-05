#include<stdio.h>
#include<stdlib.h>
int mukemmelSayi(int sayi)
{
	int i = 1;
	int toplam = 0;
	while (i < sayi)
	{
		if (sayi%i == 0)
		{
			toplam = toplam + i;
		}

		i++;
	}
	if (toplam == sayi)
		printf("\n%d", sayi);
	else
		//printf("%d sayisi Mukemmel sayi degildir.", sayi)
		;
		
}
int main()
{
	int i = 1;
	for (i = 1; i <= 10000; i++)
		mukemmelSayi(i);
	getch();

}