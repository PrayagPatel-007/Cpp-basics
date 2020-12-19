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
    } else if (ML->dlink !=NULL && ML->mnext == NULL){
        add_end(D, ML->dlink);
    }else if(ML -> dlink -> mdata > ML -> mnext -> mdata){
        add_end(D, ML->mnext);
        add_end(D, ML->dlink);
    } else if(ML -> dlink -> mdata < ML -> mnext -> mdata) {
        add_end(D, ML->dlink);
        add_end(D, ML->mnext);
    }
    sort_(D);
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

// 3 1 8 15 -1 7 1 12 45 -1 10 1 18 72 -1 36 0 -2

// void add_before(dlptr &D, int x, int y){
//     if(D == NULL){
//         cout<<"No "<<y<<" was found!";
//         return;
//     }
//     if(D != NULL){
//         if(D -> data == y){
//             dlptr T = new(dlnode);
//             T -> data = x;
//             T -> right = D;
//             T -> left = D -> left;
//             D -> left = T;
//             if(T -> left == NULL){
//                 D = T;
//                 return;
//             }
//             T -> left -> right = T;
//             return;
//         }
//         add_before(D->right, x, y);
//     }
// }

// void insert_sort(dlptr &D, int k){
//     if(D == NULL){
//         add_end(D, k);
//     } else {
//         dlptr T = D;
//         while(T != NULL && T -> data < k){
//             T = T -> right;
//         }
//         if(T == NULL){
//             add_end(D, k);
//         } else {
//             add_before(D, k, T->data);
//         }
//     }
// }

// void sort_mll(mlptr ML, dlptr &D) {
//     if(ML != NULL){
//         insert_sort(D, ML->mdata);
//         sort_mll(ML -> dlink, D);
//         sort_mll(ML -> mnext, D);
//     }
// }