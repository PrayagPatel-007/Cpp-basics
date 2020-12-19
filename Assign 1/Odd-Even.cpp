#include<iostream>
using namespace std;

void swape(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a[30] = {21, 44, 65, 35, 65, 86, 254, 75, 70, 57, 35, 44, 83, 92, 84, 54, 20, 65, 73, 24, 46, 923, 934, 43, 2, 59 ,27, 40, 02, 46};
    int n = 30;
    int swaps = 0;
    /* while (swaps != 0) {
        swaps = 0;
        for (int l=0, h=1; l<29, h<30; l++, h++) {
            if (a[l] % 2 != 0 && a[h] % 2 == 0) {
                swape(&a[l], &a[h]);
                swaps++;
            }
        }
    } */
    for (int l=0, h=1; l<n-1, h<n; l++, h++) {
        swaps = 0;
        if (a[l] % 2 != 0 && a[h] % 2 == 0) {
            swape(&a[l], &a[h]);
        }
        if (swaps == 0){
            cout<<"IDGaf";
            break;
        }
    }
    int l=0, h=n-1;
    while (true){
        if (l >= h) {
            break;
        }
        if (a[l] % 2 != 0 && a[h] % 2 == 0) {
            swape(&a[l], &a[h]);
            l++;
            h--;
        } else if(a[l] % 2 == 0 && a[h] % 2 == 0) {
            l++;
        } else if(a[l] % 2 != 0 && a[h] % 2 != 0) {
            h--;
        } else {
            h--;
            l++;
        }
    }
    //for (int i=0; i<n; i++){cout<<a[i]<<" ";}
    for (int i=0; i<n; i++){cout<<a[i]<<" ";}
    return 0;
}
