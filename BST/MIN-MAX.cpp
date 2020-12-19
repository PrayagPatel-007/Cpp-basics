#include<bits/stdc++.h>
using namespace std;

struct btnode {
  struct btnode *lchild;
  int data;
  struct btnode *rchild;
};

typedef struct btnode *btptr;

void insert(btptr &T, char k){
  char n;
  if(T == NULL){
    T = new(btnode);
    T->data = k;
    T->lchild = NULL;
    T->rchild = NULL;
  }
  cin>>n;
  if(n != '#'){
    insert(T->lchild, n);
  }
  cin>>n;
  if(n != '#'){
    insert(T->rchild, n);
  }
}

void is_bst(btptr T, int min, int max, bool &bst){
  if(T != NULL){
    if(max < T->data || min > T->data){
      bst=false;
      return;
    }
    is_bst(T->lchild, min, T->data-1, bst);
    is_bst(T->rchild, T->data+1, max, bst);
  }
}

void print_dead_ends(btptr T, int min, int max){
  if(T != NULL){
    if((T->lchild == NULL && min == T->data) || (T->rchild == NULL && max == T->data)) {
      cout<<T->data<<" ";
    }
    print_dead_ends(T->lchild, min, T->data-1);
    print_dead_ends(T->rchild, T->data+1, max);
  }
}

void swap_2_nodes(btptr T, bool first, btptr &b1, int min, int max){
  if(T != NULL){
    if(max < T->data || min > T->data){
      if(first){
        first=false;
        b1=T;
      }else{
        swap(b1->data, T->data);
        return;
      }
    }
    swap_2_nodes(T->lchild, first, b1, min, T->data-1);
    swap_2_nodes(T->rchild, first, b1, T->data+1, max);
  }
}

void create_bst_lvl(string s, btptr &T){
  queue<btptr> Q;
  queue<pair<int, int>> Q1;
  int i = 0, min, max;
  T = new(btnode);
  T->data = s[i];
  i++;
  T->lchild = NULL;
  T->rchild = NULL;
  Q.push(T);
  Q1.push({INT_MIN, INT_MAX});
  btptr B;
  while(true){
    B = Q.front();
    Q.pop();
    B->lchild->data = s[i];
    i++;
    B->lchild->lchild = NULL;
    B->lchild->rchild = NULL;
    min = Q1.front().first;
    max = Q1.front().second;
    Q1.pop();
    B->rchild->data = s[i];
    i++;
    B->rchild->lchild = NULL;
    B->rchild->rchild = NULL;
    if(B->lchild){
      Q.push(B->lchild);
      Q1.push({min, B->data - 1});
    }
    if(B->rchild){
      Q.push(B->rchild);
      Q1.push({B->data + 1, max});
    }
  }
}

void print_level(btptr T, int arr[], int &i){
  if(T != NULL){
    print_level(T->lchild, arr, i);
    arr[T->data] = i;
    i++;
    print_level(T->rchild, arr, i);
  }
}

void print_level_in(btptr T, int arr[]){
  queue<btptr> Q;
  Q.push(T);
  btptr E, B = T;
  E=new(btnode);
  E->data='#';
  E->lchild=NULL;
  E->rchild=NULL;
  Q.push(E);
  int i=0;
  while(true){
    B = Q.front();
    Q.pop();
    if(Q.empty()){
      break;
    }
    if(B->data == '#'){
      i=0;
      cout<<endl;
      Q.push(B);
    }else {
      while(i<arr[B->data]){
        cout<<" ";
        i++; 
      }
      cout<<B->data;
      i++;
    }
    if (B -> lchild != NULL)
      Q.push(B->lchild);
    if (B -> rchild != NULL)
      Q.push(B->rchild);
  }
}





int main() {
  btptr T = NULL;
  int n = 8;
  // cin>>n;
  // insert(T, n);
  // bool bst=true;
  // is_bst(T, INT_MIN, INT_MAX, bst);
  // cout<<bst;
  return 0;
}