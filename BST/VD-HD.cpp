#include<bits/stdc++.h>
using namespace std;

struct btnode{
  struct btnode *lchild;
  int data;
  struct btnode *rchild;
};

typedef struct btnode *btptr;

btptr get_node(int x){
  btptr T = new(btnode);
  T->lchild = T->rchild = NULL;
  T->data = x;
  return T;
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

int left_bt(btptr T){
  if(T) return 1+left_bt(T->lchild);
  else return 0;
}

int right_bt(btptr T){
  if(T) return 1+right_bt(T->rchild);
  else return 0;
}

void vertical_sums(btptr T, int arr[], int l, int i=0){
  if(T){
    arr[l+i] += T->data;
    vertical_sums(T->lchild, arr, l, i-1);
    vertical_sums(T->rchild, arr, l, i+1);
  }
}

int horizontal_sum(btptr T, int arr[]){
  queue<btptr> Q;
  Q.push(T);
  btptr E, B = T;
  E=new(btnode);
  E->data=-1;
  E->lchild=NULL;
  E->rchild=NULL;
  Q.push(E);
  int sum=0, i=0;
  while(true){
    B = Q.front();
    Q.pop();
    if(Q.empty()){
      arr[i] = sum;
      i++;
      return i;
    }
    if(B->data == -1){
      arr[i] = sum;
      sum=0;
      i++;
      Q.push(B);
    }else {
      sum += B->data;
    }
    if (B -> lchild != NULL)
      Q.push(B->lchild);
    if (B -> rchild != NULL)
      Q.push(B->rchild);
  }
}

void print_arr(int arr[], int n){
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }cout<<endl;
}

int main() {
  btptr T = NULL;
  int n;
  cin>>n;
  insert(T, n);
  int l = left_bt(T) -1;
  int r = right_bt(T) -1;
  int v[l+r+1] = {0};
  vertical_sums(T, v, l);
  print_arr(v, l+r+1);
  int h[10];
  n = horizontal_sum(T, h);
  print_arr(h, n);
  return 0;
}

// 5 3 2 1 0 0 0 4 0 0 7 6 0 0 9 8 0 0 0