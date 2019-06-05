#include<stdio.h>

int main()
{
        int satici[50],maas[50];
        int n=50,i;
        printf("Kac eleman calistiriyorsunuz.. : ");
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            printf("?");
            scanf("%d",&maas[i]);
            satici[i]=200+9*maas[i]/100;
            printf("Maas : %d",satici[i]);

        }
}
