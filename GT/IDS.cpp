#include<bits/stdc++.h>
using namespace std;

struct gtnode {
  struct gtnode *fc;
  int data;
  struct gtnode *ns;
};

typedef gtnode *gtptr;

gtptr new_gtnode(int n){
  gtptr T = new(gtnode);
  T->data = n;
  T->fc = T->ns = NULL;
  return T;
}

void create_gt(gtptr &GT, int n){
  int num;
  if(GT == NULL){
    GT = new_gtnode(n);
  } 
  cin>>num;
  if(num != 0) create_gt(GT->fc, num);
  cin>>num;
  if(num != 0) create_gt(GT->ns, num);
}

void max_depth(gtptr GT, int i, int &max){
  if(GT){
    if(max < i) max =  i;
    max_depth(GT->fc, i+1, max);
    max_depth(GT->ns, i, max);
  }
}

bool DLS(gtptr GT, int n, int limit){
  if(GT->data == n) return true;
  if(limit <= 0) return false;
  gtptr p = GT->fc;
  while(p != NULL){
    if(DLS(p, n, limit-1)) return true;
    p = p->ns;
  }
  return false;
}

bool IDDFS(gtptr GT, int n, int max_depth){
  for(int i=0; i<=max_depth; i++){
    if(DLS(GT, n, i)) return true;
  }
  return false;
}

int main(){
  gtptr GT = NULL;
  int n, max = INT_MIN;
  cin>>n;
  create_gt(GT, n);
  max_depth(GT, 0, max);
  int q;
  cin>>q;
  while(q != 0){
    cin>>n;
    cout<<IDDFS(GT, n, max)<<endl;
    q--;
  }
  return 0;
}

// 50 49 47 33 0 43 35 0 34 0 0 42 32 0 0 0 0 46 41 31 0 30 0 0 40 29 0 28 0 0 0 48 45 39 27 0 26 0 0 38 25 0 24 0 0 0 44 37 23 0 22 0 0 21 0 36 20 0 0 0 0 0 0 3 21 35 19