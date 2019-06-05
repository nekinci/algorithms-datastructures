#include<stdio.h>

int rezerve_et(int,int[]);
int kontrol=0;
int main()
{
    printf("Sigara icilen bolum icin 1*e basin\nSigara icilmeyen bolum icin 2*e basin\n...\n");
    int koltuklar[10]={0};
    int c;
    char boole;
    scanf("%d",&c);
    int sonuc=rezerve_et(c,koltuklar);
    if(sonuc!=-1)
        printf("\n%d bolumunden %d numarali koltuk rezerve edilmistir.",c,sonuc+1);
    else
        {
            printf("%d bolumunde bos koltuk yoktur. %d bolumunden rezervasyon yaptirmak istermisiniz.. : ",c,c+1);
            scanf("%s",boole);
            if(boole=='e'||boole=='E')
                printf("3 saat sonra");
        }

}
int rezerve_et(int bolum,int koltuk[])
{
    int i=0;
    if(bolum==1)
    {
        for(i=0;i<5;i++)
        {
            if(koltuk[i]==0)
            {
             koltuk[i]++;
             return i;
            }

        }

    }
    else if(bolum==2)
    {
        for(i=5;i<10;i++)
        {
            if(koltuk[i]==0)
            {
                koltuk[i]++;
                return i;
            }

        }

    }
    return -1;

}
