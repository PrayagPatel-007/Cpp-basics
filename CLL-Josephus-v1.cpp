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

void josephus (cptr &C, int m, int i){
    if(C -> next == C){
        return;
    }
    if(i == 2){
        cout<<C->next->data<<" ";
        C -> next = C -> next -> next;
        josephus(C -> next, m, m);
    } else {
        josephus(C -> next, m, i-1);
    }
}

int main(){
    int n, m, num;
    cptr C = NULL;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        insert_cnode(C, num);
    }
    make_circular(C);
    cin>>m;
    josephus(C, m, m);
    return 0;
}