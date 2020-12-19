#include<bits/stdc++.h>
using namespace std;

struct cnode {
    int data;
    struct cnode *next;
};

typedef struct cnode *cptr;

void insert_cnode(cptr &C, int n){
    if(C == NULL){
        C = new(cnode);
        C -> data = n;
        C -> next = NULL;
        return;
    }
    insert_cnode(C -> next, n);
}

void make_circular(cptr &C){
    cptr T = C;
    while(T -> next != NULL){
        T = T -> next;
    }
    T -> next = C;
}

void josephus (cptr &C, int n){
    if(C -> next == C){
        cout<<C->data;
        return;
    }
    if(n == 2){
        C -> next = C -> next -> next;
        josephus(C -> next, n-1);
    } else {
        C -> next = C -> next -> next -> next;
        josephus(C -> next, n-2);
    }
}

int main(){
    int n;
    cptr C = NULL;
    cin>>n;
    for(int i=1; i<=n; i++){
        insert_cnode(C, i);
    }
    make_circular(C);
    josephus(C, n);
    return 0;
}