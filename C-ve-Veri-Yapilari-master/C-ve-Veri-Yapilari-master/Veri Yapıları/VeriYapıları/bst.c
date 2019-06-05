#include<stdio.h>
#include<stdlib.h>

 struct n{
    int data;
    struct n *left;
    struct n *right;
};
typedef struct n node;

node * ekle(node*agac,int data){
    if(agac==NULL){
        node *root =(node*) malloc(sizeof(node));
        root->data=data;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    if(agac->data<data){
        agac->right=ekle(agac->right,data);
        return agac;
    }
    agac->left=ekle(agac->left,data);
    return agac;

}
int max(node *agac){

    while(agac->right!=NULL)
        agac=agac->right;
    return agac->data;
}
int min(node* agac){
    while(agac->left!=NULL)
        agac=agac->left;
    return agac->data;
}
void dolas(node * agac){
    if(agac==NULL)
        return ;
    dolas(agac->left);
    printf("%d ",agac->data);
    dolas(agac->right);
}
node *yerDegis(node *r){
    node *temp=r->left;
    r->left=r->right;
    r->right=temp;
    return r;
}
int bul(node * agac,int aranan){
    if(agac==NULL)
        return -1;
    if(agac->data==aranan)
        return 1;
    if(bul(agac->right,aranan)==1)
        return 1;
    if(bul(agac->left,aranan)==1)
        return 1;
    return -1;
}
node *sil(node * agac,int data){
    if(agac==NULL)
        return NULL;
    if(agac->data==data){
        if(agac->left==NULL&&agac->right==NULL)
            return NULL;
        if(agac->right!=NULL){
            agac->data=min(agac->right);
            agac->right=sil(agac->right,min(agac->right));
            return agac;
        }
        agac->data=max(agac->left);
        agac->left=sil(agac->left,max(agac->left));
        return agac;

    }
    if(agac->data < data){
        agac->right=sil(agac->right,data);
        return agac;
    }
    agac->left=sil(agac->left,data);
    return agac;
}
int main(){
    node *agac=NULL;
    agac=ekle(agac,28);
    agac=ekle(agac,56);
    agac=ekle(agac,26);
    agac=ekle(agac,24);
    agac=ekle(agac,12);
    agac=ekle(agac,18);
    agac=ekle(agac,27);
    agac=ekle(agac,190);

    agac=ekle(agac,213);
    agac=ekle(agac,200);
    printf("max : %d min: %d \n",max(agac),min(agac));
    dolas(agac);
    printf("\n");
    agac=yerDegis(agac);
    printf("\n");
    dolas(agac);
    agac=sil(agac,56);
    agac=sil(agac,213);
    agac=sil(agac,28);
    agac=sil(agac,26);
    agac=sil(agac,27);
    //dolas(agac);

}
