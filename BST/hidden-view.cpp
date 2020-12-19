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
    string s;
    cin>>s;
    int i=0;
    insert(T, s, i);
    print_hidden(T, 't');
    return 0;
}

// MJPB###TE###LKS###QF#G###