#include<stdio.h>
#include<stdlib.h>

struct n{
    int data;
    struct n *next;
};
typedef struct n node;

//prototip tanımları
node * add(node *, int); //sıralı ekleme
node * removex(node *, int);
void print(node *);
void append(node *,int );
void main(){
   node *root=NULL;
    root=add(root,400);
    root=add(root,40);
    root=add(root,4);
    root=add(root,450);
    root=add(root,50);
    print(root);
    removex(root,50);
    print(root);
    removex(root,60);
    print(root);
    removex(root,4);
    print(root);
}
void print(node *r){
    while(r!=NULL){
        printf("%d ",r->data);
        r=r->next;
    }
    printf("\n");
}
node *add(node *r,int x){
    if(r==NULL){
        //boşsa
        r=(node *) malloc(sizeof(node));
        r->next=NULL;
        r->data=x;
        return r;
    }
    if(r->data>x){
        //en başa ekleme durumu
        node *temp=(node *) malloc(sizeof(node));
        temp->data=x;
        temp->next=r;
        return temp;
    }
    node *iter=r;
    while(iter->next!=NULL&&iter->next->data<x){
        iter=iter->next;
    }
    node *temp=(node *) malloc(sizeof(node));
    temp->next=iter->next; //50nin sonrakisi 400 olacak.
    iter->next=temp; //40ın sonrakisi 50 olacak;
    temp->data=x;
    return r;

}
node * removex(node * r, int x){
    node *temp;
    node *iter=r;
    if(r->data==x){
        temp=r;
       	r=r->next;
        free(temp);
        return r;
    }
    while(iter->next!=NULL&&iter->next->data!=x){
        iter=iter->next;
    }
    if(iter->next==NULL){
        printf("Sayi bulunamadi");
        return r;
    }
    temp=iter->next;
    iter->next=iter->next->next;
    free(temp);
    return iter;
}
