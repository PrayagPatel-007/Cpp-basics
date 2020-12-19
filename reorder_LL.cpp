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

void reorder (lptr p, lptr p1) {
    while (p != NULL && p->next != NULL && p->next->next != NULL) {
        lptr T = p1;
        while (T -> next -> next != NULL) {
            T = T -> next;
        }
        T -> next -> next = p -> next;
        p -> next = T -> next;
        T -> next = NULL;
        p = p ->next->next;
    }
}

int main() {
    lptr L = NULL;
    int n;
    cin>>n;
    while (n != -1) {
        insert(L, L, n);
        cin>>n;
    }
    reorder(L, L);
    print(L);
    return 0;
}
