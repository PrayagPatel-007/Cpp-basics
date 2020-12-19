#include<bits/stdc++.h>
using namespace std;

union u_gen {
    int i;
    char c;
    float f;
};

struct node {
    union u_gen data;
    struct node *next;
    int tag;
};

typedef struct node *lptr;

void insert (lptr &L, lptr p, union u_gen n, int tag) {
    if (L == NULL) {
        L = new(node);
        L -> data = n;
        L -> tag = tag;
        L -> next = NULL;
        return;
    }
    lptr T;
    T = new(node);
    T -> data = n;
    T -> tag = tag;
    T -> next = NULL;
    if (p->next != NULL) {
        p = p -> next;
        insert (L, p, n, tag);
    } else {
        p -> next = T;
    }
}

void print (lptr p) {
    if (p != NULL) {
        switch(p -> tag) {
            case 0:
                cout<<(p->data).i<<" ";
                break;
            case 1:
                cout<<(p->data).c<<" ";
                break;
            case 2:
                cout<<(p->data).f<<" ";
                break;
        }
        if (p -> next == NULL) {
            cout<<endl;
        }
        print(p->next);
    }

}


struct gen_queue {
    int size;
    int f;
    int r;
    struct node elements[100];
};

void enqueue(struct gen_queue &Q, struct node L) 
{
    if ((Q.r + 1) % Q.size == Q.f)
    {
        cout << "Queue_ full";
    }
    else
    {
        if (Q.r == -1)
        {
            Q.r++;
            Q.f++;
        }
        else
        {
            Q.r = (Q.r + 1) % Q.size;
        }
        Q.elements[Q.r] = L;
    }
}

struct node dequeue(struct gen_queue &Q)
{
    if (Q.f == -1)
    {
        struct node s;
        cout << "Queue_ Empty";
        return s;
    }
    else
    {
        struct node s;
        if (Q.f == Q.r)
        {
            s = Q.elements[Q.f];
            Q.f = -1;
            Q.r = -1;
        }
        else
        {
            s = Q.elements[Q.f];
            Q.f = Q.f+1%Q.size;
        }
        return s;
    }
}

int main() {
    struct gen_queue Q;
    Q.size = 10;
    Q.r = -1;
    Q.f = -1;
    struct node L1;
    L1.data.i = 34;
    L1.tag = 0;
    union u_gen s;
    s.c = 'A';
    insert(L1.next, L1.next, s, 1);
    s.f = 3.7;
    insert(L1.next, L1.next, s, 2);
    
    return 0;
}

