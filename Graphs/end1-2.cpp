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

void right_rotate(bstptr &T){
  if(T){
    bstptr p = T->lchild;
    T->lchild = T->lchild->rchild;
    p->rchild = T;
    T = p;
    return;
  }
}

void left_rotate(bstptr &T){
  if(T){
    bstptr p = T->rchild;
    T->rchild = T->rchild->lchild;
    p->lchild = T;
    T = p;
    return;
  }
}

void find_key(bstptr &T, int key){
  if(T->data == key){
    return;
  } else {
    if(key > T->data){
      find_key(T->rchild, key);
      left_rotate(T);
    } else {
      find_key(T->lchild, key);
      right_rotate(T);
    }
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
  int k;
  cin>>k;
  find_key(T, k);
  inorder(T);
  return 0;
}

// 50 40 45 30 55 60 65 -1 55