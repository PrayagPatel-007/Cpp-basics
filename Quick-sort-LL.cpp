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
        cout<<p->data<<" ";
        if (p -> next == NULL) {
            cout<<endl;
        }
        print(p->next);
    }
}

void delete_k (lptr &L, int k) {
    if (L == NULL) {
        cout<<"k not found";
        return;
    }
    if (L->data != k) {
        delete_k(L -> next, k);
    } else {
        L = L -> next;
    }
}

void add_before (lptr &L, lptr p, int x, int y) {
    if (p == NULL) {
        cout<<"Y not found";
        return;
    }
    if (L == NULL) {
        cout<<"Empty";
        return;
    }
    if (L -> data == y){
        lptr T;
        T = new(node);
        T -> data = x;
        T -> next = L;
        L = T;
        return;
    }
    if (p->next->data != y) {
        add_before (L, p->next, x, y);
    } else {
        lptr T;
        T = new(node);
        T -> data = x;
        T -> next = p -> next;
        p -> next = T;
        return;
    }
}

void partition_ (lptr &L) {
    if (L == NULL || L->next == NULL) {
        return;
    }
    int a = L -> data;
    lptr p = L -> next;
    int y = L -> data;
    while (p != NULL) {
        if (p -> data < y) {
            int x = p -> data;
            delete_k(L, p->data);
            add_before(L, L, x, y);
        }
        p = p -> next;
    }
    int b = L -> data;
    if (a == b) {
        partition_(L->next);
    } else {
        partition_(L);
    }
}


int main() {
    lptr L1 =  NULL;
    int n;
    cin>>n;
    while (n != -1) {
        insert(L1, L1, n);
        cin>>n;
    }
    partition_(L1);
    print(L1);
    return 0;
}
