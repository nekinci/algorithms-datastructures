#include <stdio.h>


int main()
{
	int i = 0;
	int a = 1;
	int toplam = 0, ortalama;
	while (a != 0)
	{
		scanf_s("%d", &a);
		i++;
		toplam = toplam + (a*a);
	}
	i--;
	ortalama = toplam / i;
	printf("Kareler ortalamasi %d", ortalama);
	getch();
}
