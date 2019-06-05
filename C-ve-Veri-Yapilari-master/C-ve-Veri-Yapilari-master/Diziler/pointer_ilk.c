#include<stdio.h>

int main()
{
    int a=10;
    int *p;
    p=&a;
    printf("\np : %d",p); // a nın adresi
    printf("\n*p : %d",*p); // a nın içeriği
    printf("\n&p : %d",&p);  //p nin adresi
    printf("\na : %d",a); // a nın içeriği
    printf("\n&a : %d",&a); // a nın adresi


}
