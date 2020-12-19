#include<bits/stdc++.h>
using namespace std;

struct btnode {
  struct btnode *lchild;
  int data;
  struct btnode *rchild;
};

typedef struct btnode *btptr;

void insert(btptr &T, int n){
  int num;
  if(T == NULL){
    T = new(btnode);
    T -> data = n;
    T -> lchild = NULL;
    T -> rchild = NULL;
  } 
  cin>>num;
  if(num != 0){
    insert(T->lchild, num);
  }
  cin>>num;
  if(num != 0){
    insert(T->rchild, num);
  }
}

void print_left(btptr T){
  if(T != NULL){
    if(T -> lchild) {
      cout<<T -> data <<" ";
      print_left(T->lchild);
    } else if(T->rchild) {
      cout<<T -> data <<" ";
      print_left(T->rchild);
    }
  }
}

void print_right(btptr T){
  if(T != NULL){
    if (T->rchild){
      print_right(T -> rchild);
      cout<<T -> data <<" ";
    } else if(T -> lchild){
      print_right(T -> lchild);
      cout<<T -> data <<" ";
    }
  }
}

void print_leaves(btptr T){
  if (T != NULL){
    if(T -> lchild == NULL && T -> rchild == NULL){
      cout<<T->data<<" ";
      return;
    }
    print_leaves(T -> lchild);
    print_leaves(T -> rchild);
  }
}

void print_boundary(btptr T){
  print_left(T);
  print_leaves(T);
  print_right(T);
}

int main(){
  btptr T = NULL;
  int n;
  cin>>n;
  insert(T, n);
  print_boundary(T);
  return 0;
}