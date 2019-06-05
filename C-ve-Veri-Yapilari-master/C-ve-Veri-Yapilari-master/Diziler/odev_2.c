#include <stdio.h>

int uzunluk_hesapla(char[]);
void katar_birlestir(char[],char[]);
void katarlari_birlestir(char c[],char c1[]);
int main()
{
	char str1[20];

    char str2[20];
	printf("Bir seyler yazin..: \n");
	scanf("%s",str1);
	printf("Bir seyler yaziaaan..: \n");
	scanf("%s", str2);
	katar_birlestir(str1,str2);
	katarlari_birlestir(str1,str2);
}
int uzunluk_hesapla(char strs[])
{
	int k=0;
	while(strs[k]!='\0')
		k++;
	return k;
}
void katar_birlestir(char s1[],char s2[])
{
	int a=uzunluk_hesapla(s1);
	int b=uzunluk_hesapla(s2);
	char s3[a+b];
	int i=0,j;
	for(i=0;i<=a;i++)
		s3[i]=s1[i];
	for(j=0;j<=b+1;j++)
		s3[a+j]=s2[j];

	printf("\n%s",s3);

}
void katarlari_birlestir(char c[],char c1[])
{
	int i=0,j;
	for(i=0;c[i]!='\0';++i);
	for(j=0;c1[j]!='\0';++i,++j)
	{
        printf("i=%d \nj=%d",i,j);
		c[i]=c1[j];
	}
	printf("\n\n2:%s",c);
}
