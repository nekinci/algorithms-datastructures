#include<stdio.h>

int main()
{
	int*p, a;
	a = 10;
	p = &a;
	printf("\n %d",a );  // a nýn deðeri
	printf("\n %d",&a ); // a nýn adresi
	printf("\n %d",*p ); //p deðiþkeninin eþitlendiði bölge(a deðiþkeni) nin içeriði
	printf("\n %d",p ); //p deðiþkeninin eþitlendiði bölge(a deðiþkeni) nin adresi
	printf("\n %d",&p ); //p deðiþkeninin asýl adresi
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
