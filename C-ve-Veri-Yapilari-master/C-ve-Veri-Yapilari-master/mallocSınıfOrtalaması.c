#include <stdio.h>



int main()
{
	int a;
	printf("Sýnýf Mevcudunu giriniz: ");
	scanf_s("%d", &a);
	int *p = (int *)malloc(sizeof(int)*a);
	int i = 0;
	int b, ortalama, toplam=0;
	int c = 0;
	while (i < a)
	{
		printf("Ogrencinin notunu giriniz: ");
		scanf_s("%d", &b);
		*(p + i) = b;
		i++;
	}
	while (c < a)
	{
		toplam = toplam + p[c];
		c++;
	}
	ortalama = toplam / a;
	printf("Sinif ortalamasi: %d", ortalama);
	getch();

}