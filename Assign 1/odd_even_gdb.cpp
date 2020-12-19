#include<iostream>
#include<string>
using namespace std;

void swape(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(int argc, char *argv[]){
    int n = argc - 1;
    int a[n];
    for (int i=0; i<n; i++) {
        a[i] = atoi(argv[i + 1]);
    }
    int swaps = 1;
    while (swaps != 0) {
        swaps = 0;
        for (int l=0, h=1; l<n-1, h<n; l++, h++) {
            if (a[l] % 2 != 0 && a[h] % 2 == 0) {
                swape(&a[l], &a[h]);
                swaps++;
            }
        }
    }
    for (int i=0; i<n; i++){cout<<a[i]<<" ";}
    return 0;
}