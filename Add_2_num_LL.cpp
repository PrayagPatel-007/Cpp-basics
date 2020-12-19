#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

typedef struct node *lptr;

void insert (lptr &L, lptr p, int n) {
    if (L == NULL) {
        L = new(node);
        L -> data = n;
        L -> next = NULL;
        return;
    }
    lptr T;
    T = new(node);
    T -> data = n;
    T -> next = NULL;
    if (p->next != NULL) {
        p = p -> next;
        insert (L, p, n);
    } else {
        p -> next = T;
    }
}

void print (lptr p) {
    if (p != NULL) {
        cout<<p->data;
        if (p -> next == NULL) {
            cout<<endl;
        }
        print(p->next);
    }
}

void add_front (lptr &L, int n) {
    lptr T;
    T = new(node);
    T -> data = n;
    T -> next = L;
    L = T;
}

int del_back(lptr &L, lptr p){
    if (L == NULL) {
        return 0;
    }
    else if (L->next == NULL){
        int x = L -> data;
        L = NULL;
        return x;
    } else {
        while (p -> next -> next != NULL) {
            p = p -> next;
        }
        int x = p -> next -> data;
        p -> next = NULL;
        return x;
    }
}

void add_ (lptr &p1, lptr &p2, lptr &L3, int carry) {
    int sum;
    if (p1 == NULL && p2 == NULL) {
        if (carry != 0) {
            add_front(L3, carry);
        }
        return; 
    }
    int x = del_back(p1, p1) + del_back(p2, p2);
    add_front(L3, (x + carry) % 10);
    carry = (x + carry) / 10;
    add_ (p1, p2, L3, carry);
}

int main() {
    lptr L1 = NULL, L2 = NULL;
    int n, i = 1;
    cin>>n;
    while (n / i > 0) {
        i *= 10;
    }
    i = i/10;
    while (i > 1) {
        insert(L1, L1, (n/i)%10);
        i = i/10;
    }
    insert(L1, L1, n%10);
    cin>>n;
    while (n / i > 0) {
        i *= 10;
    }
    i = i/10;
    while (i > 1) {
        insert(L2, L2, (n/i)%10);
        i = i/10;
    }
    insert(L2, L2, n%10);
    lptr L3 = NULL;
    add_ (L1, L2, L3, 0);
    print(L3);
    return 0;
}



