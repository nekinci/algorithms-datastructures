/*
160204044 Niyazi EKÝNCÝ
Veri Þifreleme ve Hata Ayýklama
v1.0
*/

#include<stdio.h>
unsigned int sonuc;
int yanlis_yapildiysa=0;//simdilik kullanim disi
void islemYap(unsigned int,char,unsigned int);
void bitleriGoster(unsigned int);
int main()
{
    unsigned int sayi1,anahtar;
    char islem,eslikBiti;
    printf("[sayi][islem operatoru][anahtar] formatinda giriniz...\n");
    scanf("%u",&sayi1);
    scanf("%c",&islem);
    scanf("%u",&anahtar);
    islemYap(sayi1,islem,anahtar);
    printf("%u",sonuc);
    printf("Eslik biti giriniz: ");
    fflush(stdin);
    scanf("%c",&eslikBiti);

    if(eslikBiti=='T')
    {
    	sonuc=sonuc<<1;
    	sonuc=sonuc | 1;
    	printf("Sonuc: %u \n",sonuc);
    	bitleriGoster(sonuc);
	}
	else if(eslikBiti=='C')
	{
		sonuc=sonuc<<1;
		printf("%u \n",sonuc);
		bitleriGoster(sonuc);
	}




}
/*

3= 0001
5= 0101
-------
&= 0001
|= 0101
*/

void islemYap(unsigned int a, char b, unsigned int c)
{

    switch(b)
    {
        case '&':  sonuc=a&c; break;
        case '|':  sonuc=a|c; break;
        case '^':  sonuc=a^c; break;
        case '>':  sonuc=a>>c; break;
        case '<':  sonuc=a<<c; break;
        default: printf("Yanlis islem kodu girdiniz.Tekrar girin.."); break;

    }

}
void bitleriGoster(unsigned int s)
{
    unsigned int maske=1<<31;
    int t;
    for(t=1; t<=32; t++)
    {
    	putchar(s&maske?'1':'0');
    	s<<=1;
    	if(t%8==0)
    	{
    		putchar(' ');
		}
		
	}
	putchar('\n');
}
