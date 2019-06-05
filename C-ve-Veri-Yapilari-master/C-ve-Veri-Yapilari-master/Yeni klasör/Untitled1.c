#include<stdio.h>

int main()
{
	unsigned a,b,sonuc;
	char islem;
	printf("Sayi girin: ",&a,&b);
	printf("\nIslemi girin: ");
	fflush(stdin);	
	scanf("%c",&islem);
	switch(islem)
	{
		case '&': sonuc=a&b; break;
		case '|': sonuc=a|b; break;
		case '^': sonuc=a^b; break;
		case '~' :sonuc=~b; break;
		default: printf("yanlis"); break;
	}
	printf("Sonuc: %d ",sonuc);
}
