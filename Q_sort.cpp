#include<bits/stdc++.h>
using namespace std;

void swape(int &x,int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int partition1(int arr[], int low, int high) {
    if (arr[low] > arr[high]) {
        swape(arr[low], arr[high]);
    }
    int lp = low;
    low++;
    while (low < high) {
        while (arr[low] < arr[lp]) {
            low++;
        }
        while (arr[high] > arr[lp]) {
            high--;
        }
        if (low < high) {
            swape(arr[low], arr[high]);
        }
    }
    if (arr[lp] > arr[high]) {
        swape(arr[lp], arr[high]);
    }
    return high;
}

int partition2(int arr[], int low, int high) {
    int hp = high;
    high--;
    while (low < high) {
        while (arr[low] < arr[hp]) {
            low++;
        }
        while (arr[high] > arr[hp]) {
            high--;
        }
        if (low < high) {
            swape(arr[low], arr[high]);
        }
    }
    // if (arr[hp] < arr[low]){
    //     swape(arr[hp], arr[low]);   
    // }
    
    return low;
}

void Qsort(int arr[], int l, int h) {
    if (l >= h) {
        return;
    }
    if (l < h) {
        int j = partition1(arr, l, h);
        int k = partition2(arr, l, h);
        Qsort(arr, l, j-1);
        Qsort(arr, j+1, k-1);
        Qsort(arr, k+1, h);
    }
}

int main() {
    int arr[20] = {3, 19, 15, 12,  9, 14,  2, 13, 18,  6, 16,  20, 11,  1, 10,  4,  5, 17,  7,  8};
    // if (arr[0] > arr[5]){
    //     swape(arr[0], arr[5]);
    // }
    // Qsort(arr, 0, 19);
    for (int i=0; i<20; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}