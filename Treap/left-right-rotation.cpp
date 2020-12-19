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

void create_bst(bstptr &T, bool &flag){
  int k;
  cin>>k;
  if(k == -2) flag = false;
  else if (k != -1){
    insert_bnode(T, k);
    create_bst(T, flag);
  }
}

void right_rotate(bstptr &T, int n){
  if(T){
    if(T->data == n){
      bstptr p = T->lchild;
      T->lchild = T->lchild->rchild;
      p->rchild = T;
      T = p;
      return;
    }
    right_rotate(T->lchild, n);
    right_rotate(T->rchild, n);
  }
}

void left_rotate(bstptr &T, int n){
  if(T){
    if(T->data == n){
      bstptr p = T->rchild;
      T->rchild = T->rchild->lchild;
      p->lchild = T;
      T = p;
      return;
    }
    left_rotate(T->lchild, n);
    left_rotate(T->rchild, n);
  }
}

void print_preorder(bstptr T){
  if(T){
    cout<<T->data<<" ";
    print_preorder(T->lchild);
    print_preorder(T->rchild);
  }
}

int main(){
  bstptr T = NULL;
  int n, k;
  bool flag=true;
  while(true){
    create_bst(T, flag);
    if(!flag) break;
    cin>>n;
    cin>>k;
    if(k == 0)
    right_rotate(T, n);
  }
  print_preorder(T);
  return 0;
}

// 1 2 3 -1 1 0 4 5 -1 3 0 6 -1 2 0 7 -1 5 0 -2
// 