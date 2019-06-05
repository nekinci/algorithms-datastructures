#include<stdio.h>
#include<stdlib.h>
#include "queue_arr.h"

int *dizi=NULL;
int sira=0,sirabasi=0,boyut=2;
int deque(){
    if(sira==sirabasi){
        printf("Sira Bos!");
        return -1;
    }
    if(sira-sirabasi<boyut/4){
        int *dizi2=(int*) malloc(sizeof(int)*boyut/2);
        for(int c=0;c<sira-sirabasi;c++)
            dizi2[c]=dizi[c+sirabasi];
        sira-=sirabasi;
        sirabasi=0;
        boyut/=2;
        free (dizi);
        dizi=dizi2;
    }
    return dizi[sirabasi++];

}
void toparla(){
    if(sirabasi==0)
        return ;
    int i;
    for(i=0;i<boyut;i++){
        dizi[i]=dizi[i+sirabasi];
    }
    sira-=sirabasi;
    sirabasi=0;
}
void enque(int a){
    if(dizi==NULL)
        dizi=(int *) malloc(sizeof(int)*2);

    if(sira>=boyut){
        boyut*=2;
        int *dizi2=(int*) malloc(sizeof(int)*boyut);
        int i;
        for(i=0;i<boyut/2;i++)
            dizi2[i]=dizi[i];
        free (dizi);
        dizi=dizi2;
    }
    dizi[sira++]=a;
}
void bastir(){
    int i;
    for(i=0;i<sira;i++)
        printf("%d ",dizi[i]);
}
int main(){
    for(int j=0;j<20;j++)
        enque(j*10);
    for(int a=0;a<10;a++)
        printf("%d ",deque());
    toparla();
    for(int j=0;j<20;j++)
        enque(j*10);
    for(int a=0;a<30;a++)
        printf("%d ",deque());

}
