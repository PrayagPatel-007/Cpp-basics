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

void print(cptr C, int n){
    for(int i=0; i<n; i++){
        int x = C -> data;
        cout<<x<<" ";
        C = C -> next;
        while(C -> data != x){
            cout<<C -> data<<" ";
            C = C -> next;
        }
        cout<<x<<endl;
    }
}

int num_element (cptr C){
    int count=1;
    cptr T = C -> next;
    while(T != C){
        if(T -> data == C -> data){
            count++;
        }
        T = T -> next;
    }
    return count;
}

bool is_before(cptr C, cptr T){
    while(C != T){
        if(C -> data == T -> data){
            return true;
        }
        C = C -> next;
    }
    return false;
}

void print_circles (cptr &C, cptr T){
    if(T -> next == C){
        return;
    }
    if(num_element(T) > 1){
        if(!is_before(C, T)){
            print(T, num_element(T));
        }
    }
    print_circles(C, T->next);
}

int main(){
    int n;
    cptr C = NULL;
    cin>>n;
    while(n != -1){
        insert_cnode(C, n);
        cin>>n;
    }
    make_circular(C);
    print_circles(C, C);
    return 0;
}
