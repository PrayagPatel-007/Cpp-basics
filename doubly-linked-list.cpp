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

void add_front(dlptr &D, int n){
    dlptr T = new(dlnode);
    T -> data = n;
    T -> left = NULL;
    T -> right = D;
    D = T;
}

void add_end(dlptr &D, int n){
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

int del_front(dlptr &D){
    if(D == NULL){
        cout<<"DLL empty!";
        return 0;
    }
    int x = D -> data;
    D = D -> right;
    return x;
}

int del_end(dlptr &D){
    if(D == NULL){
        cout<<"DLL Empty!";
        return 0;
    }
    if(D -> right == NULL){
        int x = D -> data;
        D = NULL;
        return x;
    }
    del_end(D->right);
}

void print(dlptr D){
    if(D != NULL){
        cout<<D->data<<" ";
        print(D->right);
    }
}

void print_backward(dlptr D){
    if(D != NULL){
        cout<<D->data<<" ";
        print_backward(D->left);
    }
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

void add_before(dlptr &D, int x, int y){
    if(D == NULL){
        cout<<"No "<<y<<" was found!";
        return;
    }
    if(D != NULL){
        if(D -> data == y){
            dlptr T = new(dlnode);
            T -> data = x;
            T -> right = D;
            T -> left = D -> left;
            D -> left = T;
            if(T -> left == NULL){
                D = T;
                return;
            }
            T -> left -> right = T;
            return;
        }
        add_before(D->right, x, y);
    }
}

void add_after(dlptr &D, int x, int y){
    if(D == NULL){
        cout<<"No "<<y<<" was found!";
        return;
    }
    if(D != NULL){
        if(D -> data == y){
            dlptr T = new(dlnode);
            T -> data = x;
            T -> right = D -> right;
            T -> left = D;
            D -> right = T;
            if(T -> right == NULL){
                return;
            }
            T -> right -> left = T;
            return;
        }
        add_after(D->right, x, y);
    }
}

bool find_k(dlptr D, int k){
    if(D == NULL){
        return false;
    }
    if(D != NULL){
        if(D -> data == k){
            return true;
        }
        find_k(D -> right, k);
    }
}

void delete_k(dlptr D, int k){
    if(D ==NULL){
        cout<<k<<" not found!";
        return;
    }
    if(D -> data == k){
        D -> left -> right = D -> right;
        D -> right -> left = D -> left;
        return;
    }
    delete_k(D->right, k);
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

void swape(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

dlptr partition_ (dlptr D1, dlptr D2) {
    dlptr T = D1;
    dlptr T2 = D2;
    D1 = D1 -> right;
    while(is_next(D1, D2)){
        while(D1 -> data < T -> data){
            if(D1 == T2){
                break;
            }
            D1 = D1->right;
        }
        while(D2 -> data > T -> data) {
            D2 = D2->left;
        }
        if(is_next(D1, D2)){
            swape(D1 -> data, D2 -> data);
        }
    }
    if(T -> data > D2 -> data){
        swape(T->data, D2 -> data);
    }
    return D2;
}

void quick_sort(dlptr D1, dlptr D2){
    if(is_next(D1, D2)){
        dlptr T = partition_(D1, D2);
        if(T -> left != NULL && D1 != T->left){
            quick_sort(D1, T->left);
        }
        if(T -> right != NULL && T->right!=D2){
            quick_sort(T->right, D2);
        }
    }
}

int main(){
    dlptr D = NULL;
    create_dll(D);
    // del_front(D);
    // add_front(D, 13);
    // add_end(D, 14);
    // del_end(D);
    // add_before(D, 14, 3);
    // add_after(D, 15, 6);
    // delete_k(D, 3);
    // dlptr last = last_node(D);
    // print_backward(last);
    // cout<<endl;
    quick_sort(D, last_node(D));
    print(D);
    return 0;
}


/* 1 2 3 4 5 6 -1 */




