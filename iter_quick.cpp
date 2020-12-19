#include<bits/stdc++.h>
using namespace std;

void swape(int &x,int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int partitione(int arr[], int i, int n) {
    int low = i+1, high = n-1;
    int p = i;
    while (low <= high) {
        while (arr[low] < arr[p]) {
            low++;
        }
        while (arr[high] > arr[p] && low <= high) {
            high--;
        }
        if (low < high) {
            swape(arr[low], arr[high]);
        }
    }
    swape(arr[p], arr[high]);
    return high;
}

void Q_sort(int arr[], int n) {
    int i = 0;
    while (i < n) {
        if (i == partitione(arr, i, n)) {
            i++;
        }
    }
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[] = {1,8,9,5,4,7};
    Q_sort(arr, 6);
    return 0;
}

