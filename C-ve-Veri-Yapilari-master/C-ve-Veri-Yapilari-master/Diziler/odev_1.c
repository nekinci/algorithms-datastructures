#include<stdio.h>

int uzunluk_bul(char[]);
int main()
{
	int i,sonuc=0;
	char s[20];
	for(i=0;i<3;i++)
	{
		scanf("%s",s);
		//sonuc=uzunluk_bul(s);
		printf("%d nci stringin uzunlugu, %d",i+1,sonuc);

	}
	return 0;
}
int uzunluk_bul(char d[])
{
	int k;
	while(d[k]!='\0')
		k++;
	return k;
}
