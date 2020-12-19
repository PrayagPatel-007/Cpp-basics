#include<bits/stdc++.h>
using namespace std;

int slide_window_max(int A[], int B, int n) {
    int max = 0, x;
    for (int i=0; i<=n-B; i++) {
        int min = A[i]; 
        for (int j=i; j<i+B; j++) {
            if (min > A[j]) {
                min = A[j];
            }
        }
        x = B * min;
        if (max < x) {
            max = x;
        }
    }
    return max;
}

int max_area(int A[], int n) {
    int max = 0;
    for (int i=1; i<n; i++) {
        int x = slide_window_max(A, i, n);
        if (max < x) {
            max = x;
        }
    }
    return max;
}

int main() {
    int A[100], B;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    cout<<max_area(A, n)<<endl;
    return 0;
}