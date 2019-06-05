#include<stdio.h>
#include<time.h> // srand(timeNULL) yapabilmek için
#include<stdlib.h>
#define BOYUT 8
//global degisken struct tip tanimlamasi ve prototipler.

int skor=10;

typedef struct
{
    char tip;
    int tesir;
    int yapildi_mi;
}patlayici;

void oyun_baslangici(patlayici d[BOYUT][BOYUT]);
void oyun_alani_goster(patlayici d[BOYUT][BOYUT]);
void patlayici_yerlestir(patlayici d[BOYUT][BOYUT]); //random patlayicilari yerlestirmek icin fonksiyon kullandim.
void hamle_yap(int satir,int sutun,patlayici d[BOYUT][BOYUT]);
void komsulari_tara(int,int,patlayici d[][BOYUT]);
void puani_guncelle(patlayici *);


int main()
{
    patlayici oyun_alani[BOYUT][BOYUT];
    oyun_baslangici(oyun_alani);
    oyun_alani_goster(oyun_alani);
    int satir,sutun;
    do
    {
        printf("\tPuaniniz: %d",skor);
        printf("\n\tSeciminiz: ");
        scanf("%d%d",&satir,&sutun);
        patlayici_yerlestir(oyun_alani);
        hamle_yap(satir,sutun,oyun_alani);
    }while(skor>0);


}

void patlayici_yerlestir(patlayici d[BOYUT][BOYUT])
{
    int x,y,i=0;
    patlayici s[2][BOYUT+1];
    s[0][0].tesir=2;
    s[0][0].tip='M';
    s[0][0].yapildi_mi=0;
    s[0][1].tesir=2;
    s[0][1].tip='M';
    s[0][1].yapildi_mi=0;
    s[0][2].tesir=4;
    s[0][2].tip='D';
    s[0][2].yapildi_mi=0;
    s[0][3].tesir=4;
    s[0][3].tip='D';
    s[0][3].yapildi_mi=0;
    s[0][4].tesir=6;
    s[0][4].tip='R';
    s[0][4].yapildi_mi=0;
    s[0][5].tesir=6;
    s[0][5].tip='R';
    s[0][5].yapildi_mi=0;
    s[0][6].tesir=8;
    s[0][6].tip='A';
    s[0][6].yapildi_mi=0;
    s[0][7].tesir=8;
    s[0][7].tip='A';
    s[0][7].yapildi_mi=0;
    s[1][0].tesir=10;
    s[1][0].tip='N';
    s[1][0].yapildi_mi=0;
    srand(time(NULL));
    while(i<=8)
    {
        x=rand()%8;
        y=rand()%8;
        if(i<=7)
            d[x][y]=s[0][i];
        else
            d[x][y]=s[1][0];
        i++;

    }

}
void oyun_baslangici(patlayici d[BOYUT][BOYUT])
{
    int i,j;
    for(i=0;i<BOYUT;i++)
    {
        for(j=0;j<BOYUT;j++)
        {
            d[i][j].tesir=0;
            d[i][j].tip='O';
            d[i][j].yapildi_mi=0;
        }

    }
}
void oyun_alani_goster(patlayici s[BOYUT][BOYUT])
{
    int i,j;
    system("clear"); //ekranda gorunen bir onceki hamlenin goruntusunu silmek icin.
    for(i=0;i<BOYUT;i++)
    {
        for(j=0;j<BOYUT;j++)
        {
            printf("\t%c",s[i][j].tip);

        }
        printf("\n");
    }
}
void hamle_yap(int satir,int sutun,patlayici d[BOYUT][BOYUT])
{
    if(d[satir][sutun].tip=='O')
    {
        komsulari_tara(satir,sutun,d);
        oyun_alani_goster(d);
    }
    else if(d[satir][sutun].tip=='X')
        printf("\nAcilmis alan");
    else
        puani_guncelle(&d[satir][sutun]);
}
void komsulari_tara(int satir,int sutun,patlayici d[BOYUT][BOYUT])
{
    int i,j;
    if(satir-1>=0&&sutun-1>=0&&sutun+1<=7&&satir+1<=7)
    {
        for(i=satir-1;i<=satir+1;i++)
        {
            for(j=sutun-1;j<=sutun+1;j++)
            {
                if(d[i][j].tip!='O')
                    continue;
                else
                    d[i][j].tip='X';
            }
        }
    }

}
void puani_guncelle(patlayici *a)
{
    skor=skor-a->tesir;
}

