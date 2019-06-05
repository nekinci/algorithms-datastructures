
#include <iostream>
#include<vector>
#include<cstdio>
#include<stdio.h>

using namespace std;
int *A;
int maximum = 0;
int sum = 0;
bool *check;
int res = 0;
vector <int> results;


void initA(int n){
    cout << "Dizi degerlerini girin: ";

    for (int i = 0; i < n; i++){
        cin >> A[i];

    }
}


void combinationUtil(int data[], int start, int end,
                     int index, int r,int k)
{
	//maximum = 0;
    if (index == r)
    {
        sum = 0;
        for (int j=0; j<r; j++){

            printf("%d ", data[j]);
            sum += data[j];

        }
        results.push_back(sum);
        if(sum > maximum)
            maximum = sum;
        if (maximum <= k)
            res = maximum;
        printf("\n");
        return;
    }

    for (int i = start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = A[i];
        combinationUtil(data, i+1, end, index+1, r,k);
    }
}
int sonuc(int k){
    vector<int> :: iterator i;
    int maxi = 0;
    int w = 0;
    int a = 0;
    for(i = results.begin(); i != results.end(); ++i ){
            a = w;
            if(maxi<=results.at(a) && results.at(a)<=k)
                maxi = results.at(a);
            w++;
    }
    return maxi;
}
void printCombination(int n, int r,int k)
{

    int data[r];

    combinationUtil(data, 0, n-1, 0, r,k);

    res = sonuc(k);
}




int main(){

    int n,k,T;
    cout << "T degerini girin: ";
    cin >> T;
    while(T--){
        cout << "\nn ve k degerlerini giriniz: ";
    cin >> n >> k;
    A = new int[n];
    check = new bool[n];
    initA(n);
    for(int i=1; i<=n;i++)
      printCombination(n,i,k);

    cout << "Sonuc: "<< res;
    }

}
