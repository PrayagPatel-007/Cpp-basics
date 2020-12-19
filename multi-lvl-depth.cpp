#include<bits/stdc++.h>
using namespace std;

struct mnode {
    int mdata;
    struct mnode *dlink;
    struct mnode *mnext;
};

typedef struct mnode *mlptr;

void create_mll (mlptr &ML) {
    int n, tag;
    cin>>n;
    if (n != -1){
        cin>>tag;
        ML = new(mnode);
        ML -> mdata = n;
        ML -> dlink = NULL;
        ML -> mnext = NULL;
        if (tag == 1) {
            create_mll (ML -> dlink);
        }
        create_mll(ML -> mnext);
    }
}

void print(mlptr ML) {
    if (ML != NULL) {
        cout<<ML -> mdata<<" ";
        print(ML -> mnext);
    }
}

void level_print (mlptr ML, int i) {
    if (ML != NULL){
        if (i == -1) {
            return;
        }
        if (i == 0){
            print(ML);
        }
        while(ML != NULL) {
            level_print(ML->dlink, i-1);
            ML = ML -> mnext;
        }
    }
}

void num_depth(mlptr ML, int &max, int count) {
    if (ML != NULL) {
        if (ML -> dlink != NULL) {
            count++;
            if (max < count) {
                max = count;
            }
            num_depth(ML -> dlink, max, count);
        }
        num_depth(ML -> mnext, max, count);
    }
}

void level_print_all (mlptr ML) {
    int max = -10000;
    num_depth(ML, max, 0);
    for (int i = 0; i < max; i++)
    {
        level_print(ML, i);
    }
    
}

void depth_print (mlptr ML) {
    if (ML != NULL) {
        cout<<ML->mdata<<" ";
        if (ML -> dlink != NULL) {
            depth_print(ML -> dlink);
        }
        depth_print(ML -> mnext);
    }
}

int main() {
    mlptr ML = NULL;
    create_mll(ML);
    level_print_all(ML);
    cout<<endl;
    depth_print(ML);
    return 0;
}



// 10 1 4 0 20 1 3 0 -1 9 1 63 1 72 0 -1 -1 -1 5 0 12 0 7 1 25 1 2 1 47 1 36 0 -1 86 0 -1 8 0 54 0 -1 6 0 -1 18 0 -1
