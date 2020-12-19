#include<iostream>
using namespace std;

void swap1(int x, int y){ //call-by-value
    int temp = x;
    x = y;
    y = temp;
}

void swap2(int &x, int &y){ // call-by-reference      Using Alias x and y
    int temp = x;
    x = y;
    y = temp;
}

void swap3(int *x, int *y) {  // call-by-pointer
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap4(int &x, int *y) {
    int temp = x;
    x = *y;
    *y = temp;
}

void swap5(int *x, int &y) {
    int temp = *x;
    *x = y;
    y = temp;
}

// void swap6(int *x, int *y) {
//     int *temp;
//     *temp = *x;    // Assigning value to a pointer that wasn't intialised
//                     // is not encouraged however newer compilers will work
//                     // in my machine it crashed
//     *x = *y;
//     *y = *temp;
// }

int main(){
    int a=3, b=6;
    cout<<"a = "<<a<<", b = "<<b<<endl;
    swap1(a, b);     // Since it is call by value It won't swap the original a and b.
    cout<<"After Swap1 - Call By Value"<<endl;
    cout<<"a = "<<a<<", b = "<<b<<endl;
    swap2(a, b);
    cout<<"After Swap2 - Call by Reference"<<endl;
    cout<<"a = "<<a<<", b = "<<b<<endl;
    swap3(&a, &b);
    cout<<"After Swap3 - Call by Pointer"<<endl;
    cout<<"a = "<<a<<", b = "<<b<<endl;
    swap4(a, &b);
    cout<<"After Swap4 - Call by reference and pointer"<<endl;
    cout<<"a = "<<a<<", b = "<<b<<endl;
    swap5(&a, b);
    cout<<"After Swap5 - Call by pointer and reference"<<endl;
    cout<<"a = "<<a<<", b = "<<b<<endl;
    return 0;
}
