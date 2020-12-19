#include<bits/stdc++.h>
using namespace std;

// HELPER FUNCTIONS == 
void swape(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
void insert(int arr[], int n) {
    int j=0;
    while (j < (n-1) && arr[j] > arr[j+1]) {
        swape(arr[j], arr[j+1]);
        j++;
    }
}
void bsort(int arr[], int l, int m) {
    bool swaps = true;
    while (swaps) {
        swaps = false;
        for (int i=l; i<m-1; i++) {
            if (arr[i] > arr[i+1]) {
                swape(arr[i], arr[i+1]);
                swaps = true;
            }
        }
    }
}
void print_array(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void all_zeros(int arr[], int n) {
    for (int i=0; i<n; i++) {
        arr[i] = 0;
    }
}

// Question wise ORDER

//1st
void sort_duplicate(int arr1[], int arr2[], int freq[], int n) {
    for (int i = 0; i<n; i++) {
        freq[arr1[i] + 50]++;
    }
    int k=0;
    for (int i=0; i<100; i++) {
        while (freq[i] != 0){
            arr2[k] = i-50;
            k++;
            freq[i]--;
        }
    }
}

//2nd
void sorted_triplet(int arr[], int n) {
    bool is_present = false;
    for (int i =0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            for (int k=j+1; k<n; k++) {
                if (arr[i] < arr[j] && arr[j] < arr[k]) {
                    is_present = true;
                    cout<<"("<<arr[i]<<", "<<arr[j]<<", "<<arr[k]<<")\n";
                    return;
                }
            }
        }
    }
    if (!is_present) {
        cout<<"No such triplet present !!\n";
    }
}

//3rd
void find_window(int arr[], int n) {
    int low = 0, high = n-1, i;
    for (i=0; i<n; i++) {
        int min = arr[i];
        for(int j=i; j<n; j++) {
            if (min > arr[j]) {
                min = arr[j];
            }
        }
        if (min != arr[i]) {
            low = i;
            break;
        }
    }
    for (i=n-1; i>=0; i--) {
        int max = arr[i];
        for(int j=i; j>=0; j--) {
            if (max < arr[j]) {
                max = arr[j];
            }
        }
        if (max != arr[i]) {
            high = i;
            break;
        }
    }
    cout<<"Sort the array from index "<<low<<" to "<<high<<endl;
}

//4th
void merge_sorted(int X[], int Y[], int m, int n) {
    int i=0;
    while (i < m) {
        if (X[i] >= Y[0]) {
            swape(X[i], Y[0]);
            insert(Y, n);
        }
        i++;
    }
}

//5th
void merge_zeros(int X[], int Y[], int m, int n) {
    int i=0, k=0;
    while (k < m - n) {
        while (X[i] == 0) {
            i++;
        }
        if (X[i] >= Y[0]) {
            X[k] = Y[0];
            Y[0] = X[i];
            insert(Y, n);
        } else {
            X[k] = X[i];
        }
        i++;
        k++;
    }
    for (int j=0; j<n; j++) {
        X[k] = Y[j];
        k++;
    }
}

//6th
void sort_order(int X[], int Y[], int m, int n) {
    int k=0;
    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (Y[i] == X[j]) {
                swape(X[k], X[j]);
                k++;
            }
        }
    }
    bsort(X, k, m);
}

//7th
void one_swap_sort(int X[], int n) {
    int l=0, h=n-1;
    while(X[l] < X[l+1]){
        l++;
    }
    while(X[h] > X[h-1]){
        h--;
    }
    swape(X[l], X[h]);
}


int main() {
    int A1[11] = {4, 2, 40, 10, 10, 1, 4, 2, 1, 10, 40};
    int freq[100], A2[11];     // since the freq is 100 we can go -50 and 49 at most
    all_zeros(freq, 100);
    int arr1[7] = {5,4,3,7,6,1,9};
    int arr2[8] = {1,2,3,7,5,6,4,8};
    int X1[] = {1,4,7,8,10};
    int Y1[] = {2,3,9};
    int X2[] = {0,2,0,3,0,5,6,0,0};
    int Y2[] = {1,8,9,10,15};
    int arr3[] = {5,8,9,3,5,7,1,3,4,9,3,5,1,8,4};
    int arr4[] = {3,5,7,2};
    int arr5[] = {3,5,6,9,8,7};

    sort_duplicate(A1, A2, freq, 11);
    print_array(A2, 11);
    sorted_triplet(arr1, 7);
    find_window(arr2, 8);
    merge_sorted(X1, Y1, 5, 3);
    print_array(X1, 5);
    print_array(Y1, 3);
    merge_zeros(X2, Y2, 9, 5);
    print_array(X2, 9);
    sort_order(arr3, arr4, 15, 4);
    print_array(arr3, 15);
    one_swap_sort(arr5, 6);
    print_array(arr5, 6);
    return 0;
}
