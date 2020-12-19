#include<bits/stdc++.h>
using namespace std;

#define m 4

struct mtnode {
  int cnt=0;
  int keys[m-1];
  struct mtnode *ptr[m] = {NULL};
};

typedef struct mtnode *mtptr;

void create_mt_v1(mtptr &MT, int n){
  if(MT == NULL){
    MT = new(mtnode);
    MT->keys[0] = n;
    MT->cnt = 1;
  } else {
    if(MT->cnt != m-1) {
      if(MT->keys[MT->cnt-1] < n) {
        MT->keys[MT->cnt] = n;
        MT->cnt++;
      } else {
        int i=0;
        while(i <= MT->cnt-1 && MT->keys[i] < n){
          i++;
        }
        create_mt_v1(MT->ptr[i], n);
      }
    } else {
      int i=0;
        while(i <= MT->cnt-1 && MT->keys[i] < n){
          i++;
        }
        create_mt_v1(MT->ptr[i], n);
    }
  }
}

void m_way_v1(mtptr &MT){
  int n;
  cin>>n;
  if(n != 0){
    create_mt_v1(MT, n);
    m_way_v1(MT);
  }
}

void print_left_view(mtptr MT){
  queue<mtptr> Q;
  Q.push(MT);
  mtptr B = new(mtnode);
  Q.push(B);
  bool first = true;
  while(true){
    MT = Q.front();
    Q.pop();
    if(Q.empty()) {
      cout<<endl;
      break;
    }
    if(MT == B) {
      first = true;
      Q.push(B);
    }else if(first) {
      cout<<MT->keys[0]<<" ";
      first = false;
    }
    for(int i=0; i<=MT->cnt; i++){
      if(MT->ptr[i]) Q.push(MT->ptr[i]);
    }
  }
}

void print_right_view(mtptr MT){
  queue<mtptr> Q;
  Q.push(MT);
  mtptr B = new(mtnode);
  Q.push(B);
  int last;
  while(true){
    MT = Q.front();
    Q.pop();
    if(Q.empty()) {
      cout<<last;
      cout<<endl;
      break;
    }
    if(MT == B) {
      cout<<last<<" ";
      Q.push(B);
    }
    for(int i=0; i<MT->cnt; i++){
      last = MT->keys[i];
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
  m_way_v1(MT);
  print_left_view(MT);
  print_right_view(MT);
  return 0;
  
}

// 4 18 36 27 9 54 45 50 63 20 47 72 46 48 49 0