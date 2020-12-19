#include<bits/stdc++.h>
using namespace std;

#define m 4

struct Bdnode {
  int cnt=0;
  int keys[m-1] = {0};
  struct Bdnode *ptr[m] = {NULL};
};

struct OVnode {
  int cnt=m;
  int keys[m];
  struct Bdnode *ptr[m+1] = {NULL};
};

typedef struct Bdnode *Bdptr;
typedef struct OVnode *ovptr;


//insert sort
void sort(int arr[], Bdptr ptr[], int n, bool flag){
  int i = n-2;
  while(i >= 0 && arr[i] > arr[i+1]){
    swap(arr[i], arr[i+1]);
    if(flag)
    swap(ptr[i+1], ptr[i+2]);
    i--;
  }
}


// adjustment for overflow
void overflow_adjust(Bdptr &B, ovptr &O, Bdptr &BT, Bdptr &p1, Bdptr &p2, int &n, int flag, bool &toggle) {
  for(int i=0; i<m-1; i++){
    O->keys[i] = BT->keys[i];
    O->ptr[i] = BT->ptr[i];
  }
  O->ptr[m-1] = BT->ptr[m-1];
  O->keys[m-1] = n;
  sort(O->keys, O->ptr, m, flag);
  int mid;
  if(toggle){
    mid = (m/2);
  } else mid = (m/2) - 1;
  toggle = !toggle;
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


// function to insert in B tree
void Add(Bdptr &BT, Bdptr &T, int &n, bool &flag, Bdptr parent, Bdptr &p1, Bdptr &p2, bool &toggle){
  if(BT == NULL){
    Bdptr K = new(Bdnode);
    K->keys[0] = n;
    K->cnt++;
    K->ptr[0] = p1;
    K->ptr[1] = p2;
    T = K;
    BT = K;
  } else {
      if (BT->ptr[0] != NULL) {
        int i=0;
        while(BT->keys[i] < n && i < BT->cnt){
          i++; 
        }
        Add(BT->ptr[i], T, n, flag, BT, p1, p2, toggle);
      }  
      if (BT->ptr[0] == NULL || flag) {
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
        overflow_adjust(B, O, BT, p1, p2, n, flag, toggle);
        flag = true;
        if(parent == NULL) {
          Add(parent, T, n, flag, parent, p1, p2, toggle);
        }
      }
    }
  }
}

// print level order
void print_level(Bdptr MT){
  queue<Bdptr> Q;
  Q.push(MT);
  Bdptr B = new(Bdnode);
  Q.push(B);
  while(true){
    MT = Q.front();
    Q.pop();
    if(Q.empty()) {
      cout<<endl;
      break;
    }
    if(MT == B) {
      cout<<endl;
      Q.push(B);
    }
    for(int i=0; i<MT->cnt; i++){
      cout<<MT->keys[i]<<" ";
    }
    for(int i=0; i<=MT->cnt; i++){
      if(MT->ptr[i]) Q.push(MT->ptr[i]);
    }
  }
}

int main(){
  Bdptr BT = NULL;
  int n, num;
  bool flag=false;
  bool toggle=true;
  Bdptr p1=NULL, p2=NULL;
  num = 12;
  Bdptr parent = NULL;
  for(int i=0; i < num; i++){
    cin>>n;
    parent = NULL;
    p1 = NULL;
    p2 = NULL;
    flag = false;
    Add(BT, BT, n, flag, parent, p1, p2, toggle);
  }
  print_level(BT);
  return 0;
}

// 12 11 10 9 8 7 6 5 4 3 2 1