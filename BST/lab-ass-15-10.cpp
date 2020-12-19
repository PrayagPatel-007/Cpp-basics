#include<bits/stdc++.h>
using namespace std;

struct btnode {
  struct btnode *lchild;
  char data;
  struct btnode *rchild;
};

typedef struct btnode *btptr;

void insert(btptr &T, string s){
  queue<btptr> Q;
  int i=0;
  char ch = s[i];
  i++;
  T = new(btnode);
  T -> data = ch;
  T -> lchild = NULL;
  T -> rchild = NULL;
  Q.push(T);
  char ch1, ch2;
  btptr B;
  while(true){
    ch1 = s[i];
    i++;
    if(ch1 == '$'){
      return;
    }
    B = Q.front();
    Q.pop();
    if(ch1 != '#'){
      B -> lchild = new(btnode);
      B -> lchild -> data = ch1;
      B -> lchild -> lchild = NULL;
      B -> lchild -> rchild = NULL;
    } else {
      B -> lchild = NULL;
    }
    ch2 = s[i];
    i++;
    if(ch2 == '$'){
      return;
    }
    if(ch2 != '#'){
      B -> rchild = new(btnode);
      B -> rchild -> data = ch2;
      B -> rchild -> lchild = NULL;
      B -> rchild -> rchild = NULL;
    } else {
      B -> rchild = NULL;
    }
    if (B -> lchild != NULL)
    Q.push(B -> lchild);
    if (B -> rchild != NULL)
    Q.push(B -> rchild);
  }
}

void print_levels (btptr T){
  queue<btptr> Q;
  Q.push(T);
  btptr E, B = T;
  E=new(btnode);
  E->data='#';
  E->lchild=NULL;
  E->rchild=NULL;
  Q.push(E);
  while(true){
    B = Q.front();
    Q.pop();
    if(Q.empty()){
      break;
    }
    if(B->data == '#'){
      cout<<endl;
      Q.push(B);
    }else {
      cout<<B->data<<" ";
    }
    if (B -> lchild != NULL)
      Q.push(B->lchild);
    if (B -> rchild != NULL)
      Q.push(B->rchild);
  }
}

int main(){
  btptr T = NULL;
  string s;
  cin>>s;
  insert(T, s);
  print_levels(T);
  return 0;
}
