#include<bits/stdc++.h>
using namespace std;

struct bstnode {
  struct bstnode *lchild;
  int data;
  struct bstnode *rchild;
};

typedef struct bstnode *bstptr;

void insert_bnode(bstptr &T, int k){
  if (T == NULL){
    T = new(bstnode);
    T -> data = k;
    T -> lchild = NULL;
    T -> rchild = NULL;
  } else {
    if (k < T -> data){
      insert_bnode(T -> lchild, k);
    } else {
      insert_bnode(T -> rchild, k);
    }
  }
}

void create_bst(bstptr &T){
  int k;
  cin>>k;
  if (k != -1){
    insert_bnode(T, k);
    create_bst(T);
  }
}