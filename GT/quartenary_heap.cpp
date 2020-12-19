#include<bits/stdc++.h>
using namespace std;

struct qtnode {
  int data;
  struct qtnode *cptr[4] = {NULL};
};

typedef struct qtnode *qtptr;

pair<int, int> min(qtptr arr[], int m){
  int min = INT_MAX;
  int index;
  for(int i=0; i<m; i++){
    if(arr[i] && min > arr[i]->data){
      min = arr[i]->data;
      index=i;
    }
  }
  return {min, index};
}

void perculate_up(qtptr QT, int m){
  if(QT){
    if(QT->cptr[0]){
      for(int i=0; i<m; i++){
        perculate_up(QT->cptr[i], m);
      }
      if(min(QT->cptr, m).first < QT->data){
        swap(QT->cptr[min(QT->cptr, m).second]->data, QT->data);
      } else {
        return;
      }
    }
  }
}

void create_heap(qtptr &QT, int m){
  int n;
  cin>>n;
  if(n != -1){
    QT = new(qtnode);
    QT->data = n;
  }
  queue<qtptr> Q;
  Q.push(QT);
  bool done = false;
  while(!done){
    qtptr B = Q.front();
    Q.pop();
    for(int i=0; i<m; i++){
      cin>>n;
      if(n != -1){
        B->cptr[i] = new(qtnode);
        Q.push(B->cptr[i]);
        B->cptr[i]->data = n;
        perculate_up(QT, m);
      } else {
        done = true;
        break;
      }
    }
  }
}

void print_level(qtptr QT, int m){
  queue<qtptr> Q;
  Q.push(QT);
  qtptr B = new(qtnode);
  Q.push(B);
  while(true){
    QT = Q.front();
    Q.pop();
    if(Q.empty()) {
      cout<<endl;
      break;
    }
    if(QT == B) {
      cout<<endl;
      Q.push(B);
    } else cout<<QT->data<<" ";
    for(int i=0; i<m; i++){
      if(QT->cptr[i]) Q.push(QT->cptr[i]);
    }
  }
}

int main(){
  qtptr QT = NULL;
  create_heap(QT, 4);
  print_level(QT, 4);
  return 0;
}

// 9 5 12 3 10 6 8 14 11 4 7 1 13 15 2 -1