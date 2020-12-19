#include<bits/stdc++.h>
using namespace std;

struct mnode {
    int data;
    int randata;
    struct mnode *next;
    struct mnode *rptr;
    int index;
};

typedef struct mnode *mlptr;

void create_mll(mlptr &ML) {
    int n1, n2, rand;
    cin>>n1>>n2;
    ML = new(mnode);
    ML -> data = n1;
    ML -> next = NULL;
    ML -> index = 0;
    cin>>rand;
    ML -> randata = rand;
    if (n2 == 0) {
        return;
    }
    create_mll(ML -> next);
}

void find_node(mlptr ML, int i, mlptr &T){
    if(ML -> data == i){
        T = ML;
        return;
    }
    find_node(ML->next, i, T);
}

void create_connection (mlptr &ML, int i){
    if(ML != NULL){
        if(ML -> randata != 0) {
            mlptr T;
            find_node(ML, ML->randata, T);
            ML -> rptr = T;
            ML -> index = i;
            i++;
        }
        create_connection(ML -> next, i);
    }
}

void print_pattern(mlptr ML, int arr[], int lastIndex){
    if(ML == NULL){
        if(lastIndex != 9) {
            for(int i=0; i<lastIndex; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    arr[lastIndex] = ML->data;
    if((ML -> index) == 3){
        print_pattern(ML->next, arr, lastIndex+1);  
        if(ML -> randata != 0){
            print_pattern(ML->rptr, arr, lastIndex+1);
        } 
    } else {
        if(ML -> randata != 0){
            print_pattern(ML->rptr, arr, lastIndex+1);
        } 
        print_pattern(ML->next, arr, lastIndex+1);  
    
    }
}

void print_first (mlptr ML) {
    if(ML != NULL){
        cout<<ML -> data<<" ";
        if(ML -> next == NULL){
            cout<<endl;
        }
        print_first(ML -> next);
    }
}

int main(){
    mlptr ML = NULL;
    create_mll(ML);
    int arr[100];
    create_connection(ML, 1);
    print_first(ML);
    print_pattern(ML, arr, 0);
    return 0;
}

// 5 2 0 2 1 8 1 8 6 8 6 0 6 3 0 3 9 4 9 4 0 4 7 0 7 0 0


