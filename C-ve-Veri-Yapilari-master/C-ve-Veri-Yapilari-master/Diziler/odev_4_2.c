#include<stdio.h>
#define ArSIZE 50
int katar_ara(char[][ArSIZE],char[],int boyut);
int main()
{
    int a,i;
    puts("Kac tane string girmek istiyorsunuz.. :" );
    scanf("%d",&a);
    char string[a][ArSIZE];
    printf("Bir seyler yazin.. : ");
    for(i=0;i<a;i++)
        scanf("%s",string[i]);
    for(i=0;i<a;i++)
    puts(string[i]);
    puts("Aramak istediginiz kelimeyi giriniz.. : ");
    char aranan[ArSIZE];
    scanf("%s",aranan);
    int sonuc= katar_ara(string,aranan,a);
    if(sonuc!=-1)
        printf("%d icinde buludu!",sonuc);
    else
        printf("%s","Bulunamadi");


}
int katar_ara(char Ary[][ArSIZE],char aranan[],int boyut)
{
    int x=0,y=0;
    for(x=0;x<boyut;x++)
    {
        for(y=0;aranan[y]==Ary[x][y];y++)
        {
            if(Ary[x][y]=='\0')
                return x;
        }

    }
    return -1;
}

