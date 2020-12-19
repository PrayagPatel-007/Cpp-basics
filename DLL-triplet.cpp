#include<bits/stdc++.h>
using namespace std;

struct dlnode {
    struct dlnode *left;
    int data;
    struct dlnode *right;
};

typedef struct dlnode *dlptr;

void create_dll (dlptr &D){
    int n;
    cin>>n;
    if(n != -1){
        if(D == NULL){
            D = new(dlnode);
            D -> data = n;
            D -> left = NULL;
            D -> right = NULL;
            create_dll(D);
        } else {
            dlptr T = new(dlnode);
            T -> data = n;
            T -> left = D;
            T -> right = NULL;
            D -> right = T;
            create_dll(T);
        }
    }
}

bool is_next(dlptr D1, dlptr D2){
    D1 = D1 -> right;
    while(D1 != NULL){
        if(D1 == D2){
            return true;
        }
        D1 = D1 -> right;
    }
    return false;
}

dlptr last_node(dlptr D){
    if(D == NULL){
        cout<<"NO elements";
        return D;
    }
    if(D->right == NULL){
        return D;
    }
    last_node(D->right);
}


void print_triplets(dlptr D, dlptr D1, dlptr L, int sum){
    if(D != NULL){
        int s = sum - 2*(D->data);
        dlptr l = D1;
        dlptr h = L;
        while(is_next(l, h)){
            if(l == D){
                l = l -> right;
            }else if(h == D){
                h = h -> left;
            }else if(l -> data + h -> data < s){
                l = l->right;
            }else if(l -> data + h -> data > s) {
                h = h->left;
            } else {
                cout<<D->data<<" "<<l->data<<" "<<h->data<<endl;
                l = l -> right;
                h = h -> left;
            }
        }
        print_triplets(D->right, D1, L, sum);
    }
}

int main(){
    dlptr D = NULL;
    int sum;
    create_dll(D);
    cin>>sum;
    print_triplets(D, D, last_node(D), sum);
    return 0;
}
