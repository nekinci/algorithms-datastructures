#include <stdio.h> // programa giriþ çýkýþ kütüphanesini ekledik. // ön iþlemcilerde noktalý virgül olmaz.
#include<conio.h> //karakter alma iþlemleri kütüphanesi
int main()
{
int x;
scanf("%d",&x);
if(x%2==0)
{
	printf("%d sayisi cifttir",x);
}
else
	printf("%d sayisi tektir",x);
return 0;
	
}
