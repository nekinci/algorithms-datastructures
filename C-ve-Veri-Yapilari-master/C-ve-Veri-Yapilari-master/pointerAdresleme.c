#include<stdio.h>

int main()
{
	int*p, a;
	a = 10;
	p = &a;
	printf("\n %d",a );  // a n�n de�eri
	printf("\n %d",&a ); // a n�n adresi
	printf("\n %d",*p ); //p de�i�keninin e�itlendi�i b�lge(a de�i�keni) nin i�eri�i
	printf("\n %d",p ); //p de�i�keninin e�itlendi�i b�lge(a de�i�keni) nin adresi
	printf("\n %d",&p ); //p de�i�keninin as�l adresi
	getch();

/*

	-----------------------------------------
	-   a	|   &a	|  *p  	|   &p	 |  p	-
	-----------------------------------------
	-  10 	| A0f0	|   10	| B0a0	 | A0f0	-
	-	|	|	|	 |	-
	-	|	|	|	 |	-
	-	|	|	|	 |	-
	-	|	|	|	 |	-
	-----------------------------------------

*/

}
