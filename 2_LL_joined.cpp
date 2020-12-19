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

lptr kth_node (lptr p) {
    while (p -> next -> data != 6) {
        p = p -> next;
    }
    return p -> next;
}

void last_node_redirect(lptr p, lptr t) {
    while (p -> next != NULL) {
        p = p-> next;
    }
    p -> next = t;
}

int find_node (lptr L1, lptr L2) {
    while (L2 != NULL) {
        lptr p = L1;
        while(p != NULL) {
            if (p == L2) {
                return p -> data;
            }
            p = p -> next;
        }
        L2 = L2 -> next;
    }
}

int main () {
    lptr L1 =  NULL;
    int n;
    cin>>n;
    while (n != -1) {
        insert(L1, L1, n);
        cin>>n;
    }
    lptr L2 =  NULL;
    cin>>n;
    while (n != -1) {
        insert(L2, L2, n);
        cin>>n;
    }
    last_node_redirect(L2, kth_node(L1));
    cout<<find_node(L1, L2);
    return 0;
}





