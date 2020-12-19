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

void find_node(btptr T, btptr &min, btptr &max){
  btptr min1, max1;
  if(T->lchild == NULL && T->rchild == NULL){
    min = T;
    max = T;
    return;
  } else if(T -> lchild == NULL){
    max = T;
    min1= T;
    find_node(T->rchild, min, max1);
  } else if(T -> rchild == NULL){
    min = T;
    max1 = T;
    find_node(T->lchild, min1, max);
  } else {
    find_node(T->lchild, min1, max);
    find_node(T->rchild, min, max1);
  }
  if(max->data > T->data && min->data < T->data){
    swap(max->data, min->data);
  }
  min = min1;
  max = max1;
}

void swap_node(btptr T, btptr &last, bool first, btptr &b1, btptr &b2){
  if(T != NULL){
    swap_node(T->lchild, last, first, b1, b2);
    if(last ->data > T->data && first) {
      b1 = last;
      b2 = T;
      first = false;
    }
    else if (last->data > T->data && !first) {
      b2 = T;
      return;
    }
    last = T;
    swap_node(T->rchild, last, first, b1, b2);
  }
}

void print_inorder(btptr T){
  if(T != NULL){
    print_inorder(T->lchild);
    cout<<T->data<<" ";
    print_inorder(T->rchild);
  }
}

int main(){
  int n;
  btptr last = new(btnode);
  last -> data = -99;
  btptr T = NULL;
  cin>>n;
  insert(T, n);
  btptr min, max;
  // find_node(T, min, max);
  swap_node(T, last, true, min, max);
  swap(min->data, max->data);
  print_inorder(T);
  return 0;
}

// 7 3 1 0 2 0 0 4 0 0 8 6 0 5 0 0 9 0 0