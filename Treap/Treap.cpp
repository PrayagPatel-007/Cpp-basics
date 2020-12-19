#include<bits/stdc++.h>
using namespace std;

struct trpnode{
  struct trpnode *lchild;
  char key;
  int pri;
  struct trpnode *rchild;
};

typedef struct trpnode *trpptr;

void right_rotate(trpptr &T){
  if(T){
    trpptr p = T->lchild;
    T->lchild = T->lchild->rchild;
    p->rchild = T;
    T = p;
    return;
  }
}

void left_rotate(trpptr &T){
  if(T){
    trpptr p = T->rchild;
    T->rchild = T->rchild->lchild;
    p->lchild = T;
    T = p;
    return;
  }
}

void insert(trpptr &T, char k, int p){
  if (T == NULL){
    T = new(trpnode);
    T -> key = k;
    T -> pri = p;
    T -> lchild = NULL;
    T -> rchild = NULL;
  } else {
    if (k < T -> key){
      insert(T -> lchild, k, p);
      if(T->lchild->pri < T->pri) {
        right_rotate(T);
      }
    } else {
      insert(T -> rchild, k, p);
      if(T->rchild->pri < T->pri) {
        left_rotate(T);
      }
    }
  }
}

void inorder(trpptr T){
  if(T){
    inorder(T->lchild);
    cout<<T->key<<" ";
    cout<<T->pri<<" ";
    inorder(T->rchild);
  }
}

void delete_node(trpptr &T, char c){
  if(T){
    if(c < T->key) delete_node(T->lchild, c);
    else if(c > T->key) delete_node(T->rchild, c);
    if(T->key == c && !T->lchild && !T->rchild) {
      T = NULL;
      return;
    } else if(T->key == c) {
      if(!T->lchild) {
        T = T->rchild;
      } else if(!T->rchild) {
        T = T->lchild;
      } else {
        if(T->lchild->pri < T->rchild->pri) {
          right_rotate(T);
          delete_node(T->rchild, c);
        } else {
          left_rotate(T);
          delete_node(T->lchild, c);
        }
      }
    }
  }
}

int main(){
  trpptr T = NULL;
  char c;
  int n;
  cin>>c;
  while(c != '#'){
    cin>>n;
    insert(T, c, n);
    cin>>c;
  }
  inorder(T);
  char c1;
  cin>>c>>c1;
  delete_node(T, c);
  delete_node(T, c1);
  inorder(T);
  return 0;
}


// p 45 s 63 h 21 m 36 e 27 g 9 #