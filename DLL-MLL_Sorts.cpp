#include<bits/stdc++.h>
using namespace std;

struct mnode {
    int mdata;
    struct mnode *dlink;
    struct mnode *mnext;
};

typedef struct mnode *mlptr;

struct dlnode {
    struct dlnode *left;
    mlptr data;
    struct dlnode *right;
};

typedef struct dlnode *dlptr;

void node_insert (mlptr &L) {
    int n;
    cin>>n;
    if (n != -1){
        L = new(mnode);
        L -> mdata = n;
        L -> mnext = NULL;
        L -> dlink = NULL;
        node_insert(L -> dlink);
    }
}

void create_mll (mlptr &ML) {
    int n, tag;
    cin>>n;
    if (n != -2){
        cin>>tag;
        ML = new(mnode);
        ML -> mdata = n;
        ML -> dlink = NULL;
        ML -> mnext = NULL;
        if (tag == 1) {
            node_insert (ML -> dlink);
            create_mll(ML -> mnext);
        } else if (tag == 0) {
            create_mll(ML -> mnext);
        }
    }
}

void add_end(dlptr &D, mlptr n){
    if(D == NULL){
        D = new(dlnode);
        D -> right = NULL;
        D -> left = NULL;
        D -> data = n;
        return;
    }
    if(D -> right == NULL){
        D -> right = new(dlnode);
        D -> right -> data = n;
        D -> right -> left = D;
        D ->  right->right=NULL;
        return;
    }
    add_end(D->right, n);
}

mlptr del_front(dlptr &D){
    if(D != NULL){
        mlptr x = D -> data;
        D = D -> right;
        return x;
    }
}

void sort_mll(dlptr &D){
    if(D == NULL){
        return;
    }
    mlptr ML = del_front(D);
    cout<<ML->mdata<<" ";
    if(ML -> dlink == NULL && ML->mnext == NULL){
    }else if(ML -> dlink == NULL && ML->mnext!=NULL){
        add_end(D, ML->mnext);
        sort_mll(D);
    } else if (ML->dlink !=NULL && ML->mnext == NULL){
        add_end(D, ML->dlink);
        sort_mll(D);
    }else if(ML -> dlink -> mdata > ML -> mnext -> mdata){
        add_end(D, ML->mnext);
        sort_mll(D);
        add_end(D, ML->dlink);
        sort_mll(D);
    } else if(ML -> dlink -> mdata < ML -> mnext -> mdata) {
        add_end(D, ML->dlink);
        sort_mll(D);
        add_end(D, ML->mnext);
        sort_mll(D);
    }
}

void print(dlptr D){
    if(D != NULL){
        cout<<D->data<<" ";
        print(D->right);
    }
}

int main() {
    mlptr ML = NULL;
    dlptr D = NULL;
    create_mll(ML);
    add_end(D, ML);
    sort_mll(D);
    print(D);
    return 0;
}


/* 3 1 7 8 -1 9 1 15 45 -1 12 1 18 72 -1 36 0 -2
3 7 8
9 15 45
12 18 72
36

3 9  12 36
7 15 18
8 45 72

3

9 12 36 
7 8 15 18 45 72

*/