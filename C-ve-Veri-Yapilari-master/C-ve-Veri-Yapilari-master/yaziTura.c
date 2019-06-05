#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int paraAt(void)
{
	int i;
	
	srand(time(NULL));
	
	int yazi = 0, tura = 0;
	for(int a=1; a<=100; a++)
	{
		i = rand() % 2;
	if (i == 0)
	{
		printf("\nYazi");
		yazi++;
	}
	else{
		printf("\nTura");
		tura++;
}
	}
	printf("\nTura: %d\n Yazi: %d", tura, yazi);
}

int main()
{
	
	paraAt();
	getch();

}