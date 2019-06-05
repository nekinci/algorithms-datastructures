#include<stdio.h>
#include<stdlib.h>

int *diziSirala(int dizi[],int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i;j<n;j++){
            if(dizi[j]<dizi[min])
                min=j;
        }
        int tmp=dizi[i];
        dizi[i]=dizi[min];
        dizi[min]=tmp;
    }
    return dizi;
}

int main(){
    int dizi[]={5,4,3,2,1};
    dizi=diziSirala(dizi,5);
    for(int i=0;i<5;i++)
        printf("%d ",dizi[i]);
}
