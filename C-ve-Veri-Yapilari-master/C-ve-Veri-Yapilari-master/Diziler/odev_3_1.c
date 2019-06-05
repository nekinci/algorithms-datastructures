#include<stdio.h>
#define KELIME 10
#define HARF 50
#include<string.h>
int main()
{
    char strings[KELIME][HARF];
    int i,a,b;
    char tmp[HARF];
    for(i=0;i<=KELIME-1;i++)
        scanf("%s",strings[i]);

    for(a=0;a<=KELIME-1;a++)
    {
        for(b=a+1;b<=KELIME-2;b++)
        {
            if(strcmp(strings[a],strings[b])>0)
            {
                strcpy(tmp,strings[a]);
                strcpy(strings[a],strings[b]);
                strcpy(strings[b],tmp);
            }
        }
    }
    for(i=0;i<=KELIME-1;i++)
    {
        printf("\n%s",strings[i]);
    }
}
