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

void union_ (lptr p1, lptr p2, lptr &L3) {
    while (p1 != NULL && p2 != NULL){
        if (p1 -> data < p2 -> data) {
            insert(L3, L3, p1 -> data);
            p1 = p1 -> next;
        } 
        else if (p1 -> data > p2 -> data) {
            insert(L3, L3, p2 ->data);
            p2 = p2 -> next;
        } else {
            insert(L3, L3, p1 ->data);
            p1 = p1 ->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insert(L3, L3, p1 -> data);
        p1 = p1 -> next;
    }
    while (p2 != NULL) {
        insert(L3, L3, p2 -> data);
        p2 = p2 -> next;
    }
}

void intersection_ (lptr p1, lptr p2, lptr &L3) {
    while (p1 != NULL) {
        lptr T = p2;
        while (T != NULL && p1 -> data != T -> data) {
            T = T -> next;
        }
        if (T == NULL) {
            p1 = p1 -> next;
        } else if (p1 -> data == T -> data) {
            insert(L3, L3, p1 -> data);
            p1 = p1 -> next;
        } else {
        }
    }
}

void difference_ (lptr p1, lptr p2, lptr&L3) {
    lptr T = NULL;
    intersection_(p1, p2, T);
    while (p1 != NULL) {
        if (T == NULL) {
            insert(L3, L3, p1 -> data);
            p1 = p1 -> next;
        }else if (p1 -> data != T -> data) {
            insert(L3, L3, p1 -> data);
            p1 = p1 -> next;
        } else {
            p1 = p1 -> next;
            T = T -> next;
        }
    }
}

void u_intersection_ (lptr p1, lptr p2, lptr &L3) {
    while(p1 != NULL) {
        lptr p3 = p2;
        while (p3 != NULL) {
            if (p1 -> data == p3 -> data) {
                insert (L3, L3, p1 -> data);
                break;
            }
            p3 = p3 -> next;
        }
        p1 = p1 -> next;
    }
}


void u_union_ (lptr p1, lptr p2, lptr &L3){
    lptr T = NULL;
    u_intersection_(p1, p2, T);
    while (p1 != NULL) {
        insert(L3, L3, p1 -> data);
        p1 = p1 -> next;
    }
    while (p2 != NULL) {
        lptr T2 = T;
        while (T2 != NULL && T2-> data != p2 -> data) {
            T2 = T2 -> next;
        }
        if (T2 == NULL) {
            insert(L3, L3, p2 -> data);
            p2 = p2 -> next;
        } else {
            p2 = p2 -> next;
        }
    }
}

void u_diff_ (lptr p1, lptr p2, lptr &L3) {
    lptr T = NULL;
    u_intersection_(p1, p2, T);
    while (p1 != NULL) {
        lptr T2 = T;
        while (T2 != NULL && T2-> data != p1 -> data) {
            T2 = T2 -> next;
        }
        if (T2 == NULL) {
            insert(L3, L3, p1 -> data);
            p1 = p1 -> next;
        } else {
            p1 = p1 -> next;
        }
    }
}

int main () {
    lptr L1, L2;
    lptr L3 = NULL;
    L1 = NULL;
    L2 = NULL;
    int n;
    cin>>n;
    while(n != -1) {
        insert(L1, L1, n);
        cin>>n;
    }
    cin>>n;
    while(n != -1) {
        insert(L2, L2, n);
        cin>>n;
    }
    union_ (L1, L2, L3);
    print(L3);
    L3 = NULL;
    intersection_(L1, L2, L3);
    print(L3);
    L3 = NULL;
    difference_(L1, L2, L3);
    print(L3);
    L1 = NULL;
    L2 = NULL;
    L3 = NULL;
    cin>>n;
    while(n != -1) {
        insert(L1, L1, n);
        cin>>n;
    }
    cin>>n;
    while(n != -1) {
        insert(L2, L2, n);
        cin>>n;
    }
    u_union_(L1, L2, L3);
    print(L3);
    L3 = NULL;
    u_intersection_(L1, L2, L3);
    print(L3);
    L3 = NULL;
    u_diff_(L1, L2, L3);
    print(L3);
    return 0;
}
