#include<stdio.h>
#include<stdlib.h>

struct n{
    int data;
    struct n *next,*prev;
};

typedef struct n node;


node *siraliEkle(node*r,int data){
    node *temp=(node*) malloc(sizeof(node));
    if(r==NULL){
        r=(node*) malloc(sizeof(node));
        r->data=data;
        r->prev=NULL;
        r->next=NULL;
        return r;
    }
    if(r->data>data){
        temp->data=data;
        temp->next=r;
        temp->prev=NULL;
        r->prev=temp;
        return temp;
    }
    node *iter=r;
    while(iter->next!=NULL&&iter->next->data <data){
        iter=iter->next;
    }
    temp->data=data;
    //iter->next->prev=temp;
    //temp->prev=iter;
    temp->next=iter->next;
    iter->next=temp;
    temp->prev=iter;
    if(temp->next!=NULL)
        temp->next->prev=temp;
    return r;
}

void bastir(node *r){
    node *iter=r;
    while(iter!=NULL){
        printf("%d ",iter->data);
        iter=iter->next;
    }
    printf("\n");
}
node *sil(node *r,int data){
    node *iter=r;
    if(r->data==data){
        node *temp;
        r->next->prev=NULL;
        temp=r;
        r=r->next;
        free(temp);
        return r;
    }
    while(iter!=NULL&&iter->data!=data){
        iter=iter->next;
    }
    if(iter==NULL){
        printf("Sayi Bulunamadi!");
        return r;
    }
    node *temp=iter;
    iter->prev->next=iter->next;
    if(iter->next!=NULL)
        iter->next->prev=iter->prev;
    free(temp);
    return r;
}

void main(){
    node *r;
    r=siraliEkle(r,9);
    r=siraliEkle(r,4);
    r=siraliEkle(r,8);
    r=siraliEkle(r,3);
    r=siraliEkle(r,5);
    r=siraliEkle(r,15);
    r=siraliEkle(r,13);

    bastir(r);

    r=sil(r,5);
    bastir(r);
    r=sil(r,9);
    bastir(r);
    r=sil(r,15);
    bastir(r);
    r=sil(r,13);
    bastir(r);
    }



/*
    Kendi yazmış olduğum silme metodu:

    node *iter=r;
    if(r->data==data){
        node *temp;
        r->next->prev=NULL;
        temp=r;
        r=r->next;
        free(temp);
        return r;
    }
    while(iter!=NULL&&iter->data!=data){
        iter=iter->next;
    }
    if(iter==NULL){
        printf("Sayi Bulunamadi!");
        return r;
    }
    node *temp=iter;
    iter->prev->next=iter->next;
    if(iter->next!=NULL)
        iter->next->prev=iter->prev;
    free(temp);
    return r;

*/



/*
    Sadi Hocanın Algoritması:


    node *iter=r;
    node *temp;
   if(r->data==data){
        temp = r;
        r=r->next;
        free(temp);
        return r;
   }
   while(iter->next!=NULL&&iter->next->data!=data){
        iter =iter->next;
   }
   if(iter->next==NULL){
    printf("Sayi Bulunamadi");
    return r;
   }
   temp=iter->next;
   iter->next=iter->next->next;
   free(temp);
   if(iter->next!=NULL)
        iter->next->prev=iter;
   return r;

*/
