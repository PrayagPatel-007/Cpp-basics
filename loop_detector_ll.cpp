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

bool is_loop (lptr sp, lptr fp) {
    if (fp == NULL) {
        return false;
    }
    if (sp == fp) {
        return true;
    }
    else {
        if (fp -> next == NULL) {
            return false;
        } else {
            sp = sp -> next;
            fp = fp -> next -> next;
            is_loop(sp, fp);
        }
    }
}

int loop_start (lptr p) {
    lptr T = p;
    while(T -> next != NULL) {
        lptr T2 = p;
        while (T2 != T ) {
            if (T2 == T -> next) {
                return T2 -> data;
            }
            T2 = T2 -> next;
        }
        T = T -> next;
    }
}

int main() {
    int n;
    lptr L = NULL;
    cin>>n;
    while (n != -1) {
        insert(L, L, n);
        cin>>n;
    }
    lptr p = L;
    lptr T;
    int i = 0;
    while (p -> next != NULL) {
        i++;
        if (i == 5) {
            T = p;
        }
        p = p -> next;
    }
    p -> next = T;
    cout<<is_loop(L->next, L->next->next)<<" ";
    cout<<loop_start(L);
    return 0;
}