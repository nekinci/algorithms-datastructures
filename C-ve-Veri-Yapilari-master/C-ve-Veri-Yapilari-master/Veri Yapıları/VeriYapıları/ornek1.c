#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 100
int linear_search(int arr[],int searched){
    int i=0;
    while(arr[i]!=searched&&i<SIZE)
        i++;
    if(i<SIZE)
        return i;
    else
        return -1;
}
void printToArray(int arr[]){
    for(int i=0;i<SIZE;i++)
        printf("%d ",arr[i]);
}
int main(){

    int numbers[SIZE];
    srand(time(NULL));
    for(int i=0;i<SIZE;i++){
        numbers[i]=rand()%SIZE;;
    }
    printToArray(numbers);
    printf("\n\nInput the number: ");
    int data;
    scanf("%d",&data);
    printf("isFinded : %d ",linear_search(numbers,data));
}

