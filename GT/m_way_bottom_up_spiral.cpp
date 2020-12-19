#include<bits/stdc++.h>
using namespace std;

#define m 4

struct mtnode {
  int cnt=0;
  int keys[m-1];
  struct mtnode *ptr[m] = {NULL};
};

typedef struct mtnode *mtptr;

void create_mt_v2(mtptr &MT, int n){
  if(MT == NULL){
    MT = new(mtnode);
    MT->keys[0] = n;
    MT->cnt=1;
  } else {
    if(MT->cnt != m-1){
      MT->keys[MT->cnt] = n;
      MT->cnt++;
      int i = MT->cnt-2;
      while(i >= 0 && MT->keys[i] > MT->keys[i+1]){
        swap(MT->keys[i], MT->keys[i+1]);
        i--;
      }
    } else {
      int i=0;
      while(i <= MT->cnt-1 && MT->keys[i] < n){
        i++;
      }
      create_mt_v2(MT->ptr[i], n);
    }
  }
}

void m_way_v2(mtptr &MT){
  int n;
  cin>>n;
  if(n != 0){
    create_mt_v2(MT, n);
    m_way_v2(MT);
  }
}

void print_pattern(queue<mtptr> Q1, queue<mtptr> Q2, bool flag, mtptr B){
  mtptr MT1 = Q1.front();
  Q1.pop();
  mtptr MT2 = Q2.front();
  Q2.pop();
  if(Q1.empty()) return;
  if(MT1 == B) {
    flag = !flag;
    Q1.push(MT1);
    Q2.push(MT2);
  }
  for(int i=0; i<=MT1->cnt; i++){
    if (MT1->ptr[i]) Q1.push(MT1->ptr[i]);
  }
  for(int i=MT2->cnt; i>=0; i--){
    if (MT2->ptr[i]) Q2.push(MT2->ptr[i]);
  }
  print_pattern(Q1, Q2, flag, B);
  if(MT1 != B){
    if(flag){
      for(int i=0; i<MT2->cnt; i++){
        cout<<MT2->keys[i]<<" ";
      }
    } else {
      for(int i=MT1->cnt-1; i>=0; i--){
        cout<<MT1->keys[i]<<" ";
      }
    }
  }
}

void print_level(mtptr MT){
  queue<mtptr> Q;
  Q.push(MT);
  mtptr B = new(mtnode);
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
  mtptr MT = NULL;
  int n;
  cin>>n;
  m_way_v2(MT);
  queue<mtptr> Q1;
  queue<mtptr> Q2;
  mtptr B = new(mtnode);
  Q1.push(MT);
  Q1.push(B);
  Q2.push(MT);
  Q2.push(B);
  print_pattern(Q1, Q2, false, B);
  return 0;
}

// 4 18 36 27 9 54 45 50 63 20 47 72 46 49 48 0