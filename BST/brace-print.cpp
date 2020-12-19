#include<bits/stdc++.h>
using namespace std;

struct btnode {
  struct btnode *lchild;
  char data;
  struct btnode *rchild;
};

typedef struct btnode *btptr;

void insert(btptr &T, string k, int &i){
  if(T == NULL){
    T = new(btnode);
    T->data = k[i];
    i++;
    T->lchild = NULL;
    T->rchild = NULL;
  }
  if(k[i] != '#'){
    insert(T->lchild, k, i);
  } else i++;
  if(k[i] != '#'){
    insert(T->rchild, k, i);
  } else i++;
}

void print_braces(btptr T){
  if(T != NULL){
    cout<<T->data;
    if(T->lchild == NULL && T->rchild == NULL) return;
    cout<<"(";
    print_braces(T->lchild);
    print_braces(T->rchild);
    cout<<")";
  }
}

int main(){
  btptr T = NULL;
  string s;
  cin>>s;
  int i=0;
  insert(T, s, i);
  print_braces(T);
  return 0;
}