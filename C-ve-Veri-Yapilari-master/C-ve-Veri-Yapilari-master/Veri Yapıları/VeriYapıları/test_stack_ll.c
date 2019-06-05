#include<stdio.h>
#include<stdlib.h>
#include "stack_ll.h"
#include "stack_ll.c"

void main(){
    node *root=NULL;

    root=pushOne(root,1);
    root=pushOne(root,2);
    root=pushOne(root,3);
    root=pushOne(root,4);
   // bastir(root);
    root=popOne(root);
    printf("Çekilen eleman: %d\n",rValue);

    root=popOne(root);
    printf("Çekilen eleman: %d\n",rValue);

    root=popOne(root);
    printf("Çekilen eleman: %d\n",rValue);

    root=popOne(root);
    printf("Çekilen eleman: %d\n",rValue);

}
