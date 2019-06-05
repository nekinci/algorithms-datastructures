#include<stdio.h>

int uzunluk_bul(char[]);
int main()
{
	int i,sonuc;
	char s[100];
	printf("stringleri girin : \n");
	for(i=0;i<3;i++)
	{
		scanf("%s",s);
		sonuc=uzunluk_bul(s);
		printf("%d nci stringin uzunlugu, %d",i+1,sonuc);
	}
	return 0;
}
int uzunluk_bul(char d[])
{
	int k=0;
	while(d[k]!='\0')
		k++;
	return k;
}
