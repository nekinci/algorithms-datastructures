#include<stdio.h>
#define BOYUT 10
int main()
{
	int dizi[] = {5,6,9,15,65,15,3,1,9,10};
	int i, j;
	printf("%s%7s%13s", "Eleman", "Deger", "Grafik");
	printf("\n");

	for (i = 0; i <= BOYUT - 1; i++)
	{
		printf("%4d%9d	    ", i, dizi[i]);
		for (j = 1; j <= dizi[i]; j++)
		{
			printf("*");
		}
		printf("\n");
		
	}
	getch();

}