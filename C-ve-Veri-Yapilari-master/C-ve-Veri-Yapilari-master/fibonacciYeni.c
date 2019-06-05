#include<stdio.h>

int main()
{
	int ilk=0;
	int iki=1;
	int toplam,sayici=1;
	int kacinciEleman;
	puts("Kacinci elemana kadar gormek istiyorsunuz: ");
	scanf("%d",&kacinciEleman);
	printf("%d\t%d",ilk,iki);
	while(sayici<=(kacinciEleman-2))
	{
		toplam=ilk+iki;
		ilk=iki;
		iki=toplam;
		printf("\t%d",toplam);
		sayici++;
	}
	
}
