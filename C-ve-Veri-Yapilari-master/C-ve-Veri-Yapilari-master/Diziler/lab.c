#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
 int no;
 char not4[5];
}sinif;
int main()
{
    int n=5;
    sinif *ogrenciler=(sinif*) malloc(sizeof(sinif)*n);
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("No girin: ");
        scanf("%d",&ogrenciler[i].no);
        printf("Not girin: ");
        fflush(stdin);
        scanf("%s",ogrenciler[i].not4);
    }
    for(i=0;i<n;i++)
    {
        printf("No: %d........Not: %s\n",(ogrenciler+i)->no,(ogrenciler+i)->not4);
    }
    ogrenciler=realloc(ogrenciler,sizeof(sinif)*10);
    (ogrenciler+6)->no=5;

    strcpy((ogrenciler+6)->not4,"C");
    for(i=0;i<n+n;i++)
    {
        printf("No: %d........Not: %s\n",(ogrenciler+i)->no,(ogrenciler+i)->not4);
    }

}
