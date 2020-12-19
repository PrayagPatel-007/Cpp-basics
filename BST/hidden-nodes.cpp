#include<bits/stdc++.h>
using namespace std;

struct btnode {
  struct btnode *lchild;
  int data;
  struct btnode *rchild;
};

typedef struct btnode *btptr;

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

void print_hidden(btptr T, char c){
  if(T != NULL){
    if(c == 'l'){
      c = (T->lchild) ? 'm' : c;
      print_hidden(T->lchild, 'l');
      print_hidden(T->rchild, c);
    } else if(c == 'r'){
      c = (T->rchild) ? 'm' : c;
      print_hidden(T->lchild, c);
      print_hidden(T->rchild, 'r');
    } else if(c == 'm'){
      if (T->lchild != NULL || T->rchild != NULL){
        cout<<T->data<<" ";
      }
      print_hidden(T->lchild, c);
      print_hidden(T->rchild, c);
    } else {
      print_hidden(T->lchild, 'l');
      print_hidden(T->rchild, 'r');
    }
  }
}

int main(){
  btptr T = NULL;
  int n;
  cin>>n;
  insert(T, n);
  print_hidden(T, 't');
  return 0;
}