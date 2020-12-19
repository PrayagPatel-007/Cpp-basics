#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

typedef struct node *lptr;

void insert (lptr &L, lptr p, int n) {
    if (n != -9999) {
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
        cout<<"Empty\n";
        return -9999;
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
    if (n != -9999) {
        lptr T;
        T = new(node);
        T -> data = n;
        T -> next = L;
        L = T;
    }
}

int del_back(lptr &L, lptr p){
    if (L == NULL) {
        cout<<"Empty\n";
        return -9999;
    }else if (L->next == NULL){
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

void push(lptr &L, int n) {
    insert(L, L, n);
}

int pop(lptr &L) {
    return del_back(L, L);
}

int peek(lptr p) {
    if (p == NULL) {
        cout<<"Empty";
    }else if (p->next == NULL){
        return p -> data;
    } else {
        while (p -> next -> next != NULL) {
            p = p -> next;
        }
        return p -> next -> data;
    }
}

void enqueue(lptr &L, int n) {
    insert(L, L, n);
}

int dequeue(lptr &L) {
    return del_front(L);
}

int main() {
    lptr L = NULL;
    cout<<"Stack Operations ";
    int n, choice = 0;
    while (choice != -1) {
        cout<<"Push(0) or Pop(1) or -1 to exit: ";
        cin>>choice;
        if(choice == 0) {
            cout<<"Enter Number: ";
            cin>>n;
            push(L, n);
        } else if (choice == 1) {
            pop(L);
        }
    }
    print(L);
    cout<<"Queue Operations ";
    lptr L2 = NULL;
    choice = 0;
    while (choice != -1) {
        cout<<"Enqueue(0) or Dequeue(1) or -1 to exit: ";
        cin>>choice;
        if(choice == 0) {
            cout<<"Enter Number: ";
            cin>>n;
            enqueue(L2, n);
        } else if (choice == 1) {
            dequeue(L2);
        }
    }
    print(L2);
    return 0;
}

