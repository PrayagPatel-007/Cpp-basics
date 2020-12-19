#include<bits/stdc++.h>
using namespace std;

struct Queue_k {
    int size;
    int r[50];
    int f[50];
    int elements[100];
};

void enqueue_k(struct Queue_k &Q, int i, int n) {
    if ((Q.r[i]+1)%Q.size == Q.f[i]) {
        cout<<"Queue full";
    } else {
        if (Q.r[i] == -1 + Q.size*i) {
            Q.r[i]++;
            Q.f[i]++;
        } else {
            Q.r[i] = (Q.r[i]+1)%Q.size;
        }
        Q.elements[Q.r[i]] = n;
    }
}

int dequeue_k(struct Queue_k &Q, int i) {
    if (Q.f[i] == -1 + Q.size*i) {
        cout<<"Queue Empty";
        return 0;
    } else {
        int s;
        if (Q.f[i] == Q.r[i]) {
            s = Q.elements[Q.f[i]];
            Q.f[i] = -1 + Q.size*i;
            Q.r[i] = -1 + Q.size*i;
        } else {
            s = Q.elements[Q.f[i]];
            Q.f[i] = (Q.f[i]+1)%Q.size;
        }
        return s;
    }
}

int main() {
    int n, k, inp, num, choice;
    cout<<"Enter n and k: ";
    cin>>n>>k;
    struct Queue_k Q;
    Q.size = n/k;
    for (int i=0; i<n; i++) {
        Q.r[i] = -1 + n/k *i;
        Q.f[i] = -1 + n/k *i;
    }
    cout<<"Select Queue (numbering starts from 0 to k-1) (-1 to exit): ";
    cin>>inp;
    while (inp != -1) {
        cout<<"Enqueue(0) or Dequeue(1): ";
        cin>>choice;
        if (choice == 0) {
            cout<<"Enter number";
            cin>>num;
            enqueue_k(Q, inp, num);
        } else {
            dequeue_k(Q, inp);
        }
        cout<<"Select Queue (numbering starts from 0 to k-1) (-1 to exit): ";
        cin>>inp;
    }
    for (int i=0; i<k; i++) {
        cout<<i<<" Queue: ";
        while (Q.f[i] != -1 + Q.size*i) {
            cout<<dequeue_k(Q, i)<<" ";
        }cout<<endl;
    }
    return 0;
}


