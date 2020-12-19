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

int pope(struct stack_ S) {
    if (S.top == -1) {
        cout<<"Stack Empty!!";
        return 0;
    } else {
        int n = S.elements[S.top];
        S.top = S.top - 1;
        return n;
    }
}


struct Queue_ {
    int size;
    int f;
    int r;
    int elements[50];
};

void enqueue(struct Queue_ &Q, int n) {
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

int dequeue(struct Queue_ &Q) {
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

void inter_leave(struct Queue_ &Q) {
    struct stack_ S;
    S.top=-1;
    S.size=30;
    struct stack_ S2;
    int n = Q.r-Q.f+1;
    for (int i=0; i<n; i++) {
        push(S, dequeue(Q));
    }
    for (int i=0; i<n; i++) {
        enqueue(Q, pop(S));
    }
    for (int i=0; i<n; i++) {
        push(S, dequeue(Q));
    }
    S2 = S;
    for (int i=0; i<n; i++) {
        enqueue(Q, pop(S2));
    }
    for (int i=0; i<n/2; i++) {
        dequeue(Q);
    }
    for(int i=n/2; i<n; i++) {
        enqueue(Q, pop(S));
        enqueue(Q, dequeue(Q));
    }
}

int main() {
    struct Queue_ Q;
    Q.f=-1;
    Q.r=-1;
    Q.size=50;
    for (int i=11; i<=20; i++) {
        enqueue(Q, i);
    }
    inter_leave(Q);
    int n = Q.r - Q.f + 1;
    for(int i=0; i<n; i++) {
        cout<<dequeue(Q)<<" ";
    }
    return 0;
}

