#include<stdio.h>
#include<stdlib.h>

struct n{
    int x;
    struct n* next;};
typedef struct n node;
void main(void){
    //linklist (bağlı liste kullanımı)

    node *root; //root adında ilk değeri tanımladık.
    root=(node*) malloc(sizeof(node)); //bellekten yer ayırdık malloc sayesinde node kadar.
    root->x=10; // root un x değerini 10 yaptık.
    root->next =(node *) malloc(sizeof(node)); //rootun sonraki değerini pointer ile gösterip yer açtık.
    root->next->x=20; //değerini 20 yaptık.
    root->next->next=(node *) malloc(sizeof(node));
    root->next->next->x=30;
    root->next->next->next=NULL;
    node *iter;
    iter=root;
    printf("%d",iter->x);
    iter=iter->next;
    printf("%d",iter->x);
    iter=iter->next;
    printf("%d",iter->x);
    iter=root;
//    printf("%d",iter->x);
    while(iter->next!=NULL){
        iter=iter->next;
    }
    int i=0;
    for(i=0;i<40;i+=10){
        iter->x=40+i;
        printf("%d",iter->x);
        iter=iter->next=(node *) malloc(sizeof(node));
        iter->next=NULL;
    }
}
