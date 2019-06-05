#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define BOYUT 3600

int zar_at(int,int,int[]);
int main()
{
    int zar_table[BOYUT][BOYUT];
    int zar_hafiza[36];
    int i,zar1,zar2;
    for(i=0;i<3600;i++)
    {
        zar_at(zar1,zar2,zar_hafiza);

    }

}
int zar_at(int a,int b)
{
    srand(time(NULL));
    a=1+rand()%6;
    b=1+rand()%6;
    return a+b;
}
