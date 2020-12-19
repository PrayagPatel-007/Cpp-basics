#include<bits/stdc++.h>
using namespace std;

void slide_window(int A, int B, n) {
    int C[100];
    int k=0;
    if (B > n) {
        int max = A[0];
        for (int i=0; i<n; i++) {
            if (max < A[i]) {
                max = A[i];
            }
        }
        cout<<max<<endl;
        return;
    }
    for (int i=0; i<=n-B; i++) {
        int max = A[i]; 
        for (int j=i; j<i+B; j++) {
            if (max < A[j]) {
                max = A[j];
            }
        }
        C[k++] = max;
    }
    for (int i = 0; i < n-B+1; i++)
    {
        cout<<C[i]<<" ";
    }
    cout<<endl;
    return;
}