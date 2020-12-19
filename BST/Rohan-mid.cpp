#include<bits/stdc++.h>
using namespace std;

struct btnode {
  struct btnode *lchild = NULL;
  int data=0;
  struct btnode *rchild = NULL;
};

typedef struct btnode * btptr;

void create_bt (btptr &T, int h, int num[1000]){
  queue<btptr> Q;
  Q.push(T);
  int i=1;
  while(i<pow(2, h+1)-1){
    btptr B = Q.front();
    Q.pop();
    B->lchild = new(btnode);
    B->rchild = new(btnode);
    i+=2;
    Q.push(B->lchild);
    Q.push(B->rchild);
  }
  int j=0;
  while(!Q.empty()){
    btptr B = Q.front();
    Q.pop();
    B->data = num[j++];
  }
}

void insert_values(btptr T, int h, bool flag){
  if(T->lchild == NULL && T->rchild == NULL){
    return;
  } else {
    insert_values(T->lchild, h+1, flag);
    insert_values(T->rchild, h+1, flag);
    if(flag){
      if(h%2 != 0){
        T->data = max(T->lchild->data, T->rchild->data);
      } else {
        T->data = min(T->lchild->data, T->rchild->data);
      }
    } else {
      if(h%2 == 0){
        T->data = max(T->lchild->data, T->rchild->data);
      } else {
        T->data = min(T->lchild->data, T->rchild->data);
      }
    }
  }
}

void print_reverse(btptr T){
  if(T){
    print_reverse(T->rchild);
    cout<<T->data<<" ";
    print_reverse(T->lchild);
  }
}

void print_path(btptr T, bool flag, int h=0){
  if(T){
    cout<<T->data<<" ";
    if(flag){
      if(h%2 == 0){
        btptr k = (T->lchild->data > T->rchild->data) ? T->lchild : T->rchild;
        print_path(k, flag, h+1);
      } else {
        btptr k = (T->lchild->data > T->rchild->data) ? T->rchild : T->lchild;
        print_path(k, flag, h+1);
      }
    } else {
      if(h%2 == 0){
        btptr k = (T->lchild->data > T->rchild->data) ? T->lchild : T->rchild;
        print_path(k, flag, h+1);
      } else {
        btptr k = (T->lchild->data > T->rchild->data) ? T->rchild : T->lchild;
        print_path(k, flag, h+1);
      }
    }
  }
}

int main(){
  btptr T = new(btnode);
  int h, num[1000];
  cin>>h;
  bool flag = true;
  if(h%2 == 0){
    flag = false;
  }
  for(int i=0; i<pow(2, h); i++){
    cin>>num[i];
  }
  create_bt(T, h, num);
  insert_values(T, 0, flag);
  print_reverse(T);
  cout<<endl;
  print_path(T, flag);
  return 0;
}

// 4
// 84 -29 -37 -25 1 -43 -75 49 -21 -51 58 -46 -3 -13 26 79