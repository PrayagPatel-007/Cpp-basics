#include<bits/stdc++.h>
using namespace std;

struct Queue_ {
    int size;
    int f;
    int r;
    int elements[100];
};

void enqueue_(struct Queue_ &Q, int n) {
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

int dequeue_(struct Queue_ &Q) {
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
            Q.f = (Q.f +1)%Q.size;
        }
        return s;
    }
} 

void sort_queue(struct Queue_ &Q, int n) {
    bool done=false;
    while (!done) {
        done= true;
        int max = dequeue_(Q);
        for (int i=1; i<n; i++) {
            int x = dequeue_(Q);
            if (max > x) {
                done = false;
                enqueue_(Q, x);
            } else {
                enqueue_(Q, max);
                max = x;
            }
        }
        enqueue_(Q, max);
    }
}

int main() {
    struct Queue_ Q2;
    Q2.r=-1;
    Q2.f=-1;
    Q2.size=15;
    int arr[100];
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>arr[i];
        enqueue_(Q2, arr[i]);
    }
    sort_queue(Q2, n);
    while (Q2.f != -1) {
        cout<<dequeue_(Q2)<<" ";
    }
    return 0;
}


