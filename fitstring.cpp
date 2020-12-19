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

int main() {
    // cout<<convert("101110");
    cout<<fitstring("101110", false);
    return 0;
}
