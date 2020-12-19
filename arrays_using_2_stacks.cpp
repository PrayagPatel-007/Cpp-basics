#include<bits/stdc++.h>
using namespace std;

struct stack_ {
    int size;
    int top;
    int elements[50];
};

void push(struct stack_ &S, int n) {
    if (S.top == S.size - 1) {
        cout<<"Stack full!!";
    } else {
        S.top = S.top + 1;
        S.elements[S.top] = n;
    }
}

int pop(struct stack_ &S) {
    if (S.top == -1) {
        cout<<"Stack Empty!!";
        return 0;
    } else {
        int n = S.elements[S.top];
        S.top = S.top - 1;
        return n;
    }
}

void all_zeros(int arr[], int n){
    for (int i=0; i<n; i++) {
        arr[i] = 0;
    }
}

int main() {
    struct stack_ S1;
    struct stack_ S2;
    int choice, stk , num;
    S1.top=-1;
    S2.top=-1;
    S1.size=10;
    S2.size=10;
    int arr[20];
    all_zeros(arr, 20);
    while(true) {
        cout<<"Push(1) or pop(0): ";
        cin>>choice;
        if(choice == 1) {
            cout<<"Stack1(0) or Stack2(1): ";
            cin>>stk;
            cout<<"Enter number: ";
            cin>>num;
            if (stk == 0) {
                push(S1, num);
                arr[S1.top] = num;
            } else {
                push(S2, num);
                arr[S2.top + 10] = num;
            }
        } else if (choice == 0) {
            cout<<"Stack1(0) or Stack2(1): ";
            cin>>stk;
            if (stk == 0 && S1.top < S1.size-1) {
                pop(S1);
                arr[S1.top+1] = 0;
            } else if (stk ==1  && S2.top < S2.size-1) {
                pop(S2);
                arr[S2.top + 11] = 0;
            }
        } else {
            break;
        }
    }
    for (int i=0; i<20; i++) {
        cout<<arr[i]<<" ";    
    }
    return 0;
}