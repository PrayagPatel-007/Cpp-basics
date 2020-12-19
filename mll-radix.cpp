#include<bits/stdc++.h>
using namespace std;

struct mnode {
    struct node *link[10] = {NULL};
};

struct node {
    int data;
    struct node *next;
};

typedef struct mnode *mlptr;
typedef struct node *lptr;

void node_insert (lptr &L, int n) {
    if (L == NULL) {
        L = new(node);
        L -> data = n;
        L -> next = NULL;
        return;
    }
    node_insert (L -> next, n);
}

void rad_sort (mlptr &ML, int arr[]){
    int ind = 0;
    for(int i=0; i<10; i++){
        while(ML -> link[i] != NULL){
            arr[ind] = ML->link[i]->data;
            ML -> link[i] = ML -> link[i] -> next;
            ind++;
        }
    }
}

void rad (mlptr ML, int i, int arr[], int n) {
    for(int j = 0; j<n; j++) {
        node_insert(ML -> link [(arr[j] / (int)(pow(10, i)+0.5)) % 10], arr[j]);
    }
}

void radix(mlptr &ML, int arr[], int n){
    for(int i=0; i<5; i++){
        rad(ML, i, arr, n);
        rad_sort(ML, arr);
    }
}

void print(mlptr ML){
    for(int i=0; i<10; i++){
        lptr p = ML->link[i];
        while(p!= NULL){
            cout<<p->data<<" ";
        }
    }
}

int main(){
    mlptr ML = new(mnode);
    int n;
    cin>>n;
    int arr[100];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    radix(ML, arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

