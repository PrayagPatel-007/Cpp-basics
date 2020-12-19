#include<bits/stdc++.h>
using namespace std;

struct Queue_c {
    int size;
    int f;
    int r;
    char elements[50];
};

struct stack_c {
    int top;
    int size;
    char elements[50];
    void push(char n) {
        if (top == size - 1) {
            cout<<"Stack full";
        } else {
            elements[++top] = n;
        }
    }
    char pop() {
        if (top == -1) {
            cout<<"Stack Empty";
            return '0';
        } else {
            return elements[top--];
        }
    }
    char peek() {
        if (top == -1) {
            cout<<"Stack Empty";
            return '0';
        } else {
            return elements[top];
        }
    }
};


void enqueue_c(struct Queue_c &Q, char n) {
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

char dequeue_c(struct Queue_c &Q) {
    if (Q.f == -1) {
        cout<<"Queue Empty";
        return '0';
    } else {
        char s;
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

bool is_palme(char str[], int n) {
    struct Queue_c Q;
    struct stack_c S;
    S.top=-1;
    S.size=20;
    Q.f=-1;
    Q.r=-1;
    Q.size=20;
    for (int i=0; i<n; i++) {
        enqueue_c(Q, str[i]);
        S.push(str[i]);
    }
    bool is_palindrome = true;
    for (int i=0; i < n/2; i++) {
        if (dequeue_c(Q) != S.pop()) {
            is_palindrome = false;
        }
    }
    return is_palindrome;
}


void reverse_queue(struct Queue_c &Q, struct stack_c &S, int n) {
    for (int i=0; i<n; i++) {
        S.push(dequeue_c(Q));
    }
}

int main(){
    int n = -1;
    struct Queue_c Q;
    struct stack_c S;
    S.top=-1;
    S.size=30;
    Q.f = -1;
    Q.r = -1;
    Q.size = 30;
    char c = 'a';
    while (c != '#') {
        cin>>c;
        enqueue_c(Q, c);
        n++;
    }
    reverse_queue(Q, S, n);
    while (S.top > -1) {
        cout<<S.pop()<<" ";
    }cout<<endl;
    n=0;
    char c1[100];
    char c2 = 'a';
    while (c2!= '#') {
        cin>>c2;
        c1[n] = c2;
        n++;
    }
    cout<<is_palme(c1, n-1);
    return 0;
}