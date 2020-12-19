#include<bits/stdc++.h>
using namespace std;

struct Queue_s {
    int size;
    int f;
    int r;
    string elements[50];
};

void enqueue_s (struct Queue_s &Q, string n) {
    if ((Q.r+1)%Q.size == Q.f) {
        cout<<"Queue_s full";
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

string dequeue_s (struct Queue_s &Q) {
    if (Q.f == -1) {
        cout<<"Queue_s Empty";
        return "0";
    } else {
        string s;
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

void print_str(int n) {
    struct Queue_s Q;
    Q.size = 20;
    Q.f=-1;
    Q.r=-1;
    int i=0;
    cout<<0<<" ";
    enqueue_s(Q, "1");
    while (i < n) {
        string s = dequeue_s(Q);
        cout<<s<<" ";
        enqueue_s(Q, s+"0");
        enqueue_s(Q, s+"1");
        i++;
    }
}

int main () {
    int n=7;
    print_str(n);
    return 0;
}

