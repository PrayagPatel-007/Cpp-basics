#include<bits/stdc++.h>
using namespace std;

struct mtnode {
  int cnt=0;
  int keys[50];
  struct mtnode *ptr[50] = {NULL};
};

typedef struct mtnode *mtptr;

void create_mt_v2(mtptr &MT, int n, int m){
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
      create_mt_v2(MT->ptr[i], n, m);
    }
  }
}

void m_way_v2(mtptr &MT, int m){
  int n;
  cin>>n;
  if(n != -1){
    create_mt_v2(MT, n, m);
    m_way_v2(MT, m);
  }
}

void min_mtnode(mtptr MT, mtptr &min){
  if(MT){
    min_mtnode(MT->ptr[0], min);
    if(MT->ptr[0] == NULL) min = MT;
  }
}

void max_mtnode(mtptr MT, mtptr &max){
  if(MT){
    max_mtnode(MT->ptr[MT->cnt], max);
    if(MT->ptr[MT->cnt] == NULL) max = MT;
  }
}

void delete_mtnode(mtptr MT, int n){
  if(MT){
    for(int i=0; i<MT->cnt; i++){
      if(MT->keys[i] == n && !MT->ptr[i] && !MT->ptr[i+1]){
        int j=i;
        while(j < MT->cnt-1){
          swap(MT->keys[j], MT->keys[j+1]);
          swap(MT->ptr[j], MT->ptr[j+1]);
          j++;
        }
        swap(MT->ptr[j], MT->ptr[j+1]);
      } else if(MT->keys[i] == n && MT->ptr[i+1]) {
        mtptr min;
        min_mtnode(MT->ptr[i+1], min);
        swap(min->keys[0], MT->keys[i]);
        delete_mtnode(min, n);
      } else if(MT->keys[i] == n && MT->ptr[i]) {
        mtptr max;
        max_mtnode(MT->ptr[i], max);
        swap(max->keys[max->cnt-1], MT->keys[i]);
        delete_mtnode(max, n);
      }
    }
    for(int i=0; i<= MT->cnt; i++){
      delete_mtnode(MT->ptr[i], n);
    }
  }
}

void delete_last(mtptr MT, int n){
  if(MT){
    for(int i=0; i<=MT->cnt; i++){
      if(MT->ptr[i] && MT->ptr[i]->keys[MT->ptr[i]->cnt-1] == n) {
        MT->ptr[i]->keys[MT->ptr[i]->cnt-1] = 0;
        MT->ptr[i]->cnt--;
        if(MT->ptr[i]->cnt == 0){
          MT->ptr[i] = NULL;
        }
      }
    }
    for(int i=0; i<=MT->cnt; i++){
      delete_last(MT->ptr[i], n);
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
  int m;
  cin>>m;
  m_way_v2(MT, m);
  print_level(MT);
  int x, y;
  cin>>x>>y;
  delete_mtnode(MT, x);
  delete_last(MT, x);
  delete_mtnode(MT, y);
  delete_last(MT, y);
  print_level(MT);
  return 0;
}

// 3 18 54 6 8 25 45 63 81 1 3 10 12 30 36 72 75 90 -1 25 54

