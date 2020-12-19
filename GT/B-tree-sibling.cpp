#include<bits/stdc++.h>
using namespace std;

#define m 3

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
  int j = mid+1;
  B->ptr[x] = O->ptr[j];
  for(int i=j; i<m; i++){
    B->keys[x] = O->keys[i];
    B->ptr[x+1] = O->ptr[i+1];
    x++;
    B->cnt++;
  }
  p1 = BT;
  p2 = B;
  n = middle;
}

void left_sibling(Bdptr parent, int index){
  int i = index - 1;
  while(i >= 0) {
    if(parent->ptr[i] && parent->ptr[i]->cnt != m-1) {
      break;
    }
    i--;
  } 
  for(int j = i; j<index-1; j++){
    parent->ptr[j]->keys[parent->ptr[j]->cnt] = parent->keys[j];
    parent->ptr[j]->cnt++;
    parent->keys[j] = parent->ptr[j+1]->keys[0];
    parent->ptr[j+1]->cnt--;
    int count = parent->ptr[j+1]->cnt;
    for(int k=0; k<count; k++){
      parent->ptr[j+1]->keys[k] = parent->ptr[j+1]->keys[k+1];
      parent->ptr[j+1]->ptr[k] = parent->ptr[j+1]->ptr[k+1];
    }
    parent->ptr[j+1]->ptr[count] = parent->ptr[j+1]->ptr[count+1];
  }
}

void right_sibling(Bdptr parent, int index){
  int i = index + 1;
  while(i < m) {
    if(parent->ptr[i] && parent->ptr[i]->cnt != m-1) {
      break;
    }
    i++;
  } 
  for(int j = i; j>index+1; j--){
    Bdptr P = parent->ptr[j];
    P->ptr[P->cnt+1] = P->ptr[P->cnt];
    for(int k=P->cnt; k>0; k--){
      P->keys[k] = P->keys[k-1];
      P->ptr[k] = P->ptr[k-1];
    }
    P->cnt++;
    P->keys[0] = parent->keys[j-1];
    parent->keys[j-1] = parent->ptr[j-1]->keys[parent->ptr[j-1]->cnt-1];
    parent->ptr[j-1]->cnt--;
  }
}

bool has_left(Bdptr parent, int index){
  while(index >= 0) {
    if(parent->ptr[index] && parent->ptr[index]->cnt != m-1){
      return true;
    }
    index--;
  }
  return false;
}

bool has_right(Bdptr parent, int index){
  while(index < m) {
    if(parent->ptr[index] && parent->ptr[index]->cnt != m-1){
      return true;
    }
    index++;
  }
  return false;
}

void Add(Bdptr &BT, Bdptr &T, int &n, bool &flag, Bdptr parent, Bdptr &p1, Bdptr &p2, int index){
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
        Add(BT->ptr[i], T, n, flag, BT, p1, p2, i);
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
        ovptr O = new(OVnode);
        for(int i=0; i<m-1; i++){
          O->keys[i] = BT->keys[i];
          O->ptr[i] = BT->ptr[i];
        }
        O->ptr[m-1] = BT->ptr[m-1];
        O->keys[m-1] = n;
        sort(O->keys, O->ptr, m, flag);
        if(!parent) {
          Bdptr B = new(Bdnode);
          overflow_adjust(B, O, BT, p1, p2, n, flag);
          flag = true;
          Add(parent, T, n, flag, parent, p1, p2, index);
        } else {
        if(has_left(parent, index)){
          // left sibling
          left_sibling(parent, index);
          parent->ptr[index-1]->keys[parent->ptr[index-1]->cnt] = parent->keys[index-1];
          parent->ptr[index-1]->cnt++;
          parent->keys[index-1] = O->keys[0];
          BT->ptr[0] = O->ptr[1];
          BT->cnt = 0;
          for(int i=0; i<m-1; i++){
            BT->keys[i] = O->keys[i+1];
            BT->ptr[i+1] = O->ptr[i+2];
            BT->cnt++;
          }
          flag = false;
        } else if (has_right(parent, index)) {
          // right sibling
          right_sibling(parent, index);
          Bdptr P = parent->ptr[index+1];
          P->ptr[P->cnt+1] = P->ptr[P->cnt];
          for(int i=P->cnt; i>0; i--){
            P->keys[i] = P->keys[i-1];
            P->ptr[i] = P->ptr[i-1];
          }
          P->cnt++;
          P->keys[0] = parent->keys[index];
          parent->keys[index] = O->keys[m-1];
          BT->ptr[0] = O->ptr[0];
          BT->cnt=0;
          for(int i=0; i<m-1; i++){
            BT->keys[i] = O->keys[i];
            BT->ptr[i+1] = O->ptr[i+1];
            BT->cnt++;
          }
          flag = false;
        } else {
          Bdptr B = new(Bdnode);
          overflow_adjust(B, O, BT, p1, p2, n, flag);
          flag = true;
        }
        }
      }
    }
  }
}

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
  int n, d, num;
  bool flag=false;
  Bdptr p1=NULL, p2=NULL;
  cin>>num;
  Bdptr parent = NULL;
  while(num != 0){
    parent = NULL;
    p1 = NULL;
    p2 = NULL;
    flag = false;
    Add(BT, BT, num, flag, parent, p1, p2, -1);
    cin>>num;
  }
  print_level(BT);
  return 0;
}

// 15 9 8 7 6 18 27 45 3 5 4 0
// 5 19 21 28 16 18 26 29 13 20 8 14 15 4 6 27 30 0