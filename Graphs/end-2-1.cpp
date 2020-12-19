#include<bits/stdc++.h>
using namespace std;

struct btnode {
  struct btnode *lchild;
  int data;
  struct btnode *rchild;
};

typedef struct btnode *btptr;

struct lnode {
  struct node *ptr;
  struct lnode *next;
};

struct node {
  int data;
  struct node *next;
};

typedef struct node *lptr;

void insert_node(lptr &T, int k){
  if(T == NULL){
    T = new(node);
    T->next = NULL;
    T->data = k;
  } else {
    insert_node(T->next, k);
  }
}

void insert_lnode(lnode* &T, lptr k){
  if(T == NULL){
    T = new(lnode);
    T->next = NULL;
    T->ptr = k;
  } else {
    insert_lnode(T->next, k);
  }
}

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

void level_print(btptr T, int i, bool reverse, lptr &L){
  if (T != NULL){
    if(i == -1){
      return;
    }
    if (i == 0){
      insert_node(L, T->data);
    }
    if (!reverse){
      level_print(T->lchild, i-1, reverse, L);
      level_print(T->rchild, i-1, reverse, L);
    } else {
      level_print(T->rchild, i-1, reverse, L);
      level_print(T->lchild, i-1, reverse, L);
    }
  }
}

void depth(btptr T, int count, int &max) {
  if(T != NULL){
    count++;
    if(max < count){
      max = count;
    }
    depth(T->lchild, count, max);
    depth(T->rchild, count, max);
  }
}

void bottom_up_spiral(btptr &T, lnode* &LT){
  int n = -99999;
  depth(T, 0, n);
  bool flag = true;
  for(int i=n-1; i>=0; i--){
    lptr L = NULL;
    level_print(T, i, flag, L);
    insert_lnode(LT, L);
    flag = !flag;
  }
}

void print(lnode * &LT){
  if(LT){
    lptr p = LT->ptr;
    cout<<"[";
    while(p){
      cout<<p->data;
      if(p->next) cout<<",";
      p = p->next;
    }
    cout<<"]";
    if(LT->next) cout<<",";
    print(LT->next);
  }
}

int main(){
  btptr T = NULL;
  int n;
  cin>>n;
  insert(T, n);
  lnode *LT = NULL;
  bottom_up_spiral(T, LT);
  cout<<"[";
  print(LT);
  cout<<"]";
  return 0;
}

// 2 7 2 0 0 6 5 0 0 11 0 0 5 0 9 4 0 0 0