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

void level_order(bstptr T){
  queue<bstptr> Q;
  bstptr B = T;
  Q.push(B);
  while(!Q.empty()){
    B = Q.front();
    cout<<B->data<<" ";
    Q.pop();
    if (B -> lchild != NULL)
      Q.push(B->lchild);
    if (B -> rchild != NULL)
      Q.push(B->rchild);
  }
}

void level_print(bstptr T, int i, bool reverse){
  if (T != NULL){
    if(i == -1){
      return;
    }
    if (i == 0){
      cout<<T->data<<" ";
    }
    if (!reverse){
      level_print(T->lchild, i-1, reverse);
      level_print(T->rchild, i-1, reverse);
    } else {
      level_print(T->rchild, i-1, reverse);
      level_print(T->lchild, i-1, reverse);
    }
  }
}

void depth(bstptr T, int count, int &max) {
  if(T != NULL){
    count++;
    if(max < count){
      max = count;
    }
    depth(T->lchild, count, max);
    depth(T->rchild, count, max);
  }
}

void reverse_reversed(bstptr T){
  int n = -99999;
  depth(T, 0, n);
  for(int i=n-1; i>=0; i--){
    level_print(T, i, true);
  }
}

void reverse_level(bstptr T){
  int n = -99999;
  depth(T, 0, n);
  for(int i=n-1; i>=0; i--){
    level_print(T, i, false);
  }
}

void alternate_even(bstptr T){
  int n=-99999, i=0;
  depth(T, 0, n);
  while(i<n){
    if(i%2 != 0){
      level_print(T, i, false);
    } else {
      level_print(T, i, true);
    }
    i++;
  }
}

void alternate_odd(bstptr T){
  int n=-99999, i=0;
  depth(T, 0, n);
  while(i<n){
    if(i%2 != 0){
      level_print(T, i, true);
    } else {
      level_print(T, i, false);
    }
    i++;
  }
}

int main(){
  bstptr T = NULL;
  create_bst(T);
  level_order(T);
  cout<<endl;
  reverse_reversed(T);
  cout<<endl;
  reverse_level(T);
  cout<<endl;
  alternate_odd(T);
  cout<<endl;
  alternate_even(T);
  cout<<endl;
  alternate_odd(T);
  cout<<endl;
  alternate_even(T);
  cout<<endl;
  return 0;
}


