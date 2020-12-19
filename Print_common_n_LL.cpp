#include<bits/stdc++.h>
using namespace std;

struct node {
  int datai;
  char datac;
  struct node *next;
};

typedef struct node *lptr;

struct lnode {
  lptr data = NULL;
  struct lnode *lnext;
};

typedef struct lnode *llptr;

void create_ll(lptr &L){
  int n;
  char c;
  cin>>c>>n;
  if(n != -1 || c != '#'){
    L = new(node);
    L -> datac = c;
    L -> datai = n;
    L -> next = NULL;
    create_ll(L->next);
  }
}

void create_lll(llptr &L){
  llptr p = L;
  for(int i=0; i<3; i++){
    create_ll(p->data);
    p -> lnext = new(lnode);
    p = p -> lnext;
  }
}

void print_ll(lptr L){
  if(L != NULL){
    cout<<L->datac<<L->datai<<" ";
    print_ll(L->next);
  }
}

void print(llptr L){
  if(L -> lnext != NULL){
    print_ll(L->data);
    print(L->lnext);
  }
}

void delete_k (lptr &L, int n, char c) {
    if (L == NULL) {
        cout<<"k not found";
        return;
    }
    if (L->datai != n || L->datac != c) {
        delete_k(L -> next, n, c);
    } else {
        L = L -> next;
    }
}

void insert(lptr &L, int n, char c){
  if(L == NULL){
    L -> datac = c;
    L -> datai = n;
    L -> next = NULL;
    return;
  }
  insert(L->next, n, c);
}

void print_common(llptr L, lptr &L1){
  if(L != NULL){
    lptr p = L->data;
    lptr p2 = L1;
    while(p2 != NULL){
      while(p != NULL){
        if(p->datai == p2->datai && p->datac==p2->datac){
          insert(L1, p->datai, p->datac);
        }
        p = p -> next;
      }
      delete_k(L1, p2->datai, p2->datac);
      p2 = p2 -> next;
    }
    print_common(L->lnext, L1);
  }
}

int main(){
  llptr L = new(lnode);
  create_lll(L);
  print_common(L->lnext, L->data);
  print_ll(L->data);
  return 0;
}

// A 3 C 9 N 5 S 6 # -1 B 5 S 6 L 2 C 9 # -1 L 7 J 8 N 2 A 3 C 9 B 9 S 6 E 4 # -1