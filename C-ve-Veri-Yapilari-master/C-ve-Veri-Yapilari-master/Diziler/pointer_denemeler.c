#include<stdio.h>

int main()
{
    printf("Sinif kac kisilik: ");
    int a;
    scanf("%d",&a);
    int *p=(int*) malloc(sizeof(int)*a);
    int i=0;float toplam=0;
    printf("Notlari girin: \n");
    for(i=0;i<a;i++)
    {
        printf("\n%d nci kisinin notu : ",i+1);
        scanf("%d",(p+i));
        toplam+=*(p+i);
    }
    printf("Ortalama : %.2f ",toplam/a);
}
