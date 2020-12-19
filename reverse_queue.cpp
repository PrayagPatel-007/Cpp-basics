#include<bits/stdc++.h>
using namespace std;

struct Queue {
    int size;
    int f;
    int r;
    int elements[50];
};

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

void enqueue (struct Queue &Q, int n) {
    if ((Q.r+1)%Q.size == Q.f) {
        cout<<"Queue full";
    } else {
        if (Q.r == -1) {
            Q.r++;
            Q.f++;
        } else {
            Q.r = (Q.r+1)%Q.size;
        }
        Q.elements[Q.r] = n;
    }
}

int dequeue (struct Queue &Q) {
    if (Q.f == -1) {
        cout<<"Queue Empty";
        return 0;
    } else {
        int s;
        if (Q.f == Q.r) {
            s = Q.elements[Q.f];
            Q.f = -1;
            Q.r = -1;
        } else {
            s = Q.elements[Q.f];
            Q.f++;
        }
        return s;
    }
} 

void reverse_queue(struct Queue &Q, struct stack_ &S, int n) {
    for (int i=0; i<n; i++) {
        S.push(dequeue(Q));
    }
}

int main(){
    int n = 7;
    struct Queue Q;
    struct stack_ S;
    S.top=-1;
    S.size=30;
    Q.f = -1;
    Q.r = -1;
    Q.size = 30;
    for (int i=1; i<=7; i++) {
        enqueue(Q, i);
    }
    reverse_queue(Q, S, 7);
    while (S.top > -1) {
        cout<<S.pop()<<" ";
    }
    return 0;
}

