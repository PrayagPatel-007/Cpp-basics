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

int middle_level(btptr sp, btptr fp, int i=0){
  if(fp == NULL || fp->lchild == NULL){
    return i;
  } else {
    return middle_level(sp->lchild, fp->lchild->lchild, i+1);
  }
}

void print_middle_level (btptr T, int i, int level){
  if(T){
    if(level == i){
      cout<<T->data<<" ";
    } else {
      print_middle_level(T->lchild, i+1, level);
      print_middle_level(T->rchild, i+1, level);
    }
  }
}

int main(){
  btptr T = NULL;
  int n;
  cin>>n;
  insert(T, n);
  int level = middle_level(T, T);
  print_middle_level(T, 0, level);
  return 0;
}

// 1 2 4 8 16 0 0 17 0 0 9 18 0 0 19 0 0 5 10 20 0 0 21 0 0 11 22 0 0 23 0 0 3 6 12 24 0 0 25 0 0 13 26 0 0 27 0 0 7 14 28 0 0 29 0 0 15 30 0 0 31 0 0