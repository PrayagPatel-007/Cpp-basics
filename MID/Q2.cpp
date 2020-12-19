#include<bits/stdc++.h>
using namespace std;

union u {
  int i;
  char c;
};

struct node {
  struct lnode *data;
  struct node *next;
};

struct lnode {
  union u data;
  int tag;
  struct lnode *next;
};

typedef struct node *lptr;
typedef struct lnode *nlptr;

void insert(lptr &L, nlptr k){
  if(L == NULL){
    L = new(node);
    L->data = k;
    L->next = NULL;
  } else {
    insert(L->next, k);
  }
}

void create_n_c(nlptr L, lptr &N, lptr &C){
  int flag=1;
  while(L != NULL){
    if(L->tag == 0 && flag == 1){
      insert(N, L);
      flag = 0;
    } else if(L->tag == 1 && flag == 0){
      insert(C, L);
      flag = 1;
    }
    L=L->next;
  }
}

void print_N(lptr L){
  while(L != NULL) {
    nlptr T = L->data;
    while(T!= NULL && T->tag == 0 ){
      cout<<T->data.i<<" ";
      T=T->next;
    }
    L=L->next;
  }
}

void print_C(lptr L){
  while(L != NULL){
    nlptr T=L->data;
    while(T != NULL && T->tag == 1){
      cout<<T->data.c<<" ";
      T=T->next;
    }
    L=L->next;
  }
}

void create_L(nlptr &L, int tag, union u a){
  if(L == NULL){
    L = new(lnode);
    L->data = a;
    L->next = NULL;
    L->tag = tag;
  } else {
    create_L(L->next, tag, a);
  }
}

int main(){
  nlptr L=NULL;
  lptr N=NULL, C=NULL;
  int n;
  cin>>n;
  while(n != -1){
    union u a;
    int tag;
    if(n == 1){
      cin>>a.i;
      tag = 0;
    } else if(n == 0){
      cin>>a.c;
      tag = 1;
    }
    create_L(L, tag, a);
    cin>>n;
  }
  create_n_c(L, N, C);
  print_N(N);
  cout<<endl;
  print_C(C);
  cout<<endl;
}

// 1 5 1 7 1 2 0 C 0 S 0 E 0 A 1 8 1 6 0 N 0 W 0 T 1 9 0 B 1 4 1 5 -1
