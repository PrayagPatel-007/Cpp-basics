#include<bits/stdc++.h>
using namespace std;

void swape(char &x, char &y) {
    char temp =x;
    x = y;
    y=temp;
}

void permute(char a[], int l, int r) {
    if (l==r) {
        cout<<a<<" ";
    } else {
        for (int i=l; i<=r; i++){
            swape(a[l], a[i]);
            permute(a, l+1, r);
            swape(a[l], a[i]);
        }
    }
}

int main() {
    int n = 5;
    char arr[] = "ABCDE";
    permute(arr, 0, n);
    return 0;
}
