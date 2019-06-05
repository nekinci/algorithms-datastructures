#include<stdio.h>
#include<stdlib.h>
#define STRLENGTH 50
struct Rehber{
    char ilkHarf;
    struct Kayit *ilkKayit;
};
struct Kayit{
    char ad[STRLENGTH];
    char soyad[STRLENGTH];
    int telno;
    struct Kayit *sonrakiKayit;
};
//typedef tanimi
typedef struct Rehber rehber;
void ilklendir(rehber *r);
void yazdir(rehber *r);

int main(){
    rehber *r1=(rehber*) malloc(sizeof(rehber)*26);
    ilklendir(r1);
    yazdir(r1);
    (r1+0)->ilkKayit->telno=55;
    (r1+0)->ilkKayit->sonrakiKayit=NULL;
}
void ilklendir(rehber *r){
    int i=0;
    char c;
    for(c='A';c<='Z';c++,i++){
        (r+i)->ilkHarf=c;
        (r+i)->ilkKayit=NULL;
    }
}
void yazdir(rehber *r){
    int i=0;
    for(i=0;i<26;i++){
        printf("%c ",(r+i)->ilkHarf);
    }
}
