#include<bits/stdc++.h>
using namespace std;

struct mnode {
    int data;
    int count;
    struct mnode *ptr[10] = {NULL};
};

typedef struct mnode *mlptr;

void create_mll (mlptr &ML){
    int n, tag;
    cin>>n;
    cin>>tag;
    ML = new(mnode);
    ML -> data = n;
    ML -> count = tag;
    // cout<<ML->data<<" ";
    if(tag == 0) {
        return;
    }
    for(int i=0; i<tag; i++) {
        create_mll(ML -> ptr[i]);
    }
}

void find_path (int arr[], int d, mlptr s, int lastIndex) {
    if (s == NULL) {
        return;
    }
    if (s -> data == d){
        arr[lastIndex] = d;
        for(int i=0; i<=lastIndex; i++) {
            cout<<arr[i]<<" ";
        }
        return;
    }
    arr[lastIndex] = s -> data;
    for (int i =0 ; i< s -> count; i++) {
        find_path(arr, d, s->ptr[i], lastIndex+1);
    }
}

void find_node (mlptr ML, int s, mlptr &T) {
    if (ML != NULL) {
        if (ML -> data == s) {
            T = ML;
            return;
        }
        for (int i=0; i<ML->count; i++) {
            find_node(ML->ptr[i], s, T);
        }
    }
}

void print_path (mlptr ML, int s, int d, int arr[]) {
    mlptr T;
    find_node(ML, s, T);
    find_path(arr, d, T, 0);
}


int main() {
    mlptr ML = NULL;
    int s, t;
    create_mll(ML);
    int arr[100];
    cin>>s>>t;
    print_path(ML, s, t, arr);
    return 0;
}


