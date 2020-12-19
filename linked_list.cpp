#include<bits/stdc++.h>
using namespace std;

typedef struct node *lptr;

struct node {
    int data;
    struct node *next;
};

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
        cout<<p -> data<<" ";
        print(p -> next);
    }
}

void print_reverse (lptr p) {
    if (p != NULL) {
        print_reverse(p -> next);
        cout<<p -> data<<" ";
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

int find_mid (lptr p, lptr sp, lptr fp) {
    if ( fp -> next == NULL) {
        return sp -> data;
    }
    else {
        find_mid(p, sp->next, fp->next->next);
    }
}

int num_even (lptr p, int count) {
    if (p == NULL) {
        return count;
    }
    if (p != NULL) {
        if (p -> data % 2 == 0) {
            count ++;
        }
        num_even(p->next, count);
    }
} 

int num_odd (lptr p, int count) {
    if (p == NULL) {
        return count;
    }
    if (p != NULL) {
        if (p -> data % 2 != 0) {
            count ++;
        }
        num_odd (p -> next, count);
    }
}

int find_k (lptr p, int k) {
    if ( p == NULL) {
        return 0;
    }
    if (p != NULL) {
        if (p -> data == k) {
            return 1;
        } else {
            find_k(p -> next, k);
        }
    }
}


int main() {
    lptr L = NULL;
    int n, k;
    cin>>n;
    while (n != -1) {
        insert(L, L, n);
        cin>>n;
    }
    print(L);
    cout<<endl;
    print_reverse(L);
    cout<<endl<<num_nodes(L, 0)<<endl;
    cout<<find_min(L, 10000)<<endl<<find_max(L, -10000)<<endl;
    cout<<find_mid(L, L, L)<<endl;
    cout<<num_odd(L, 0)<<endl<<num_even(L, 0)<<endl;
    cin>>k;
    cout<<find_k(L, k)<<endl;
    return 0;
}


