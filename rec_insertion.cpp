#include<bits/stdc++.h>
using namespace std;

void swape(int &x,int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void recursive_insertion_sort(int arr[], int n, int index, int j){
    if (index >= n) {
            return;
    }
    if (arr[j] < arr[j+1] || j < 0){
        recursive_insertion_sort(arr, n, index+1, index);
    } else {
        swape(arr[j], arr[j+1]);
        recursive_insertion_sort(arr, n, index, j-1);
    }
}

int main() {
    int arr[6] = {6,5,4,3,2,1};
    recursive_insertion_sort(arr, 6, 1, 0);
    for (int i=0; i<6; i++) {
        cout<<arr[i] <<" ";
    }
    return 0;
}