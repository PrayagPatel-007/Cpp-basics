#include<bits/stdc++.h>
using namespace std;

struct btnode {
  struct btnode *lchild;
  int data;
  struct btnode *rchild;
};

typedef struct btnode *btptr;

btptr new_node(int x){
  btptr T=new(btnode);
  T->data=x;
  T->lchild=T->rchild=NULL;
}

void preorder(btptr T) {
  if(T != NULL){
    cout<<T->data<<" ";
    preorder(T->lchild);
    preorder(T->rchild);
  }
}

void level_order(btptr T){
  queue<btptr> Q;
  Q.push(T);
  while(!Q.empty()){
    btptr B = Q.front();
    Q.pop();
    cout<<B->data<<" ";
    if(B->lchild) Q.push(B->lchild);
    if(B->rchild) Q.push(B->rchild);
  }
}

void reverse_level_order(btptr T){
  queue<btptr> Q;
  Q.push(T);
  while(!Q.empty()){
    btptr B = Q.front();
    Q.pop();
    cout<<B->data<<" ";
    if(B->rchild) Q.push(B->rchild);
    if(B->lchild) Q.push(B->lchild);
  }
}

void DRL(btptr T){
  if(T != NULL){
    cout<<T->data<<" ";
    DRL(T->rchild);
    DRL(T->lchild);
  }
}

void spiral(btptr T, bool clock){
  queue<btptr> Q1;
  queue<btptr> Q2;
  Q1.push(T);
  Q2.push(T);
  btptr k = new(btnode);
  k->data = -1;
  k->lchild = k->rchild = NULL;
  Q1.push(k);
  Q2.push(k);
  bool flag=clock;
  btptr B1, B2;
  while(true){
    B1 = Q1.front();
    B2 = Q2.front();
    Q1.pop();
    Q2.pop();
    if(Q1.empty()) break;
    if(B1->data == -1){
      if(flag == false) flag=true;
      else flag=false;
      Q1.push(B1);
      Q2.push(B2);
    } else {
      if(flag) cout<<B1->data<<" ";
      else cout<<B2->data<<" ";
    }
    if(B1->lchild) Q1.push(B1->lchild);
    if(B1->rchild) Q1.push(B1->rchild);
    if(B2->rchild) Q2.push(B2->rchild);
    if(B2->lchild) Q2.push(B2->lchild);
  }
}

void create_bt(btptr &T1, btptr &T2, bool flag=true){
  int n;
  cin>>n;
  if(n != -1){
    T1=new_node(n);
    cin>>n;
    if(n != -1){
      T2=new_node(n);
    } else return;
    if(flag)
    create_bt(T1->rchild, T2->lchild, !flag);
    else
    create_bt(T1->lchild, T2->rchild, !flag);
  }
}

int main(){
  btptr T=NULL;
  int n;
  cin>>n;
  T=new_node(n);
  create_bt(T->lchild, T->rchild);
  preorder(T);
  cout<<endl;
  level_order(T);
  cout<<endl;
  spiral(T, false);
  cout<<endl;
  DRL(T);
  cout<<endl;
  reverse_level_order(T);
  cout<<endl;
  spiral(T, true);
  cout<<endl;
  return 0;
}