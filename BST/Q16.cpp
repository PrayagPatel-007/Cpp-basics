#include<bits/stdc++.h>
using namespace std;

struct hnode {
  struct hnode *lchild;
  char data;
  int freq;
  struct hnode *rchild; 
};

typedef struct hnode *hptr;

void insert_heap(hptr &H, int x){
  if(H == NULL){
    H = new(hnode);
    H->freq = x;
    H->lchild = H->rchild = NULL;
  } else {
    if(H->lchild == NULL) insert_heap(H->lchild, x);
    else if(H->rchild == NULL) insert_heap(H->rchild, x);
  }
}

int main(){
  hptr H = NULL, T = NULL;

  return 0;
}