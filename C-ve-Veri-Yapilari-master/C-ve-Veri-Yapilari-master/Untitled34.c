#include<stdio.h>
#include<time.h>
void santigrat_olustur(FILE*);
void kelvin(FILE*);
int main()
{
    FILE *s;
    santigrat_olustur(s);
    kelvin(s);
}
void kelvin(FILE *p)
{
 p=fopen("santigrat.txt","r");
 FILE *q;
 q=fopen("kelvin.txt","w");
 if(p==NULL||q==NULL)
    puts("Hata");
 int i=0,kelvin=0,santigrat;
 for(i=0;i<25;i++)
 {
     fscanf(p,"%d\n",&santigrat);
     printf("Santigrat: ",santigrat);
     kelvin=santigrat+273;
     fprintf(q,"%d\n",kelvin);
 }

}
void santigrat_olustur(FILE *p)
{
    srand(time(NULL));
    p=fopen("santigrat.txt","w");
    if(p==NULL)
        printf("Acilamadi");
    int i=0,santigrat=0;
    for(i=0;i<25;i++)
    {
        santigrat=rand()%101;
        fprintf(p,"%d\n",santigrat);
    }
    fclose(p);
}
