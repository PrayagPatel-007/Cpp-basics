#include<bits/stdc++.h>
using namespace std;

struct De_Queue {
    int size;
    int f[2];
    int r[2];
    int elements[100];
};

void push_rear(struct De_Queue &Q, int n, int i) {
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

void push_front(struct De_Queue &Q, int n, int i) {
    if ((Q.f[i]-1 + Q.size)%Q.size == Q.r[i]) {
        cout<<"Queue full";
    } else {
        if (Q.r[i] == -1 + i*Q.size) {
            Q.r[i]++;
            Q.f[i]++;
        } else {
            Q.f[i] = (Q.f[i]-1 + Q.size)%Q.size;
        }
        Q.elements[Q.f[i]] = n;
    }
}

int pop_front(struct De_Queue &Q, int i) {
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
            Q.f[i] = (Q.f[i] +1)%Q.size;
        }
        return s;
    }
} 

int pop_rear(struct De_Queue &Q, int i) {
    if (Q.f[i] == -1 + Q.size*i) {
        cout<<"Queue Empty";
        return 0;
    } else {
        int s;
        if (Q.f[i] == Q.r[i]) {
            s = Q.elements[Q.r[i]];
            Q.f[i] = -1 +Q.size*i;
            Q.r[i] = -1 + Q.size*i;
        } else {
            s = Q.elements[Q.r[i]];
            Q.r[i] = (Q.r[i] -1 + Q.size)%Q.size;
        }
        return s;
    }
}

void push(struct De_Queue &Q, int n) {
    push_front(Q, n, 0);
}

int pop(struct De_Queue &Q){
    return pop_front(Q, 0);
}

void enqueue (struct De_Queue &Q, int n) {
    push_rear(Q, n, 1);
}

int dequeue (struct De_Queue &Q) {
    return pop_front(Q, 1);
}


int main() {
    struct De_Queue Q;
    Q.f[0]=-1;
    Q.r[0]=-1;
    Q.size = 20;
    Q.f[1]=19;
    Q.r[1]=19;
    push(Q, 1);
    push(Q, 2);
    push(Q, 10);
    pop(Q);
    enqueue(Q, 23);
    enqueue(Q, 24);
    enqueue(Q, 24);
    dequeue(Q);
    while (Q.f[0] != -1) {
        cout<<pop(Q)<<" ";
    }
    while (Q.f[1] != -1 + 20) {
        cout<<dequeue(Q)<<" ";
    }
    return 0;
}