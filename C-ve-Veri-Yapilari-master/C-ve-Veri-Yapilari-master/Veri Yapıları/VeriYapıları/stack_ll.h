#ifndef stack_ll
#define stack_ll

struct n{
    struct n *next;
    int data;
};
typedef struct n node;
int pop(node *);
node* push(node*,int);
node *pushOne(node*,int);
node * popOne(node *r);
node * updateNode(node* r);
void bastir(node *r);
#endif
