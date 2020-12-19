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

void convert_dll(bstptr T, bstptr &H, bstptr &previous){
  if(T == NULL) return;
  convert_dll(T->lchild, H, previous);
  if(previous == NULL){
    H = T;
  } else {
    T->lchild = previous;
    previous->rchild = T;
  }
  previous = T;
  convert_dll(T->rchild, H, previous);
}

bool is_next(bstptr T1, bstptr T2){
  T1 = T1->rchild;
  while(T1 != NULL){
    if(T1 == T2) return true;
    T1 = T1->rchild;
  }
  return false;
}

bstptr last_node(bstptr T){
  while(T->rchild != NULL){
    T=T->rchild;
  }
  return T;
}

void find_sum(bstptr T, bstptr L, int sum){
  if(T != NULL){
    int s = sum - T->data;
    bstptr l = T->rchild;
    bstptr h = L;
    while(is_next(l, h)){
      if(l->data + h->data < s) l = l->rchild;
      else if(l->data + h->data > s) h=h->lchild;
      else {
        cout<<T->data<<" "<<l->data<<" "<<h->data<<endl;
        l=l->rchild;
        h=h->lchild;
      }
    }
    find_sum(T->rchild, L, sum);
  }
}

int main(){
  bstptr T=NULL, P=NULL, H;
  create_bst(T);
  convert_dll(T, H, P);
  int sum;
  cin>>sum;
  find_sum(H, last_node(H), sum);
  return 0;
}
