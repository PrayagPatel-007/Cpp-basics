#include<bits/stdc++.h>
using namespace std;

struct cnode {
    char data;
    struct cnode *next;
};

typedef struct cnode *cptr;

void insert_cnode(cptr &C, char n){
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

void print (cptr &C, int m, int i, int count){
    if(count == 0){
        return;
    }
    if(C -> data == 'B'){
        print(C -> next, m, i, count);
    } else if(i == 1){
        C -> data = 'B';
        print(C -> next, m, m, count-1);
    } else {
        print(C -> next, m, i-1, count);
    }
}

int main(){
    cptr C = NULL;
    for(int i=0; i<30; i++){
        insert_cnode(C, 'A');
    }
    make_circular(C);
    int n_b = 30/2;
    print(C, 9, 9, n_b);
    for(int i=0; i<30; i++){
        cout<<C -> data;
        C = C -> next;
    }
    return 0;
}