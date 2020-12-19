#include<bits/stdc++.h>
using namespace std;

struct Queue_ {
    int size;
    int f;
    int r;
    int elements[100];
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

void minIndex(struct Queue_ &Q, int n) {
    int min = 10000;
    int min_idx = -1;
    int num = Q.r - Q.f +1;
    int x;
    for (int i=0; i<num; i++) {
        x = dequeue(Q);
        if (min >= x && i < n){
            min = x;
            min_idx = i;
        }
        enqueue(Q, x);
    }
    for (int i=0; i<num; i++) {
        if (i!=min_idx) {
            int number = dequeue(Q);
            enqueue(Q, number);
        } else {
            dequeue(Q);
        }
    }
    enqueue(Q, min);
}

void queue_sort (struct Queue_ &Q, int n) {
    for (int i=n; i>0; i--) {
        minIndex(Q, i);
    }
}

int main() {
    struct Queue_ Q;
    int n=4;
    Q.r=-1;
    Q.f=-1;
    Q.size=100;
    enqueue(Q, 5);
    enqueue(Q, 1);
    enqueue(Q, 7);
    enqueue(Q, 2);
    queue_sort(Q, 4);
    while (Q.f != -1) {
        cout<<dequeue(Q)<<" ";
    }
    return 0;
}
