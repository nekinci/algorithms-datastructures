#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int soruSor(void)
{
	int cevap;
	srand(time(NULL));
	int i = rand() % 10;
	int j = rand() % 10;
	printf("%d kere %d kac eder?", i, j);
	scanf_s("%d", &cevap);

	int dogru = rand() % 3;
	int yanlis = rand() % 3;
	
	if (cevap == i*j)
	{
		switch (dogru) {
		case 0:printf("\nMukemmel"); break;
		case 1:printf("\nHarika! Hadi devam edelim."); break;
		case 2:printf("\nAferin!"); break;
		case 3:printf("\nIste bu kadar!"); break;

		}
	}
	else
	{
		switch (yanlis) {
		case 0:printf("\nPes etme!"); break;
		case 1:printf("\nTekrar deneyelim mi?"); break;
		case 2:printf("\nYanlis yapa yapa dogru ogrenilir :)"); break;
		case 3:printf("\nBir daha dusun."); break;

		}
	}

	


}

int main()
{
	soruSor();
	getch();

}