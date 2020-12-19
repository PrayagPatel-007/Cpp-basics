#include<bits/stdc++.h>
using namespace std;

bool in_array_str(string arr[], string c, int n) {
    for (int i=0; i<n; i++) {
        if (arr[i] == c){
            return true;
        }
    }
    return false;
}

void pre_2_post(string arr_s[], int n, string arr_c[]) {
    if (n == 1) {
        cout<<arr_s[0];
        return;
    }
    for (int j=0; j<n-2; j++) {
        if (in_array_str(arr_c, arr_s[j], 3)) {
            if (!in_array_str(arr_c, arr_s[j+1], 3)) {
                if (!in_array_str(arr_c, arr_s[j+2], 3)){
                    arr_s[j] = arr_s[j+1] + arr_s[j+2] + arr_s[j];
                    for (int k = j+1; k<n; k++){
                        arr_s[k] = arr_s[k + 2];
                    }
                }
            }
        }
    }
    n = n -2;
    pre_2_post(arr_s, n, arr_c);
}


int main() {
    string s = "*-1/23-/456";
    string arr_s[100];
    string arr_c[4] = {"+", "-", "*", "/"};
    for (int i=0; i<s.length(); i++) {
        arr_s[i] = s[i];
    }
    pre_2_post(arr_s, s.length(), arr_c);
    return 0;
}