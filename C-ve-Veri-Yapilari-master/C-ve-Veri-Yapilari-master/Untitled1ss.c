#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int sayi;
    struct NODE *sonraki;
};
void main(){
    struct NODE *baslangic=(struct NODE*) malloc(sizeof(struct NODE));
    baslangic->sayi=5;
    struct NODE *iki=(struct NODE*) malloc(sizeof(struct NODE));
    iki->sayi=6;
    baslangic->sonraki=iki;
    struct NODE *kontrol=(struct NODE*) malloc(sizeof(struct NODE));
    kontrol->sayi=7;
    iki->sonraki=kontrol;
    kontrol->sonraki=NULL;
    int dizi[5];
    int i=0;
    while(baslangic!=NULL){
        dizi[i]=baslangic->sayi;
        i++;
        baslangic=baslangic->sonraki;
    }
    for(i=0;dizi[i]!=NULL;i++){
        printf("%d",dizi[i]);
    }
}
/*
while(baslangic,iki,kontrol)
    baslangic eşit mi null ? hayır
    dizi[0]=baslangıcın sayısı
    i yi arttırdık
    baslangic= baslangicin sonrakisi ? baslangicin sonrakisi =iki;
    dizi[1]=ikinin sayısı
    i yi bir attırdık
    iki= iki->sonraki;
    kontrol=kontrol->sonraki;

*/
