#include<bits/stdc++.h>
using namespace std;

struct itnode {
  struct itnode *lchild;
  int low;
  int high;
  int max;
  struct itnode *rchild;
};

typedef struct itnode *itptr;

itptr new_itnode(int low, int high, int max){
  itptr T = new(itnode);
  T->lchild = T->rchild = NULL;
  T->high = high;
  T->low = low;
  T->max = max;
  return T;
}

int maximum(int x, int y){
  return (x > y) ? x : y;
}

void insert_it(itptr &I, int low, int high, int max){
  if(I == NULL){
    I = new_itnode(low, high, max);
  } else {
    if (I->low > low){
      I->max = maximum(max, I->max);
      insert_it(I->lchild, low, high, max);
    } else {
      I->max = maximum(max, I->max);
      insert_it(I->rchild, low, high, max);
    }
  }
}

void print_interval(itptr I, int l, int h){
  if(I){
    if(I->max < h){
      return;
    } else if(I->low < l){
      if(I->high > h){
        cout<<I->low<<" "<<I->high<<endl;
      }
      print_interval(I->lchild, l, h);
      print_interval(I->rchild, l, h);
    } else if(I->low > l){
      print_interval(I->lchild, l, h);
    }
  }
}

int main(){
  itptr I = NULL;
  for(int i=0; i<8; i++){
    int x;
    cin>>x;
    if(x == 1){
      int a, b, c;
      cin>>a>>b>>c;
      insert_it(I, a, b, c);
    } else if(x == 2){
      int a, b;
      cin>>a>>b;
      print_interval(I, a, b);
    }
  }
  return 0;
}

// 1 15 20 20 1 10 30 30 1 12 15 15 1 5 20 20 1 17 19 40 1 30 40 40 2 6 7 2 32 35