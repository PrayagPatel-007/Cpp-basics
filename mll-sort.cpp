#include<bits/stdc++.h>
using namespace std;

struct mnode {
    int mdata;
    struct mnode *dlink;
    struct mnode *mnext;
};

typedef struct mnode *mlptr;


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

// void find_min (mlptr &ML, int &min1, int &min2) {
//     if (ML != NULL) {
//         mlptr p = ML;
//         while(p != NULL) {
//             if (min1 > p -> mdata && min2 < p -> mdata){
//                 min1 = p -> mdata;
//             }
//             p = p -> dlink;
//         }
//         find_min(ML -> mnext, min1, min2);
//     }
// }

// void sort (mlptr &ML) {
//     int min1 = 10000;
//     int min2 = -10000;
//     while(true) {
//         int min1 = 10000;
//         find_min(ML, min1, min2);
//         if(min1 == 10000){
//             return;
//         }
//         cout<<min1<<" ";
//         min2 = min1;
//     }
// }

void print_sorted(mlptr ML) {
    cout<<ML->mdata<<" ";
    if(ML -> mnext -> mdata < ML -> dlink -> mdata) {
        print_sorted(ML -> mnext);
    } else {
        print_sorted(ML -> dlink);
    }
}

int main() {
    mlptr ML = NULL;
    create_mll(ML);
    sort(ML);
    return 0;
}

