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



bool is_palindrome(lptr &L) {
    if (L == NULL || L->next == NULL) {
        return true;
    }
    lptr p = L;
    int x = L -> data;
    L = L -> next;
    while ( p->next->next != NULL) {
        p = p -> next;
    }
    int y = p -> next -> data;
    p -> next = NULL;
    if (x == y) {
        return is_palindrome(L);
    } else {
        return false;
    }
}

void remove_duplicates (lptr &L, int x) {
    if (L == NULL) {
        return;
    }
    if (x == L -> data) {
        L = L -> next;
        remove_duplicates (L, x);
    } else {
        remove_duplicates(L->next, L->data);
    }
}


void remove_duplicates_u (lptr p) {
    if (p -> next == NULL || p == NULL) {
        return;
    }
    lptr T = p;
    while (T -> next != NULL) {
        if (T -> next -> data == p -> data) {
            T -> next = T -> next -> next;
        } else {
            T = T -> next;
        }
    }
    remove_duplicates_u(p -> next);
}

void remove_duplicates_last (lptr p, lptr p2) {
    if (p -> next == NULL || p == NULL) {
        return;
    }
    lptr T = p;
    int n=0, count=0;
    while (T -> next != NULL) {
        n++;
        if (T -> next -> data == p -> data) {
            count = n;
            T = T -> next;
        } else {
            T = T -> next;
        }
    }
    if (count != 0) {
        lptr T = p;
        int n=0;
        while (T -> next != NULL) {
            n++;
            if (T -> next -> data == p -> data) {
                if (count == n) {
                    T -> next = T -> next -> next;
                } else {
                    T = T -> next;
                }
            } else {
                T = T -> next;
            }
        }
    }
    p = p -> next;
    lptr T2 = p2;
    while (T2 != p && p->next != NULL) {
        if (T2 -> data == p -> data){
            T2 = p2;
            p = p -> next;
        } else {
            T2 = T2 -> next;
        }
    }
    remove_duplicates_last(p, p2);
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

void even_odd (lptr &L) {
    lptr p = L;
    int y;
    while (p -> data % 2 == 0) {
        p = p -> next;
    }
    y = p -> data;
    p = L;
    while (p -> next != NULL) {
        if (p -> next -> data % 2 == 0) {
            int x = p->next->data;
            delete_k(L, p->next->data);
            add_before(L, L, x, y);
        }
        p = p -> next;
    }
}



void insertion_sort(lptr &L) {
    lptr T1 = L -> next;
    while (T1 != NULL) {
        lptr T2 = L;
        while (T2 -> data < T1 -> data && T2 != T1) {
            T2 = T2 -> next;
        } 
        if (T2 -> data > T1 -> data) {
            int x = T1 -> data;
            delete_k (L, T1 -> data);
            add_before(L, L, x, T2 -> data);
        }
        T1 = T1 -> next;
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

void swap_k (lptr &L, int k) {
    if(L != NULL && L -> next != NULL) {
        if (k == 1) {
            int x = del_front(L);
            int y = del_back(L, L);
            swap_k(L, k - 1);
            add_front(L, y);
            insert(L, L, x);
        }
        else {
            int x = del_front(L);
            int y = del_back(L, L);
            swap_k(L, k - 1);
            add_front(L, x);
            insert(L, L, y);
        }
    } else {
        return;
    }
}

int num_nodes (lptr p, int count) {
    if (p != NULL) {
        num_nodes(p->next, count + 1);
    }
    if (p == NULL) {
        return count;
    }
}



bool in_ll (lptr L1, lptr L2) {
    bool done = false;
    while (!done) {
        lptr T1 = L1;
        lptr T2 = L2;
        while (T2 != NULL) {
            if (T1 -> data == T2 -> data) {
                T1 = T1 -> next;
                T2 = T2 -> next;
            } else {
                break;
            }
        }
        if (T2 == NULL) {
            return true;
        }
        if (num_nodes(L1, 0) > num_nodes(L2, 0)) {
            L1 = L1 -> next;
        } else {
            break;
        }
    }
    return false;
}

void mergee(lptr L1, lptr L2, lptr &L3) {
    while (L1 != NULL && L2 != NULL) {
        insert(L3, L3, del_front(L1));
        insert(L3, L3, del_front(L2));
    }
    while(L1 != NULL) {
        insert(L3, L3, del_front(L1));
    }
    while(L2 != NULL) {
        insert(L3, L3, del_front(L2));
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
    // cout<<is_palindrome(L)<<endl;
    // L = NULL;
    // cin>>n;
    // while (n != -1) {
    //     insert(L, L, n);
    //     cin>>n;
    // }
    // remove_duplicates(L->next, L->data);
    // print(L);
    // L = NULL;
    // cin>>n;
    // while (n != -1) {
    //     insert(L, L, n);
    //     cin>>n;
    // }
    remove_duplicates_u(L);
    print(L);
    // L = NULL;
    // cin>>n;
    // while (n != -1) {
    //     insert(L, L, n);
    //     cin>>n;
    // }
    // remove_duplicates_last(L, L);
    // print(L);
    // lptr L2 = NULL;
    L = NULL;
    cin>>n;
    while (n != -1) {
        insert(L, L, n);
        cin>>n;
    }
    even_odd(L);
    print(L);
    // L = NULL;
    // cin>>n;
    // while (n != -1) {
    //     insert(L, L, n);
    //     cin>>n;
    // }
    // insertion_sort(L);
    // print(L);
    // L = NULL;
    // cin>>n;
    // while (n != -1) {
    //     insert(L, L, n);
    //     cin>>n;
    // }
    // reverse(L);
    // print(L);
    // L = NULL;
    // cin>>n;
    // while (n != -1) {
    //     insert(L, L, n);
    //     cin>>n;
    // }
    // int k = 3;
    // swap_k(L, k);
    // print(L);
    // lptr L1 = NULL;
    // cin>>n;
    // while (n != -1) {
    //     insert(L1, L1, n);
    //     cin>>n;
    // }
    // L2 = NULL;
    // cin>>n;
    // while (n != -1) {
    //     insert(L2, L2, n);
    //     cin>>n;
    // }
    // cout<<in_ll(L1, L2)<<endl;
    // lptr L3 = NULL;
    // L1 = NULL;
    // cin>>n;
    // while (n != -1) {
    //     insert(L1, L1, n);
    //     cin>>n;
    // }
    // L2 = NULL;
    // cin>>n;
    // while (n != -1) {
    //     insert(L2, L2, n);
    //     cin>>n;
    // }
    // mergee(L1, L2, L3);
    // print(L3);
    return 0;
}