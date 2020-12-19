#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    bool b;
    struct node *next;
};

typedef struct node *lptr;

void insert (lptr &L, lptr p, int n, bool b) {
    if (L == NULL) {
        L = new(node);
        L -> data = n;
        L -> b = b;
        L -> next = NULL;
        return;
    }
    lptr T;
    T = new(node);
    T -> data = n;
    T -> b = b;
    T -> next = NULL;
    if (p->next != NULL) {
        p = p -> next;
        insert (L, p, n, b);
    } else {
        p -> next = T;
    }
}

void delete_elem (lptr p) {
    lptr T = p;
    while (T != NULL) {
        lptr T2 = p;
        int i=1;
        while ( i != T-> data) {
            if (T2 -> next == NULL){
                break;
            }
            T2 = T2 -> next;
            i++;
        }
        if (i == T->data) {
            T2 -> b = false;
        }
        T = T -> next;
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


void delete_false (lptr &L) {
    if (L == NULL) {
        return;
    }
    if (L -> b == false) {
        L = L -> next;
        delete_false(L);
    } else {
        delete_false(L -> next);
    }
}

int main () {
    int n;
    lptr L = NULL;
    cin>>n;
    while (n != -1) {
        insert(L, L, n, true);
        cin>>n;
    }
    delete_elem(L);
    delete_false(L);
    print(L);
    return 0;
}


