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



int main(){
  btptr T = NULL;
  int n;
  cin>>n;
  insert(T, n);
  return 0;
}

// 4 5 7 11 0 0 12 0 0 8 13 0 0 14 0 0 6 9 15 0 0 16 0 0 10 17 0 0 18 0 0