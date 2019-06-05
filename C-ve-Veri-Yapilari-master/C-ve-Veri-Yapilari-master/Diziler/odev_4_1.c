#include<stdio.h>

int ara(int[],int,int);
int main()
{
    //Arama algoritması

    int a,i;
    printf("Kac sayi gireceksiniz.. : ");
    scanf("%d",&a);
    int array[a];
    for(i=0;i<=a-1;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Aramak istediginiz sayi nedir.. : ");
    int aranacak_sayi;
    scanf("%d",&aranacak_sayi);
    int sonuc=ara(array,aranacak_sayi,a);
    if(sonuc!=-1)
        printf("%d icinde bulundu",sonuc);
    else
        printf("Bulunamadi");

}
int ara(int c[],int aranan,int boyut)
{
    int s;
    for(s=0;s<boyut;s++)
    {
        if(aranan==c[s])
            return s;
    }
    return -1;
}
