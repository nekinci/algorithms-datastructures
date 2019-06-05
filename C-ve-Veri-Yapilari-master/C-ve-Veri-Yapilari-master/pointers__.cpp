#include<stdio.h>
#include <stdlib.h>
int main(){
	
	int a = 5;
	int *ptr;
	ptr = &a;
	printf("\n a : %d ",a);
	printf("\n &a: %p ",&a);
	printf("\n ptr: %p ", ptr);
	printf("\n *ptr: %d ", *ptr);
	printf("\n &ptr: %p ", &ptr);	

	int *pptr;
	pptr = ptr;
	printf("\n *pptr : %p ",*pptr);
//	printf("\n **pptr : %d ",**pptr);
	printf("\n &pptr : %p ",&pptr);
	printf("\n pptr : %p ", pptr);
	
	int **dizi = (int **) malloc(sizeof(int *) * 5);
	
	for(int i = 0; i < 5; i++)
		*(dizi+i) = (int *)  malloc(sizeof(int) * 5);
	
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			dizi[i][j] = i * j;
	for (int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++)
			printf("\t %d ", dizi[i][j]);
		printf("\n");
	}
	return 0;
	

}
