#include<bits/stdc++.h>
using namespace std;

int eval(int opnd1, int opnd2, char optr) {
    switch (optr) {
        case '*': return opnd1 * opnd2;
        case '/': return opnd1 / opnd2;
        case '+': return opnd1 + opnd2;
        case '-': return opnd1 - opnd2;
    }
}

bool in_array(char arr[], char c, int n) {
    for (int i=0; i<n; i++) {
        if (arr[i] == c){
            return true;
        }
    }
    return false;
}

void post_evalue (int arr[], string arr_s[], int i, int lastIndex, int n, char arr_c[]) {
    if (i>=n) {
        cout<<arr[0];
        return;
    }
    if (lastIndex >= 1 && in_array(arr_c, arr_s[i][0], 4)) {
        arr[lastIndex - 1] = eval(arr[lastIndex-1], arr[lastIndex], arr_s[i][0]);
        lastIndex--;
        post_evalue(arr, arr_s, i+1, lastIndex, n, arr_c);
    } else {
        arr[lastIndex + 1] = atoi(arr_s[i].c_str());
        post_evalue(arr, arr_s, i+1, lastIndex+1, n, arr_c);
    }

}

int main() {
    char arr_c[4] = {'+', '-', '*', '/'};
    int arr[100];
    char str[50];
    cout<<"Enter the string with each character spaced: ";
    cin.getline(str, 50);
    string arr_s[100];
    char *tok =  strtok(str, " ");
    int count=0;
    while(tok != NULL){
        arr_s[count] = tok;
        tok = strtok(NULL, " ");
        count++;
    }
    post_evalue(arr, arr_s, 0, -1, count, arr_c);
    return 0;
}
