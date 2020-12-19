#include<bits/stdc++.h>
using namespace std;

struct btnode {
  struct btnode *lchild;
  int data;
  struct btnode *rchild;
};

typedef struct btnode *btptr;

void create_bst_lvl(int s[], btptr &T, int n){
  queue<btptr*> Q;
  queue<pair<int, int>> Q1;
  int i = 0, min, max;
  Q.push(&T);
  Q1.push({INT_MIN, INT_MAX});
  btptr* B;
  while(i < n){
    B = Q.front();
    Q.pop();
    min = Q1.front().first;
    max = Q1.front().second;
    Q1.pop();
    if (min <= s[i] && max >= s[i]) {
      *B = new(btnode);
      (*B)->lchild = NULL;
      (*B)->rchild = NULL;
      (*B)->data = s[i];
      i++;
      Q.push(&((*B)->lchild));
      Q1.push({min, (*B)->data - 1});
      Q.push(&((*B)->rchild));
      Q1.push({(*B)->data + 1, max});
    }
  }
}

void preorder(btptr T){
  if(T != NULL){
    cout<<T->data<<" ";
    preorder(T->lchild);
    preorder(T->rchild);
  }
}

int main(){
  btptr T = NULL;
  int arr[100];
  int n, i=0;
  cin>>n;
  while(n  != -1){
    arr[i] = n;
    i++;
    cin>>n;
  }
  create_bst_lvl(arr, T, i);
  preorder(T);
  return 0;
}