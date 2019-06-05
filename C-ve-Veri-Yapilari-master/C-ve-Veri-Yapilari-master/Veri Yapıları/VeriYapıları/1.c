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

node *sil(node*r,int data){
    node *iter=r;
    node *temp;
   if(r->data==data){
        temp = r;
        free(temp);
        return r->next;
   }
   while(iter->next!=NULL&&iter->next->data!=data){
        iter =iter->next;
   }
   if(iter->next==NULL){
    printf("Sayi Bulunamadi");
   }
   temp=iter->next;
   iter->next=iter->next->next;
   free(temp);
   return r;

}

void main(){
   // node *root; // ilk tanımlama
    //root=(node *) malloc(sizeof(node)); //bellek ayrımı
    //root->data=10; //ilk değer ataması
    //root->next=NULL; //Append ederken bellekte rasgele dolu olan yerin çakışmaması için.
//    append(root,20);
  //  append(root,30);
   // append(root,40);
   // printNode(root);
    //iter le araya ekleme işlemi
   /* node *iter=root;
    int i=0;
    for(i=0;i<1;i++){
        iter=iter->next;
    }
    node *tmp=(node*) malloc(sizeof(node));
    tmp->data=25;
    tmp->next=iter->next;
    iter->next=tmp;
    printf("\n");
    printNode(root);*/
    node * r;
    r=NULL;
    r = add(r,400);
    r->next->data=29;
    r->next->next=NULL;
    printNode(r);


}
void append(node *root,int data){
    //Sona ekleme işlemi;
    while(root->next!=NULL){
        root=root->next;
    }
    root->next=(node*) malloc(sizeof(node));
    root->next->data=data;
    root->next->next=NULL;
}


node * add(node *r,int data){
    if(r==NULL){
        r=(node *) malloc(sizeof(node));
        r->data=data;
        r->next=NULL;
        return r;
    }
   if(r->data>data){
        node *temp=(node*) malloc(sizeof(node));
        temp->data=data;
        temp->next=r;
        r=temp;
        return r;
   }
   node *iter=r;
  while(iter->next!=NULL&&iter->next->data<data){
    iter=iter->next;
  }
  node *temp=(node *) malloc(sizeof(node));
  temp->data=data;
  temp->next=iter->next;
  iter->next=temp;
  return r;

}
void printNode(node *r){
    while(r!=NULL){
        printf("%d\t",r->data);
        r=r->next;
    }
}
