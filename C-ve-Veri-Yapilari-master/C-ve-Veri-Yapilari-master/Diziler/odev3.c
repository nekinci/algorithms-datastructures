#include<stdio.h>
#include <string.h>
#define LINE 10
#define COLUMN 1
char sirala(int[][COLUMN],int,int);
int main()
{
	char strings[LINE][COLUMN];
	int i,j;
	for(i=0;i<=LINE-1;i++)
	{
		for(j=0;j<COLUMN;j++)
            scanf("%s",&strings[i][j]);
        strings[i][j]='\0';
	}
    printf("\n\n%s\n\n",&strings[0]);
	for(i=0;i<=LINE-1;i++)
	{
		for(j=0;j<=COLUMN-1;j++)
			printf("%s\n",strings[i]);
		printf("\n");
	}
	/*
    int a,b,tmp;
    i=0;
	for(a=1;a<=LINE-1;a++)
	{
		for(b=0;b<=LINE-2;b++)
		{
			if(strcmp(strings[i][0],strings[i+1][0]))
			{

				strcpy(tmp,strings[i]);
				strcpy(strings[i],strings[i+1]);
				strcpy(strings[i+1],tmp);
				i=0;

			}
		}
	}*/
}
char sirala(int array[][COLUMN],int satir,int sutun)
{
	int a,b,tmp;
	for(a=0;a<=satir-1;a++)
	{
		for(b=0;b<=satir-2;b++)
		{
			if(strcmp(array[a],array[a+1])!=0 || strcmp(array[a],array[a+1]>0))
			{

				strcpy(tmp,array[a]);
				strcpy(array[a],array[a+1]);
				strcpy(array[a+1],tmp);

			}
		}
	}
	return array[satir][sutun];
}
