#include<bits/stdc++.h>
using namespace std;

struct stack_ {
    int top;
    int size;
    int elements[50];
    void push(int n) {
        if (top == size - 1) {
            cout<<"Stack full";
        } else {
            elements[++top] = n;
        }
    }
    int pop() {
        if (top == -1) {
            cout<<"Stack Empty";
            return 0;
        } else {
            return elements[top--];
        }
    }
    int peek() {
        if (top == -1) {
            cout<<"Stack Empty";
            return 0;
        } else {
            return elements[top];
        }
    }
};

void reverse_stack(struct stack_ &S, int i, int n2) {
    if (S.top == i) {
        return;
    }
    int a = S.pop();
    int b = S.pop();
    S.push(a);
    reverse_stack(S, i ,n2);
    S.push(b);
    if (S.top == n2-1) {
        if (i >= n2-1) {
            return;
        }
        reverse_stack(S, i+1, n2);
    } 
}

int main() {
    struct stack_ S1;
    struct stack_ S2;
    S1.top = -1;
    S2.top = -1;
    S1.size = 15;
    S2.size = 15;
    int n, num;
    cout<<"Enter number of elements: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>num;
        S1.push(num);
    }
    reverse_stack(S1, 0, n);
    while (S1.top > -1) {
        cout<<S1.pop()<<" ";
    }
    return 0;
}