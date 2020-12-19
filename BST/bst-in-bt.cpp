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

void is_bst(btptr T, btptr &min, btptr &max, bool &isbst){
  btptr min1, max1;
  if(T->lchild == NULL && T->rchild == NULL){
    min = T;
    max = T;
    return;
  } else if(T -> lchild == NULL){
    max = T;
    min1= T;
    is_bst(T->rchild, min, max1, isbst);
  } else if(T -> rchild == NULL){
    min = T;
    max1 = T;
    is_bst(T->lchild, min1, max, isbst);
  } else {
    is_bst(T->lchild, min1, max, isbst);
    is_bst(T->rchild, min, max1, isbst);
  }
  if(max->data > T->data || min->data < T->data){
    isbst = false;
  }
  min = min1;
  max = max1;
}

void count_nodes(btptr T, int &count){
  if(T != NULL){
    count++;
    count_nodes(T->lchild, count);
    count_nodes(T->rchild, count);
  }
}

void largest_bst(btptr T, btptr &L, int &max2){
  if(T != NULL){
    bool isbst=true;
    int max1 = 0;
    btptr min, max;
    is_bst(T, min, max, isbst);
    count_nodes(T, max1);
    if(isbst && max1>max2){
      L = T;
      max2 = max1;
    } 
    largest_bst(T->lchild, L, max2);
    largest_bst(T->rchild, L, max2);
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
  btptr T = NULL;
  int n;
  cin>>n;
  insert(T, n);
  btptr L;
  int count=0;
  // count_nodes(T, count);
  // cout<<count;
  largest_bst(T, L, count);
  print_inorder(L);
  return 0;
}

// 27 18 15 9 0 0 0 22 12 8 0 0 0 45 32 0 0 72 0 0 36 25 0 0 63 54 0 0 0