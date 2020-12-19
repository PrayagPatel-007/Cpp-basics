#include<bits/stdc++.h>
using namespace std;

struct AVLnode {
  struct AVLnode *lchild;
  int data;
  struct AVLnode *rchild;
  int height;
};

typedef struct AVLnode *avlptr;

int height(avlptr T){
  if(T == NULL){
    return -1;
  } else return T->height;
}

void right_rotate(avlptr &T){
  if(T){
    avlptr p = T->lchild;
    T->lchild = T->lchild->rchild;
    p->rchild = T;
    T->height = max(height(T->rchild), height(T->lchild)) + 1;
    p->height = max(height(T), height(p->lchild)) + 1;
    T = p;
    return;
  }
}

void left_rotate(avlptr &T){
  if(T){
    avlptr p = T->rchild;
    T->rchild = T->rchild->lchild;
    p->lchild = T;
    T->height = max(height(T->lchild), height(T->rchild)) + 1;
    p->height = max(height(T), height(p->rchild)) + 1;
    T = p;
    return;
  }
}

void insert_avl(avlptr &T, int k){
  if(T == NULL){
    T = new(AVLnode);
    T->data = k;
    T->rchild = T->lchild = NULL;
    T->height=0;
  } else {
    if (k > T->data) {
      insert_avl(T->rchild, k);
    } else {
      insert_avl(T->lchild, k);
    }
    // T->height = max(height(T->lchild), height(T->rchild)) + 1;
    // if (height(T->lchild) - height(T->rchild) > 1) {
    //   if (k > T->lchild->data && k < T->data) {
    //     left_rotate(T->lchild);
    //     right_rotate(T);
    //   } else {
    //     right_rotate(T);
    //   }
    // } else if(height(T->rchild) - height(T->lchild) > 1) {
    //   if(k > T->data && k < T->rchild->data) {
    //     right_rotate(T->rchild);
    //     left_rotate(T);
    //   } else {
    //     left_rotate(T);
    //   }
    // }
  }
}

void search(avlptr &T, int k){
  if(T){
    if(T->data == k) {
      return;
    } else if(T->data > k) {
      search(T->lchild, k);
      right_rotate(T);
    } else {
      search(T->rchild, k);
      left_rotate(T);
    }
  }
}

void preorder(avlptr T){
  if(T){
    cout<<T->data<<" ";
    preorder(T->lchild);
    preorder(T->rchild);
  }
}

int main() {
  avlptr T = NULL;
  insert_avl(T, 100);
  insert_avl(T, 50);
  insert_avl(T, 40);
  insert_avl(T, 30);
  insert_avl(T, 20);
  insert_avl(T, 200);
  preorder(T);
  search(T, 20);
  preorder(T);
  return 0;
}