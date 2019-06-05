#include <iostream>

using namespace std;
int *A;

void initA(int n){
    cout << "Dizi degerlerini girin: ";

    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
}

int knapSack(int n,int z){
    int val = 0,sum = 0,maximum=0,res = 0;
    for (int i = 0; i < n; i++){
        val = A[i];
        for(int j = i; j < n; j++){
                val += A[j];
            for(int k = j+1; k<n; k++){

                sum = val + A[k];

                if(maximum <= sum)
                    maximum = sum;
                if(maximum <= z)
                    res = maximum;

            }
        }
    }
    return res;
}

int main(){

    int n,k,T;
    cout << "T degerini girin: ";
    cin >> T;
    cout << "n ve k degerlerini giriniz: ";
    cin >> n >> k;
    A = new int[n];
    initA(n);
    cout << knapSack(n,k);

}
