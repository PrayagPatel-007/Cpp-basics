#include<iostream>
using namespace std;

void swape(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a[9];
    for (int i=0; i<9; i++) {
        cin>>a[i];
    }
    int n = 9;
    bool over = false;
    for (int i=0; i<n; i++){
        if (a[i] % 2 != 0){
            for (int j=n-1; j >= i; j--){
                if (a[j] % 2 == 0){
                    swape(&a[i], &a[j]);
                    break;
                } else if (j==i) {
                    over = true;
                }
            }
        }
        if (over){
            break;
        }
    }
    for (int i=0; i<n; i++){cout<<a[i]<<" ";}
    return 0;
}
