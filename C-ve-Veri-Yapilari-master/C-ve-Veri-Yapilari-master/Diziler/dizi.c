#include<stdio.h>
#define BOYUT 40
int main()
{
	int cevaplar[40]={1,2,3,5,8,5,4,8,9,1,1,7,2,3,3,3,3,6,5,4,5,9,8,2,5,6,3,2,5,6,5,4,1,2,3,2,5,6,5,2},oySayisi[11]={0};
	int i=0;
	for(i=0;i<=BOYUT-1;i++)
	{
		oySayisi[cevaplar[i]]=oySayisi[cevaplar[i]]+1;

	}
	printf("Derece    Sayisi\n");
	for(i=1;i<11; i++)
	{
		printf("%4d%9d\n",i,oySayisi[i]);
	}

}