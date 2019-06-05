#include<iostream>
#include<stdlib.h>

using namespace std;

int *a,*b;

int hesapla(int start,int left,int right,int n){
    int sum[n] = {0};
    if(start == 1)
        for(int i = 0; i < n; i++){
            if(i%2 == 0)
                sum[i] = a[i];
            else
                sum[i] = b[i];
        }
    else
        for(int i = 0; i < n; i++){
            if(i % 2 == 0)
                sum[i] = b[i];
            else
                sum[i] = a[i];
        }
    int toplam = 0;
    for(int i = left; i <= right; i++){
        toplam += sum[i-1];
    }

    return toplam;

}

int main(){
    int n;
    cout << "Diziler kaç elemanli olacak : ";
    a = (int*) malloc(sizeof(int)*n);
    b = (int*) malloc(sizeof(int)*n);
    cin >> n;

    cout << "A dizisinin elemanlari: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "B dizisinin elemanlari: ";
    for(int i = 0; i < n; i++ ){
        cin >> b[i];
    }
    int start,left,right;
    cout << "Cok guzel..simdi sirasiyla start left right degerlerini girin: ";
    cin >>start >> left >> right;

    cout << "Sonuç: " << hesapla(start,left,right,n);


}
