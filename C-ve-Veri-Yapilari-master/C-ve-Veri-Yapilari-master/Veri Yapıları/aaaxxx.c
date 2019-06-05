#include<stdio.h>
#include<stdlib.h>

int ara(int dizi[],int N ,int max,int min,int aranan){
    int i=0;
    while(max-min>1){
        int orta=(max+min)/2;
        if(dizi[orta]==aranan){
            return orta;
        }
        else if(dizi[orta]>aranan){
            max=orta;
        }
        else
            min=orta;
    }
}
int binarySearchR(int dizi[],int max,int min,int aranan){
    int orta=(max+min)/2;
    if(dizi[orta]==aranan)
        return orta;
    else{
        if(dizi[orta]>aranan)
            return binarySearchR(dizi,orta,min,aranan);
        if(dizi[orta]<aranan)
            return binarySearchR(dizi,max,orta,aranan);
    }
}
int main(){
    int dizi[10]={1,2,3,4,5,6,7,8,9,10};
    printf("%d de bulundu. ",ara(dizi,10,10,-1,5));
    printf("\nÖzyinelemeli: %d de bulundu. ",binarySearchR(dizi,10,-1,10));
}
