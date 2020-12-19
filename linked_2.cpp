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

void add_front (lptr &L, int n) {
    lptr T;
    T = new(node);
    T -> data = n;
    T -> next = L;
    L = T;
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

void add_after (lptr p, int x, int y) {
    if (p == NULL) {
        cout<<"Y not found";
        return;
    }
    if (p->data != y) {
        add_after (p->next, x, y);
    } else {
        lptr T;
        T = new(node);
        T -> data = x;
        T -> next = p -> next;
        p -> next = T;
        return;
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

int find_min (lptr p, int min) {
    if (p == NULL) {
        return min;
    }
    if (p != NULL) {
        if ( min > p -> data) {
            min = p -> data;
        }
        find_min (p -> next, min);
    }
}

int find_max (lptr p, int max) {
    if (p == NULL) {
        return max;
    }
    if (p != NULL) {
        if ( max < p -> data) {
            max = p -> data;
        }
        find_max(p -> next, max);
    }
}



int main() {
    int n, k, x, y;
    lptr L = NULL;
    cin>>n;
    while (n != -1) {
        insert(L, L, n);
        cin>>n;
    }
    print(L);
    cin>>k;
    add_front(L, k);
    print(L);
    cin>>x>>y;
    add_before(L, L, x, y);
    print(L);
    cin>>x>>y;
    add_after(L, x, y);
    print(L);
    cin>>k;
    delete_k(L, k);
    print(L);
    delete_k (L, find_min(L, 10000));
    print(L);
    delete_k (L, find_max(L, -10000));
    print(L);
    return 0;
}