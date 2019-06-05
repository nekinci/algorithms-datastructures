#include<stdio.h>
#define BOYUT 15

int ara(int[],int,int,int);
int main()
{
	int b[BOYUT],aranacak_deger,i,sonuc;
	for(i=0;i<=BOYUT-1;i++)
	{
		b[i]=2*i;
	}
	printf("0 ile 28 arasinda bir deger giriniz: \n");
	scanf("%d",&aranacak_deger);
	if(ara(b,aranacak_deger,0,BOYUT-1))
	{
		printf("Bulundu!\n" );
	}
	else
		printf("bulunamadi!\n");
}
int ara(int c[],int anahtar,int alt,int ust)
{
	int orta;
	while(alt<=ust)
	{
		orta=(alt+ust)/2;
		if(anahtar==c[orta])
			return 1;
		else if(anahtar<c[orta])
			ust=orta+1;
		else
			alt=orta+1;
	}
	return -1;
}