#include<bits/stdc++.h>
using namespace std;

void all_zeros(int arr[], int n) {
    for(int i=0; i<n; i++) {
        arr[i] = 0;
    }
}

void print_array(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void count_sort(int arr[], int n, int p) {
    int A[n];
    int freq[10];
    int B[n];
    for (int i=0; i<n; i++) {
        B[i] = arr[i]/(int)(pow(10, p) + 0.5);
        B[i] = B[i]%10;
    }
    all_zeros(freq, 10);
    for (int i=0; i<n; i++) {
        freq[B[i]]++;
    }
    int last = freq[0];
    freq[0] = 0;
    for(int i=1; i<10; i++) {
        swap(freq[i], last);
        freq[i] = freq[i-1] + freq[i];
    }
    for (int i=0; i<n; i++) {
            A[freq[B[i]]] = arr[i];
            freq[B[i]]++;
    }
    for(int i=0; i<n; i++) {
        arr[i] = A[i];
    }
}

void radix_sort(int arr[], int n) {
    int p = 3;
    for (int i = 0; i < p; i++)
    {
        count_sort(arr, n, i);
    }
}

int main() {
    int arr[] = {3,83,4,4,19,1,25,2,5,4,334,5,7,67,4,93,5,72,9,9,5,41,3,2,17,3,5};
    radix_sort(arr, 27);
    print_array(arr, 27);
    return 0;
}



