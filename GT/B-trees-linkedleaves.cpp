#include<bits/stdc++.h>
using namespace std;

#define m 3

struct Bdnode {
  int cnt=0;
  int keys[m-1];
  struct Bdnode *ptr[m] = {NULL};
};

struct OVnode {
  int cnt=m;
  int keys[m];
  struct Bdnode *ptr[m+1] = {NULL};
};

typedef struct Bdnode *Bdptr;
typedef struct OVnode *ovptr;

void find_parent(Bdptr T, Bdptr k, Bdptr &parent){
  if( T == NULL || T->ptr[0] == NULL) return;
  for(int i=0; i<=T->cnt; i++){
    if(T->ptr[i] == k){
      parent = T;
    }
    find_parent(T->ptr[i], k, parent);
  }
}

void sort(int arr[], Bdptr ptr[], int n){
  int i = n-2;
  while(i >= 0 && arr[i] > arr[i+1]){
    swap(arr[i], arr[i+1]);
    swap(ptr[i+1], ptr[i+2]);
    i--;
  }
}

void Add(Bdptr &BT, Bdptr &T, int n, bool flag){
  if(BT == NULL){
    Bdptr K = new(Bdnode);
    K->keys[0] = n;
    K->cnt++;
    T = K;
    BT = K;
  } else {
    if(BT->ptr[0] == NULL || flag){
      if(BT->cnt != m-1){
        BT->keys[BT->cnt] = n;
        sort(BT->keys, BT->ptr, m-1);
        BT->cnt++;
      } else {
        // overflow
        Bdptr A = new(Bdnode);
        Bdptr B = new(Bdnode);
        ovptr O = new(OVnode);
        for(int i=0; i<m-1; i++){
          O->keys[i] = BT->keys[i];
          O->ptr[i] = BT->ptr[i];
        }
        O->ptr[m-1] = BT->ptr[m-1];
        O->keys[m-1] = n;
        sort(O->keys, O->ptr, m);
        int mid = (m)/2;
        int middle = O->keys[mid];
        BT->cnt = 0;
        A->ptr[0] = O->ptr[0];
        for(int i=0; i<mid; i++){
          A->keys[i] = O->keys[i];
          A->ptr[i+1] = O->ptr[i+1];
          A->cnt++;
        }
        int x=0;
        B->ptr[x] = O->ptr[mid+1];
        for(int i=mid+1; i<m; i++){
          B->keys[x] = O->keys[i];
          B->ptr[x+1] = O->ptr[i+1];
          x++;
          B->cnt++;
        }
        Bdptr parent = NULL;
        find_parent(T, BT, parent);
        Add(parent, T, middle, true);
        find_parent(T, BT, parent);
        for(int i=0; i<parent->cnt; i++){
          if(parent->keys[i] == middle) {
            parent->ptr[i] = A;
            parent->ptr[i+1] = B;
          }
        }
        if(!flag) A->ptr[m-1] = B;
      }
    } else {
      int i=0;
      while(BT->keys[i] < n && i < BT->cnt){
        i++; 
      }
      Add(BT->ptr[i], T, n, false);
    }
  }
}

Bdptr print_left(Bdptr T){
  while(T->ptr[0]){
    T = T->ptr[0];
  }
  return T;
}

int main(){
  Bdptr BT = NULL;
  for(int i=10; i>0; i--){
    Add(BT, BT, i, false);
  }
  Bdptr l = print_left(BT);
  Bdptr p = l;
  while(p){
    for(int i=0; i<p->cnt;i++){
      cout<<p->keys[i]<<" ";
    }
    p = p->ptr[m-1];
  }
  return 0;
}

// 10 9 8 7 6 5 4 3 2 1 -1
