#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  struct node *next;
};

typedef struct node *lptr;

struct kdnode{
  struct kdnode *lchild;
  lptr data;
  struct kdnode *rchild;
};

typedef struct kdnode *kdptr;

int ll_index(lptr L, int index){
  if(index == 0){
    return L->data;
  }else {
    return ll_index(L->next, index-1);
  }
}

void insert_node(lptr &L, int x){
  if(L == NULL){
    L = new(node);
    L->data = x;
    L->next = NULL;
  } else {
    insert_node(L->next, x);
  }
}

void insert_kd(kdptr &T, lptr L, int n, int index){
  if(T == NULL){
    T = new(kdnode);
    T->lchild = NULL;
    T->rchild = NULL;
    T->data = L;
  } else {
    if(ll_index(T->data, index) > ll_index(L, index))
    insert_kd(T->lchild, L, n, (index+1)%n);
    else
    insert_kd(T->rchild, L, n, (index+1)%n);
  }
}

void print_ll(lptr L){
  if (L){
    cout<<L->data<<" ";
    print_ll(L->next);
  }
}

void print_kd(kdptr T){
  if(T){
    print_kd(T->lchild);
    print_ll(T->data);
    cout<<endl;
    print_kd(T->rchild);
  }
}

int main(){
  kdptr K = NULL;
  int n;
  cin>>n;
  int x;
  cin>>x;
  while(x != -1){
    lptr L = NULL;
    insert_node(L, x);
    for(int i=0; i<n-1; i++){
      cin>>x;
      insert_node(L, x);
    }
    insert_kd(K, L, n, 0);
    cin>>x;
  }
  print_kd(K);
  return 0;
}

// 5 5 2 3 4 11 9 8 12 43 2 4 3 5 1 32 1 4 2 42 12 3 5 4 6 14 14 15 32 4 9 32 43 12 56 16 -1