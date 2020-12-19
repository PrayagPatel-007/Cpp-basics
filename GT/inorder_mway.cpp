#include<bits/stdc++.h>
using namespace std;

struct mtnode {
  int cnt=0;
  int keys[50];
  struct mtnode *ptr[50] = {NULL};
};

typedef struct mtnode *mtptr;

void create_mt_v2(mtptr &MT, int arr[], int m, int l, int r){
  if(MT == NULL){
    if(r-l < 2) return;
    int k = (r-l-2)/m;
    MT = new(mtnode);
    for(int i=0; i<m-1; i++){
      MT->keys[i] = arr[l+k];
      create_mt_v2(MT->ptr[i], arr, m, l, l+k);
      l += k+1;
    }
    create_mt_v2(MT->ptr[m-1], arr, m, l, l+k);
    MT->cnt = m-1;
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
  int arr[100];
  int m;
  mtptr MT = NULL;
  cin>>m;
  int i=0;
  int n;
  cin>>n;
  while(n != -1){
    arr[i] = n;
    i++;
    cin>>n;
  }
  create_mt_v2(MT, arr, m, 0, i);
  print_level(MT);
  return 0;
}

// 3 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 -1