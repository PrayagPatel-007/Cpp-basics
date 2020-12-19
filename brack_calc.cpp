#include<bits/stdc++.h>
using namespace std;

void brack_calc(int arr[], int n) {
    bool done = false;
    while (!done) {
        done = true;
        for (int i=0; i<n; i++) {
            if (arr[i] == -1) {
                done=false;
                break;
            }
        }
        int l = -1, h = -1;
        for(int i=0; i<n; i++) {
            if (arr[i] == -1) {
                l = i;
            }
            if (arr[i] == -2) {
                if( l != -1){
                    h = i;
                    if (h == l+1) {
                        arr[l] = 1;
                        arr[h] = 0;
                    } else {
                        arr[l] = 2*arr[l+1];
                        arr[l+1] = 0;
                        arr[h] = 0;
                    }
                    l = -1;
                }
            }
        }
        for (int i=0; i<n-1; i++) {
            if (arr[i] >= 0) {
                int j=i+1, sum=arr[i];
                while (arr[j] >= 0 && j<n){
                    sum = sum + arr[j];
                    arr[j] = 0;
                    j++;
                }
                arr[i] = sum;
            }
        }
    }
    cout<<arr[0]<<endl;
}

int main() {
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int arr[100];
    for (int i=0; i<s.length(); i++){
        if (s[i] == '('){
            arr[i] = -1;
        } else if (s[i] == ')') {
            arr[i] = -2;
        }
    }
    brack_calc(arr, s.length());
    return 0;
}