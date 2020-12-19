#include<bits/stdc++.h>
using namespace std;

union Uni {
    int i;
    char c;
};


struct De_Queue {
    int size;
    int f;
    int r;
    union Uni elements[100];
};

void push_rear(struct De_Queue &Q, union Uni n, int i) {
    if ((Q.r+1)%Q.size == Q.f) {
        cout<<"Queue full";
    } else {
        if (Q.r == -1) {
            Q.r++;
            Q.f++;
        } else {
            Q.r = (Q.r+1)%Q.size;
        }
        if(i == 0) {
            Q.elements[Q.r].i = n.i;
        } else {
        Q.elements[Q.r].c = n.c;
        }
    }
}

void push_front(struct De_Queue &Q, union Uni n, int i) {
    if ((Q.f-1 + Q.size)%Q.size == Q.r) {
        cout<<"Queue full";
    } else {
        if (Q.r == -1) {
            Q.r++;
            Q.f++;
        } else {
            Q.f = (Q.f-1 + Q.size)%Q.size;
        }
        if(i == 0) {
            Q.elements[Q.f].i = n.i;
        } else {
        Q.elements[Q.f].c = n.c;
        }
    }
}

union Uni pop_front(struct De_Queue &Q) {
    if (Q.f == -1) {
        union Uni s;
        cout<<"Queue Empty";
        return s;
    } else {
        union Uni s;
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

union Uni pop_rear(struct De_Queue &Q) {
    if (Q.f == -1) {
        union Uni s;
        cout<<"Queue Empty";
        return s;
    } else {
        union Uni s;
        if (Q.f == Q.r) {
            s = Q.elements[Q.r];
            Q.f = -1;
            Q.r = -1;
        } else {
            s = Q.elements[Q.r];
            Q.r = (Q.r -1 + Q.size)%Q.size;
        }
        return s;
    }
}

int main() {
    union Uni arr1[] = {'N', 'I', 17, 'T', 9, 20, 'C', 'S', 21, 'E'};
    int tags[] = {1,1,0,1,0, 0, 1,1,0,1};
    int arr2[10];
    int k=0, index=0;
    struct De_Queue Q;
    Q.f=-1;
    Q.r=-1;
    Q.size = 50;
    for (int i=0; i<10; i++) {
        if (tags[i] == 1) {
            push_rear(Q, arr1[i], 1);
            tags[index] = 1;
            index++;
        } else {
            arr2[k] = arr1[i].i;
            k++;
        }
    }
    for (int i=0; i<k; i++) {
        union Uni x;
        x.i = arr2[i];
        push_rear(Q, x, 0);
        tags[index] = 0;
        index++;
    }
    for (int i=0; i<10-k; i++) {
        union Uni x = pop_front(Q);
        push_rear(Q, x, tags[i]);
    }
    while (Q.r != -1) {
        for (int i=0; i<4; i++) {
            cout<<pop_front(Q).i<<" ";
        }
        for(int i=0; i<6; i++) {
            cout<<pop_front(Q).c<<" ";
        }
    }
    return 0;
}

