#include<bits/stdc++.h>
using namespace std;

void find_ways(int num, int index, int arr[], int sum){
    if(sum == 0){
        cout<<"(";
        for (int i=0; i<index - 1; i++) {
            cout<<arr[i]<<" + ";
        } cout<<arr[index-1]<<"), \n";
    }
    if (num < 0){
        return;
    }
    int last = (index == 0) ? 1 : arr[index-1];
    for (int i=last; i<=sum ; i++){
        arr[index] = i;
        find_ways(num, index + 1, arr, sum - i);
    }
}

void find_subsequence(string s1, string s2, int index1, int index2, bool *subsequence) {
    if (index1 >= s1.length() || index2 >= s2.length()){
        *subsequence = false;
        return;
    }
    if (s1[index1] == s2[index2]) {
        if (index2 == s2.length() - 1) {
            *subsequence = true;
            return;
        }
        else {
            find_subsequence(s1, s2, index1+1, index2+1, subsequence);
        }
    } else {
        find_subsequence(s1, s2, index1+1, index2, subsequence);
    }
}

void print_pattern(int num){
    for (int i=0; i<num; i++){
        cout<<"(";
    }
    for (int i=0; i<num; i++){
        cout<<")";
    }
}

void parantheses_pattern(int num, int index, int arr[], int sum){
    if(sum == 0){
        for (int i=0; i<index; i++) {
            print_pattern(arr[i]);
        }
        cout<<endl;
    }
    if (num < 0){
        return;
    }
    for (int i=1; i<=sum ; i++){
        arr[index] = i;
        parantheses_pattern(num, index + 1, arr, sum - i);
    }
}

string fibonacci(int num) {
    if (num == 0) {
        return "a";
    } else if (num == 1) {
        return "bc";
    }
    return fibonacci(num-2) + fibonacci(num-1);
}

int main(){
    int arr1[5];
    int n, k;
    find_ways(5, 0, arr1, 5);
    bool subsequence = false;
    string a = "cathartic", b = "hac";
    find_subsequence(a, b, 0, 0, &subsequence);
    if (subsequence){
        cout<<"There is subsequence: true\n";
    } else {
        cout<<"There is no subsequence: false\n";
    }
    string c = "table", d="bat";
    find_subsequence(c, d, 0, 0, &subsequence);
    if (subsequence){
        cout<<"There is subsequence: true\n";
    } else {
        cout<<"There is no subsequence: false\n";
    }
    int arr2[5];
    parantheses_pattern(4, 0, arr2, 4);
    cout<<"Enter n and k: ";
    cin>>n>>k;
    cout<<"The kth index of Fn is :"<<fibonacci(n)[k]<<endl;
    return 0;
}