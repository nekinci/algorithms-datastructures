#include<stdio.h>
#include<string.h>

int main()
{
	char dizi[10]="bbbaaassd";
	int i=0;
	printf("%c",dizi[0]);
	int a,b;
	char tmp;
    i=0;
	for(a=1;a<=9;a++)
	{
		for(b=0;b<=9;b++)
		{
			if(dizi[b]>dizi[b+1])
			{

				tmp=dizi[b];
				dizi[b]=dizi[b+1];
				dizi[b+1]=tmp;


			}
		}
	}
	for(i=0;i<10;i++)
	{
		printf("%c",dizi[i]);
	}
}
