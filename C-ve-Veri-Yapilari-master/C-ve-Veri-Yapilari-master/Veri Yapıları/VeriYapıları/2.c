#include<stdio.h>
#include<stdlib.h>

struct n{
    int data;
    struct n *next;
};

typedef struct n node;
node * add(node*,int);
void append(node* root, int data);
void printNode(node* r);
void main(){
    node * r;
    r=(node*) malloc(sizeof(node));
    r->data=10;
    r->next->data=20;
    r->next->next=r;
    printNode(r);


}
void append(node *root,int data){
    //Sona ekleme işlemi;
    node *iter=root;
    while(iter->next!=root){
        iter=iter->next;
    }
    iter->next=(node*) malloc(sizeof(node));
    iter->next->data=data;
    iter->next->next=root;
}


node * add(node *r,int data){
    if(r==NULL){
        r=(node *) malloc(sizeof(node));
        r->data=data;
        r->next=r;
        return r;
    }
   if(r->data>data){
        node *temp=(node*) malloc(sizeof(node));
        temp->data=data;
        temp->next=r;
        r->next=temp;
        r=temp;
        return r;
   }
   node *iter=r;
  do{
    iter=iter->next;
  }while(iter->next->data <=data&&iter->next!=r);
  node *temp=(node *) malloc(sizeof(node));
  temp->data=data;
  iter->next=temp;
  temp->next=r;
  return r;

}
void printNode(node *r){
    node *iter=r;
    do{
        printf("%d\t",iter->data);
        iter=iter->next;
    }while(iter!=r);

 }

