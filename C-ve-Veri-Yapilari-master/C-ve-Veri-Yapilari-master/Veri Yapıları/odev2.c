#include<stdio.h>
#include<stdlib.h>

struct rehber{
    char ilkHarf;
    struct kayit *ilkKayit;
};
struct kayit{
    char ad[50];
    char soyad[50];
    int telNo;
    struct kayit *next;
};
int main(){

}
