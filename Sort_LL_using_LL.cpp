#include<bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node *next;
};

typedef struct node *lptr;

struct slnode {
  lptr up;
  lptr down;
  struct slnode *next;
};

typedef struct  slnode *slptr;

void create_ll(lptr &L){
  int n;
  cin>>n;
  if(n != -1){
    L = new(node);
    L -> data = n;
    L -> next = NULL;
    create_ll(L->next);
  }
}

void link(slptr &SL, lptr L1, lptr L2){
  if(L1 != NULL || L2 != NULL){
    SL = new(slnode);
    SL -> up = L1;
    while((L1 != NULL && L2 != NULL) && L1 -> data < L2 -> data){
      L1 = L1 -> next;
    }
    if(L2 == NULL){
      L1 = NULL;
    }
    SL -> down = L2;
    while((L1 != NULL && L2 != NULL) && L2 -> data < L1 -> data){
      L2 = L2->next;
    }
    if(L1 == NULL){
      L2 = NULL;
    }
    SL -> next == NULL;
    link(SL->next, L1, L2);
  }
}

void print(slptr SL){
  if(SL != NULL){
    int x;
    if(SL -> down == NULL){
      x = 1000;
    }else {
      x = SL -> down -> data;
    }
    lptr p = SL -> up;
    while(p != NULL && p -> data < x){
      cout<<p->data<<" ";
      p = p  -> next;
    }
    if(p == NULL){
      x = 1000; 
    } else {
      x = p->data;
    }
    p = SL -> down;
    while(p != NULL && p -> data < x){
      cout<<p->data<<" ";
      p = p -> next;
    }
    print(SL -> next);
  }
}

int main(){
  lptr L1 = NULL, L2 = NULL;
  create_ll(L1);
  create_ll(L2);
  slptr SL = NULL;
  link(SL, L1, L2);
  print(SL);
  return 0;
}

// 2 3 9 12 25 48 54 61 -1 4 6 8 15 18 20 36 40 63 67 80 90 -1