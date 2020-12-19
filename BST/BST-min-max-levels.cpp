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

void print_levels (btptr T, int &min, int &max, int a[], int d[], int u[], int &an, int &dn, int &un){
  queue<btptr> Q;
  Q.push(T);
  int i=0;
  int min1=9999, max1 = -9999;
  bool ascending = true, descending = true;
  int ai=0, di=0, ui=0;
  btptr E, B = T;
  E=new(btnode);
  E->data=-1;
  E->lchild=NULL;
  E->rchild=NULL;
  Q.push(E);
  while(true){
    B = Q.front();
    Q.pop();
    if(B->data == -1){
      if(i != 0){
        if(ascending){
          a[ai] = i;
          ai++;
        } else if(descending){
          d[di]= i;
          di++;
        } else {
          u[ui]=i;
          ui++;
        }
      }
      i++;
      if(min1 < min) min = min1;
      if(max1 > max) max = max1;
      min1= 9999;
      max1 = -9999;
      ascending=true;
      descending=true;
      if(Q.empty()){
        an=ai;
        dn=di;
        un=ui;
        break;
      }
      Q.push(B);
    }else {
      if(min1>B->data) min1 = B->data;
      else descending=false;
      if(max1<B->data) max1 = B->data;
      else ascending=false;
    }
    if (B -> lchild != NULL)
      Q.push(B->lchild);
    if (B -> rchild != NULL)
      Q.push(B->rchild);
  }
}

void print_array(int arr[], int n){
  for(int i=0;i <n; i++){
    cout<<arr[i]<<" ";
  }
}

int main(){
  btptr T = NULL;
  int n;
  cin>>n;
  insert(T, n);
  int min=9999, max = -9999;
  int a[10], d[10], u[10];
  int an, dn, un;
  print_levels(T, min, max, a, d, u, an, dn, un);
  cout<<max<<" "<<min<<" ";
  print_array(a, an);
  print_array(d, dn);
  print_array(u, un);
  return 0;
}
