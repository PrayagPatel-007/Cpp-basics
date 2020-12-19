#include<bits/stdc++.h>
using namespace std;

struct btnode{
  struct btnode *lchild;
  int data;
  struct btnode *rchild;
};

typedef struct btnode *btptr;

btptr get_node(int x){
  btptr T = new(btnode);
  T->lchild = T->rchild = NULL;
  T->data = x;
  return T;
}

bool is_heap_arr(int H[], int n){
  for(int i=0; i<n; i++){
    if(2*i + 2 < n) {
      if(H[2*i+2] < H[i] || H[2*i+1] < H[i]){
        return false;
      }
    }
    if(2*i + 1 < n && H[2*i + 1] < H[i]){
        return false;
    }
  }
  return true;
}

bool is_fully_complete(btptr T){
  queue<btptr> Q;
  Q.push(T);
  bool run = true;
  while(!Q.empty()){
    T = Q.front();
    Q.pop();
    if(run && (T->lchild == NULL || T->rchild == NULL)) {
      run = false;
      if(T->rchild != NULL) {
        return false;
      }
    } else if (!run){
      if(T->lchild != NULL || T->rchild != NULL){
        return false;
      }
    }
    if(T->lchild)
    Q.push(T->lchild);
    if(T->rchild)
    Q.push(T->rchild);
  }
  return true;
}

void is_heap_bt(btptr T, bool &is_heap){
  if(T->lchild != NULL){
    if(T->rchild && (T->data > T->lchild->data || T->data > T->rchild->data)) is_heap = false;
    else if (!T->rchild && T->data > T->rchild->data) is_heap = false;
    is_heap_bt(T->lchild, is_heap);
    is_heap_bt(T->rchild, is_heap);   
  }
}

int main() {
  int H[20] = {2, 4, 6, 1, 15, 20};
  btptr T = get_node(2);
  T->lchild = get_node(4);
  T->rchild = get_node(6);
  T->rchild->lchild = get_node(10);
  T->rchild->rchild = get_node(20);
  T->lchild->rchild = get_node(15);
  bool is_heap = is_fully_complete(T);
  is_heap_bt(T, is_heap);
  cout<<is_heap;
  cout<<is_heap_arr(H, 6);
  return 0;
}