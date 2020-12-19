#include<bits/stdc++.h>
using namespace std;

void swape(int &x,int &y) {
    int temp = x;
    x = y;
    y = temp;
}


void recursive_bubble_sort(int arr[], int n, int i) {
    if (n <= 0) {
        return;
    }
    if (i >= n-1) {
        i = 0;
        n = n-1;
    }
    if (arr[i] > arr[i+1]) {
        swape(arr[i], arr[i+1]);
    }
    recursive_bubble_sort(arr, n, i+1);
}


int main() {
    int arr[3] = {6,4,3};
    recursive_bubble_sort(arr, 3, 0);
    for(int i=0; i<3; i++) {
        cout<<arr[i]<<" ";
    }
    // int arr2[6] = {2,12,3,8,1,4};
    // recursive_selection_sort(arr2, 6);
    // for(int i=0; i<6; i++) {
    //     cout<<arr2[i]<<" ";
    // }
    return 0;
}
