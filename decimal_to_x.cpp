#include<bits/stdc++.h>
using namespace std;

void xbase(int num, int base) {
    if (num == 0) {
        cout<<num;
    } else {
        xbase(num/base, base);
        int x = num%base;
        if (x > 9) {
            cout<<(char)(x+55);
        } else {
            cout<<x;
        }
    }
}

int main(){
    xbase(3592, 10);
    return 0;
}