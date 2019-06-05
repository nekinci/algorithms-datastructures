#include<stdio.h>
#include<stdlib.h>

struct n
{
    int data;
    struct n *right,*left;
};
typedef struct n node;
node *add(node *r,int data){
    if(r==NULL){
        r=(node *) malloc(sizeof(node));
        r->data=data;
        r->left=NULL;
        r->right=NULL;
        return r;
    }
    if(r->data<data){
        r->right=add(r->right,data);
        return r;
    }
    r->left=add(r->left,data);
    return r;
}
void dolas(node *r){
    if(r==NULL)
        return;
    dolas(r->right);
    printf("%d ",r->data);
    dolas(r->left);
}
int bul(node *r,int data){
    if(r==NULL)
        return -1;
    if(r->data==data)
        return 1;
    if(data>r->data)
        return bul(r->right,data);
    return bul(r->left,data);
    if(r->data!=data)
        return -1;
}
node *sil(  )
int main()
{
    node *agac=NULL;
    agac=add(agac,10);
    agac=add(agac,100);
    agac=add(agac,5);
    agac=add(agac,4);
    agac=add(agac,6);
    agac=add(agac,110);
    agac=add(agac,90);
    agac=add(agac,15);
    dolas(agac);
    printf("\nBulunma durumu: %d",bul(agac,10));
}
