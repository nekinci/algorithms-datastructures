#include<stdio.h>
#include<stdlib.h>

int dizi[2];
int tepe=0;
int boyut=2;
void push(int a){
    if(dizi==NULL);
//        dizi=(int*) malloc(sizeof(int));
    dizi[tepe++]=a;
    printf("%d ",tepe);
}
int pop(){
    printf("%d ",tepe);
    return dizi[--tepe];
}
void bastir(){
    int i;
    for(i=0;i<tepe;i++){
        printf("%d \nTepe: %d \n",dizi[i],tepe);
    }
}
int main(){
    int dizi2[1];
    dizi2[103]=5;
    printf("%d",dizi2[103]);
}
