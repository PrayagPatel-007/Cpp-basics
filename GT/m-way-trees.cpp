#include<bits/stdc++.h>
using namespace std;

struct mtnode {
  int cnt=0;
  int keys[50];
  struct mtnode *ptr[50] = {NULL};
};

typedef struct mtnode *mtptr;

void create_mt_v1(mtptr &MT, int n, int m){
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
        create_mt_v1(MT->ptr[i], n, m);
      }
    } else {
      int i=0;
        while(i <= MT->cnt-1 && MT->keys[i] < n){
          i++;
        }
        create_mt_v1(MT->ptr[i], n, m);
    }
  }
}

void m_way_v1(mtptr &MT, int m){
  int n;
  cin>>n;
  if(n != 0){
    create_mt_v1(MT, n, m);
    m_way_v1(MT, m);
  }
}

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
  if(n != 0){
    create_mt_v2(MT, n, m);
    m_way_v2(MT, m);
  }
}

void print_inorder(mtptr MT){
  if(MT){
    for(int i=0; i<MT->cnt; i++){
      print_inorder(MT->ptr[i]);
      cout<<MT->keys[i]<<" ";
    }
    print_inorder(MT->ptr[MT->cnt]);
  }
}

int main(){
  mtptr MT1 = NULL, MT2 = NULL;
  int m1, m2;
  cin>>m1;
  m_way_v1(MT1, m1);
  cin>>m2;
  m_way_v2(MT2, m2);
  print_inorder(MT1);
  print_inorder(MT2);
  return 0;
}

// 4 
// 18 36 27 9 54 45 50 63 20 47 72 0
// 4
// 18 36 27 9 54 45 50 63 20 47 72 0
// 4 18 36 27 9 54 45 50 63 20 47 72 0 4 18 36 27 9 54 45 50 63 20 47 72 0