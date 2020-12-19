#include<bits/stdc++.h>
using namespace std;

#define m 3

struct Bdnode {
  int cnt=0;
  int keys[m-1] = {0};
  struct Bdnode *ptr[m+1] = {NULL};
  bool leaf=false;
};

struct OVnode {
  int cnt=m;
  int keys[m];
  struct Bdnode *ptr[m+2] = {NULL};
};

typedef struct Bdnode *Bdptr;
typedef struct OVnode *ovptr;

void sort(int arr[], Bdptr ptr[], int n, bool flag){
  int i = n-2;
  while(i >= 0 && arr[i] > arr[i+1]){
    swap(arr[i], arr[i+1]);
    if(flag)
    swap(ptr[i+1], ptr[i+2]);
    i--;
  }
}

void overflow_adjust(Bdptr &B, ovptr &O, Bdptr &BT, Bdptr &p1, Bdptr &p2, int &n, int flag) {
  for(int i=0; i<m-1; i++){
    O->keys[i] = BT->keys[i];
    O->ptr[i] = BT->ptr[i];
  }
  O->ptr[m-1] = BT->ptr[m-1];
  O->keys[m-1] = n;
  sort(O->keys, O->ptr, m, flag);
  int mid = (m)/2;
  int middle = O->keys[mid];
  for(int i=0; i<=O->cnt; i++){
    if(O->keys[i] == n) {
      O->ptr[i] = p1;
      O->ptr[i+1] = p2;
    }
  }
  BT->cnt = 0;
  BT->ptr[0] = O->ptr[0];
  for(int i=0; i<mid; i++){
    BT->keys[i] = O->keys[i];
    BT->ptr[i+1] = O->ptr[i+1];
    BT->cnt++;
  }
  int x=0;
  B->ptr[x] = O->ptr[mid+1];
  for(int i=mid+1; i<m; i++){
    B->keys[x] = O->keys[i];
    B->ptr[x+1] = O->ptr[i+1];
    x++;
    B->cnt++;
  }
  p1 = BT;
  p2 = B;
  n = middle;
}

void Add(Bdptr &BT, Bdptr &T, int &n, bool &flag, Bdptr parent, Bdptr &p1, Bdptr &p2){
  if(BT == NULL){
    Bdptr K = new(Bdnode);
    K->keys[0] = n;
    K->cnt++;
    K->ptr[0] = p1;
    K->ptr[1] = p2;
    if(!flag)
      K->leaf = true;
    T = K;
    BT = K;
  } else {
      if (!BT->leaf) {
        int i=0;
        while(BT->keys[i] < n && i < BT->cnt){
          i++; 
        }
        Add(BT->ptr[i], T, n, flag, BT, p1, p2);
      }  
      if (BT->leaf || flag) {
        if(BT->cnt != m-1){
          BT->keys[BT->cnt] = n;
          BT->cnt++;
          sort(BT->keys, BT->ptr, BT->cnt, flag);
          for(int i=0; i<BT->cnt; i++){
            if(BT->keys[i] == n) {
              BT->ptr[i] = p1;
              BT->ptr[i+1] = p2;
              break;
            }
          }
          flag = false;
        } else {
        // OVERFLOW
        Bdptr B = new(Bdnode);
        ovptr O = new(OVnode);
        overflow_adjust(B, O, BT, p1, p2, n, flag);
        p2->ptr[m] = p1->ptr[m];
        p1->ptr[m] = p2;
        if (!flag) {
          p1 -> leaf = true;
          p2 -> leaf = true;
        }
        flag = true;
        if(parent == NULL) {
          Add(parent, T, n, flag, parent, p1, p2);
        }
      }
    }
  }
}

void print_level(Bdptr MT){
  Bdptr last;
  while(!MT->leaf){
    Bdptr p = MT;
    while(p){
      for(int i=0; i<p->cnt; i++){
        cout<<p->keys[i]<<" ";
      }
      last = p;
      p = p -> ptr[m];
    }
    last->ptr[m] = MT->ptr[0];
    MT = MT->ptr[0];
    cout<<endl;
  }
  Bdptr p = MT;
  while(p){
    for(int i=0; i<p->cnt; i++){
      cout<<p->keys[i]<<" ";
    }
    p = p -> ptr[m];
  } cout<<endl;
}

int main(){
  Bdptr BT = NULL;
  int num;
  bool flag=false;
  Bdptr p1=NULL, p2=NULL;
  cin>>num;
  Bdptr parent = NULL;
  while(num != 0){
    parent = NULL;
    p1 = NULL;
    p2 = NULL;
    flag = false;
    Add(BT, BT, num, flag, parent, p1, p2);
    cin>>num;
  }
  print_level(BT);
  Bdptr p = BT;
  while(p) {
    for(int i=0; i<p->cnt; i++){
      cout<<p->keys[i]<<" ";
    }
    p = p ->ptr[m];
  }
  return 0;
}

// 3 10 10 9 8 7 6 5 4 3 2 1
// 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 16 17 18 0