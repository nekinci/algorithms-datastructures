#include<stdio.h>
#include<stdlib.h>

int tepe=0;
int boyut=2;
int *dizi;
int i;
void push(int a){
    if(dizi==NULL){
        dizi=(int *) malloc(sizeof(int)*2);
    }
    if(tepe>=boyut){
        int *dizi2=(int *) malloc(sizeof(int)*2*boyut);
        for(i=0;i<boyut;i++)
            dizi2[i]=dizi[i];
        free(dizi);
        dizi=dizi2;
        boyut*=2;
    }
    dizi[tepe++]=a;
}
int pop(){
    if(tepe<=(boyut/4)){
        int *dizi2=(int *) malloc(sizeof(int)*2*(boyut/2));
        for(i=0;i<boyut;i++)
            dizi2[i]=dizi[i];
        free(dizi);
        dizi=dizi2;
        boyut/=2;
    }
    return dizi[--tepe];
}
void bastir(){
    for(i=0;i<tepe;i++){
        printf("%d -> Değer\nBoyut -> %d\n",dizi[i],boyut);
    }
}

int main(){
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    bastir();

}
