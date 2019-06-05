#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define BOYUT 8

typedef struct{
    char tip;
    int etki;
    int yapildi_mi;

}patlayici;
int skor=10;

void ilklendir(patlayici d[][8]);
void goster(patlayici d[][8]);
void hamle_yap(int satir, int sutun, patlayici d[8][8]);
void komsulari_tara(int satir, int sutun, patlayici d[8][8]);
void puani_guncelle(patlayici *a);
int main()
{
    patlayici oyun_alani[8][8];
    ilklendir(oyun_alani);
    goster(oyun_alani);
    int satir,sutun;
    do{
        printf("Puaniniz: %d",skor);
        printf("\nSeciminiz: ");
        scanf("%d%d",&satir,&sutun);
        hamle_yap(satir,sutun,oyun_alani);
        goster(oyun_alani);


    }while(skor>0);

}
void ilklendir(patlayici d[][8])
{
    int i,j;
    for(i=0;i<BOYUT;i++)
    {
        for(j=0;j<BOYUT;j++)
        {
            d[i][j].tip='O';
            d[i][j].etki=0;
            d[i][j].yapildi_mi=0;
        }
    }
    int a,b;
    srand(time(NULL));
    i=0;
    while(i<=8)
    {
        a=rand()%8;
        b=rand()%8;
        switch(i)
        {
            case 0:case 1:d[a][b].etki=2;d[a][b].tip='M';d[a][b].yapildi_mi=0;break;
            case 2:case 3:d[a][b].etki=4;d[a][b].tip='D';d[a][b].yapildi_mi=0;break;
            case 4:case 5:d[a][b].etki=6;d[a][b].tip='R';d[a][b].yapildi_mi=0;break;
            case 6:case 7:d[a][b].etki=8;d[a][b].tip='A';d[a][b].yapildi_mi=0;break;
            case 8:d[a][b].etki=10;d[a][b].tip='N';d[a][b].yapildi_mi=0;break;
            default:d[a][b].etki=0;d[a][b].tip='O';d[a][b].yapildi_mi=0;break;
        }
        i++;
    }
}
void goster(patlayici d[][8])
{
    int i,j;
    system("clear");
    for(i=0;i<BOYUT;i++)
    {
        for(j=0;j<BOYUT;j++)
        {
            if(d[i][j].yapildi_mi!=2)
                printf("%c\t",d[i][j].tip);
            else
                printf("%c\t",'O');
        }

        printf("\n");
    }

}
void hamle_yap(int satir, int sutun, patlayici d[8][8])
{
    if(d[satir][sutun].yapildi_mi==1||d[satir][sutun].yapildi_mi==2)
    {
        printf("\nAcilmis Alan!");
    }
    else
    {
        if(d[satir][sutun].tip=='O')
        {
            komsulari_tara(satir,sutun,d);
            goster(d);
        }
        else
        {
            puani_guncelle(&d[satir][sutun]);
        }

    }

}
void komsulari_tara(int satir, int sutun, patlayici d[8][8])
{
    int i,j;
    for(i=satir-1;i<=satir+1;i++)
    {
        for(j=sutun-1;j<=sutun+1;j++)
        {
            if(d[i][j].tip!='O')
                d[i][j].yapildi_mi=2;
            else
            {
                d[i][j].tip='X';
                d[i][j].yapildi_mi=1;
            }

        }
    }
}
void puani_guncelle(patlayici *a)
{
    skor=skor-a->etki;
    a->yapildi_mi=2;
}
