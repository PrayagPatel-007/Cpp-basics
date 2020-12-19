#include<bits/stdc++.h>
#include<string>
using namespace std;

int fibonacci(int n){
    if (n==1 || n==2) {
        return 1;
    }
    return fibonacci(n-2) + fibonacci(n-1);
}

int convert(string s) {
    int sum = 0, n = s.length();
    for (int i = 0; i<s.length(); i++) {
        if (s[i] - '0' == 1) {
            sum += fibonacci(n-i);
        }
    }
    return sum;
}

bool all_ones (string s) {
    for (int i =0; i<s.length(); i++) {
        if (s[i] - '0' != 1) {
            return false;
        }
    }
    return true;
}

string fitstring(string s, bool increment) {
    int n = convert(s);
    n = (increment) ? n+1 : n-1;
    string s1 = s;
    if (all_ones(s1) && increment){
        s1.push_back('0');
    }
    int sum = n, num = s1.length();
    for (int i=0; i < num; i++) {
        int fib = fibonacci(num - i);
        if (sum >= fib) {
            s1[i] = '1';
            sum = sum - fib;
        }
        else {
            s1[i] = '0';
        }
    }
    return s1;
}

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
    if (arr[hp] < arr[low]){
        swape(arr[hp], arr[low]);   
    }
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


void merge (int arr[], int arr1[], int l, int j, int h) {
    int i = l, k = j;
    int n1 = j-l+1, n2 = h-j;
    while (true) {
        if (arr[l] <= arr[j+1]){
            arr1[k] == arr[l];
        }
    }
}

void merge_sort(int arr[], int arr1[], int l, int h) {
    if (l < h) {
        int j = (h + l) / 2;
        merge_sort(arr, arr1, l, j);
        merge_sort(arr, arr1, j+1, h);
        merge(arr, arr1, l, j, h); 
    }
}




int main() {
    int n;
    cout<<"Press accordingly\nQ.1: Fitstring - Press 1\n"
        <<"Q.2: Recursive Insertion - Press 2\n"
        <<"Q.4: Dual Pivot Quick Sort - Press 4\n";
    cin>>n;
    switch (n) {
        case 1:
            {string s;
            cout<<"Enter the string: ";
            cin>>s;
            cout<<"Increment: "<<fitstring(s, true)
                <<"\nDecrement: "<<fitstring(s, false)<<endl;}
            break;
        case 2:
            {int num;
            cout<<"Number of elements in array: ";
            cin>>num;
            int arr[50];
            cout<<"Enter elements: ";
            for (int i=0; i<num; i++) {
                cin>>arr[i];
            }
            recursive_insertion_sort(arr, num, 1, 0);
            for (int i=0; i<num; i++) {
                cout<<arr[i] <<" ";
            }}
            break;
        case 4:
            {int num1;
            cout<<"Number of elements in array: ";
            cin>>num1;
            int arr1[50];
            cout<<"Enter elements: ";
            for (int i=0; i<num1; i++) {
                cin>>arr1[i];
            }
            Qsort(arr1, 0, num1);
            for (int i=0; i<num1; i++) {
                cout<<arr1[i]<<" ";
            }}
            break;
        default:
            cout<<"Enter valid value";
    }
    return 0;
}