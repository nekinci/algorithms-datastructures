#include<stdio.h>
#define OGRENCILER 3
#define SINAVLAR 4

int maximum(const int[][SINAVLAR],int,int);
int minimum(const int[][SINAVLAR],int,int);
double ortalama(const int[],int);
int diziyiyazdir( const 1int[][SINAVLAR],int,int);

int main(){

    int notCizelgesi[OGRENCILER][SINAVLAR]={65,66,78,71,98,84,81,89,48,71,83,45};
    diziyiyazdir(notCizelgesi,OGRENCILER,SINAVLAR);
    int maxx = maximum(notCizelgesi,OGRENCILER,SINAVLAR);
    int minn=minimum(notCizelgesi,OGRENCILER,SINAVLAR);
    printf("Max = %d  \nMin = %d\n",maxx,minn);
    int ogrenci;
    for(ogrenci=0;ogrenci<=OGRENCILER-1;ogrenci++)
    {
    	printf("%d nci ogrenci icin ortalama not = %.2f\n",ogrenci,ortalama(notCizelgesi[ogrenci],SINAVLAR));
    }
}
int diziyiyazdir(const int c[][SINAVLAR],int a,int b)
{
	int i,j;
	for(i=0;i<=a-1;i++)
	{
		for(j=0;j<=b-1;j++)
		{
			printf("\t%d",c[i][j]);
		}
		printf("\n");
	}
}
int maximum(const int c[][SINAVLAR],int a,int b)
{
	int i,j,maximum=0;
	for(i=0;i<=a-1;i++)
	{
		for(j=0;j<=b-1;j++)
		{
			if(c[i][j]>maximum)
				maximum=c[i][j];
		}
	}
	return maximum;
}
int minimum(const int c[][SINAVLAR],int a,int b)
{
	int i,j,minimum=100;
	for(i=0;i<=a-1;i++)
	{
		for(j=0;j<=b-1;j++)
		{
			if(c[i][j]<minimum)
				minimum=c[i][j];
		}
	}
	return minimum;
}
double ortalama(const int c[],int b)
{
	int i,toplam=0;
	for(i=0;i<=b-1;i++)
		toplam+=c[i];
	return (double)toplam/b;
}
