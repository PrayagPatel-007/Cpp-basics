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

int del_front(lptr &L) {
    if (L == NULL) {
        cout<<"Empty";
        return 0;
    }
    if (L -> next == NULL) {
        int x = L -> data;
        L = NULL;
        return x;
    } else {
        int x = L -> data;
        L = L -> next;
        return x;
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
    if (L->next == NULL){
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


void reverse (lptr &L) {
    if (L != NULL && L -> next != NULL) {
        int x = del_front(L);
        int y = del_back(L, L);
        reverse(L);
        add_front(L, y);
        insert(L, L, x);
    } else {
        return;
    }
}



int main() {
    int n, i, j;
    lptr L = NULL;
    lptr L2 = NULL;
    cin>>n;
    while (n != -1) {
        insert(L, L, n);
        cin>>n;
    }
    cin>>i>>j;
    lptr T1 = L;
    lptr T2 = L2;
    while (i != 1) {
        i--;
        j--;
        T1 = T1 -> next;
    }
    while (j != 0) {
        insert(L2, L2, T1 -> data);
        T1 = T1 -> next;
        j--;
    }
    reverse(L2);
    T1 = L;
    T2 = L2;
    i=1;
    j=1;
    while (i != 2) {
        i++;
        j++;
        T1 = T1 -> next;
    }
    while (j != 6) {
        T1 -> data = L2 -> data;
        L2 = L2 -> next;
        T1 = T1 -> next;
        j++;
    }
    print(L);
    return 0;
}


