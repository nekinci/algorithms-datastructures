#include <stdio.h> // programa giri� ��k�� k�t�phanesini ekledik. // �n i�lemcilerde noktal� virg�l olmaz.
#include<conio.h> //karakter alma i�lemleri k�t�phanesi
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
