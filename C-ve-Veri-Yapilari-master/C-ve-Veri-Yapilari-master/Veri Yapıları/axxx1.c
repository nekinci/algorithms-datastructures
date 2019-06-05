#include<stdio.h>
#include<stdlib.h>

struct n{
    int data;
    struct n *next;
};
typedef struct n node;
int dogrusalAra(int dizi[],int aranan,int i,int N){

    if(dizi[i]==aranan)
        return i;
    i++;
    if(i<N){
        return dogrusalAra(dizi,aranan,i,N);
    }
    else
        return -1;
}
node* sil(node *n,int data){
    if(n==NULL)
        return NULL;
    if(n->data==data){
        return n->next;
    }

    else{
        return sil(n->next,data);
    }
}
int topla(int a){
    if(a==0)
        return 0;
    topla(a-1);
    printf("%d ",a);
}
int main(){
    int dizi[10]={0,1,2,3,4,5,6,7,8,9};

    topla(10);
}
