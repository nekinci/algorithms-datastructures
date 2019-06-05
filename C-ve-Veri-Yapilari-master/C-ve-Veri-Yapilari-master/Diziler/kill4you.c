#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p;
    int a=8;
    p=(int*) calloc(a,sizeof(int));
    p[0]=0;
    int i=0,j;
    for(i=0;i<a;i++)
    {
        printf("%d",p[i]);
    }
}
