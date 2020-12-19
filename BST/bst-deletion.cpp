#include<bits/stdc++.h>
using namespace std;

struct bstnode {
  struct bstnode *lchild;
  int data;
  struct bstnode *rchild;
};

typedef struct bstnode *bstptr;

bstptr get_bstnode(int x){
  bstptr T = new(bstnode);
  T->lchild = T->rchild = NULL;
  T->data = x;
  return T;
}

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

void max_node(bstptr &T, bstptr &max){
  if(T != NULL){
    if(T->data > max->data) max = T;
    max_node(T->lchild, max);
    max_node(T->rchild, max);
  }
}

void min_node(bstptr &T, bstptr &min){
  if(T){
    if(T->data < min->data) min = T;
    min_node(T->lchild, min);
    min_node(T->rchild, min);
  }
}

void delete_bstnode(bstptr &T, int n){
  if(T){
    if(T->data == n && !T->lchild && !T->rchild){
      return;
    }
    if(T->data == n && T->lchild) {
      bstptr max = get_bstnode(INT_MIN);
      max_node(T->lchild, max);
      swap(max->data, T->data);
      delete_bstnode(max, n);
    } else if(T->data == n && T->rchild){
      bstptr min = get_bstnode(INT_MAX);
      min_node(T->rchild, min);
      swap(min->data, T->data);
      delete_bstnode(min, n);
    }
    delete_bstnode(T->lchild, n);
    delete_bstnode(T->rchild, n);
  }
}

void delete_node(bstptr &T, int n){
  if(T){
    if(T->lchild && T->lchild->data == n) T->lchild = NULL;
    if(T->rchild && T->rchild->data == n) T->rchild = NULL;
    delete_node(T->lchild, n);
    delete_node(T->rchild, n);
  }
}

void inorder(bstptr T){
  if(T){
    inorder(T->lchild);
    cout<<T->data<<" ";
    inorder(T->rchild);
  }
}

int main(){
  bstptr T = NULL;
  create_bst(T);
  delete_bstnode(T, 6);
  delete_node(T, 6);
  inorder(T);
  return 0;
}

// 5 3 8 1 2 4 6 7 9 -1