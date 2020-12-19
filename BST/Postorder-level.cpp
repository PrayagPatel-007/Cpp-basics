#include<bits/stdc++.h>
using namespace std;

struct bstnode {
  struct bstnode *lchild;
  int data;
  struct bstnode *rchild;
};

typedef struct bstnode *bstptr;

int find(int arr[], int n, int l, int h){
  for(int i=l; i<=h; i++){
    if(arr[i]>=n){
      return i;
    }
  }
}

void make_bst (bstptr &T, int arr[], int l, int h){
  if(l > h){
    return;
  }
  T = new(bstnode);
  T -> data = arr[h];
  T -> lchild = NULL;
  T -> rchild = NULL;
  int i = find(arr, arr[h], l,h);
  make_bst(T->rchild, arr, i, h-1);
  make_bst(T->lchild, arr, l, i-1);
}

void print_levels (bstptr T){
  queue<bstptr> Q;
  Q.push(T);
  bstptr E, B = T;
  E=new(bstnode);
  E->data=-1;
  E->lchild=NULL;
  E->rchild=NULL;
  Q.push(E);
  while(true){
    B = Q.front();
    Q.pop();
    if(Q.empty()){
      break;
    }
    if(B->data == -1){
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
  int arr[20];
  bstptr T = NULL;
  int i=0, n;
  cin>>n;
  while(n != -1){
    arr[i] = n;
    i++;
    cin>>n;
  }
  make_bst(T, arr, 0, i-1);
  print_levels(T);
  return 0;
}
