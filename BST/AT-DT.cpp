#include<bits/stdc++.h>
using namespace std;

struct btnode {
  struct btnode *lchild;
  int data;
  int at;
  int dt;
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

void atdt(btptr T, int &num){
  if(T != NULL){
    num++;
    T->at = num;
    atdt(T->lchild, num);
    atdt(T->rchild, num);
    num++;
    T->dt = num;
  }
}

void print(btptr T){
  if(T){
    cout<<T->data<<": "<<T->at<<", "<<T->dt<<"\n";
    print(T->lchild);
    print(T->rchild);
  }
}

int main() {
  int n;
  btptr T = NULL;
  int num=-1;
  cin>>n;
  insert(T, n);
  atdt(T, num);
  print(T);
  return 0;
}

// 5 3 2 1 0 0 0 4 0 0 7 6 0 0 9 8 0 0 0