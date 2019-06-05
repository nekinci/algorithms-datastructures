#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int zarAt(void);
int main()
{
	printf("***");
	printf("\nFSociety oyun kulubune hosgeldiniz.");
	printf("\n***");
	int toplam=zarAt();
	srand(time(NULL));
	int oyuncuSayisi;
	int oyunDurumu=0;
	scanf("%d",&oyuncuSayisi);
	printf("Oyuncu Sayisi: %d tanedir. Oyun kurallari oyuncu sayisina gore sekillendirilecektir.",oyuncuSayisi);
	switch(toplam)
	{
		case 7: case 11:
			oyunDurumu=1;
			break;
		case 2: case 3: case 12:
			oyunDurumu=2;
			break;
		default
			oyuncu
	}
	
	
}
int zarAt(void)
{
	int zar1,zar2,toplamZar;
	zar1=1+rand()%6;
	zar2=1+rand()%6;
	toplamZar=zar1+zar2;
	printf("Zar1: %d Zar2: %d , Toplam=%d",zar1,zar2,toplamZar);
	return toplamZar;
	
	
}
