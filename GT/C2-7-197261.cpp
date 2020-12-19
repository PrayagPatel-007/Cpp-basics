#include<bits/stdc++.h>
using namespace std;

struct btnode {
  struct btnode *lchild;
  int data;
  struct btnode *rchild;
};

typedef struct btnode *btptr;

void insert(btptr &T, int n){
  int num;
  if(T == NULL){
    T = new(btnode);
    T -> data = n;
    T -> lchild = NULL;
    T -> rchild = NULL;
  } 
  cin>>num;
  if(num != 0){
    insert(T->lchild, num);
  }
  cin>>num;
  if(num != 0){
    insert(T->rchild, num);
  }
}

bool is_on_path(btptr T, int num){
  if(T){
    if(T->data == num){
      return true;
    } else {
      return is_on_path(T->lchild, num) || is_on_path(T->rchild, num);
    }
  } else {
    return false;
  }
}

void print_child_distance(btptr T, int distance){
  if(T){
    if(distance == 0) {
      cout<<T->data<<" ";
      return;
    }
    print_child_distance(T->lchild, distance-1);
    print_child_distance(T->rchild, distance-1);
  }
}

void print_nodes(btptr T, int num, int distance, int &up){
  if(T){
    if(T->data == num) {
      print_child_distance(T, distance);
      return;
    }
    if(is_on_path(T->lchild, num)) {
      print_nodes(T->lchild, num, distance, up);
    } else {
      print_nodes(T->rchild, num, distance, up);
    }
    if(up == 1) {
      cout<<T->data<<" ";
      up = INT_MAX;
    } else {
      up--;
    }
  }
}

int main(){
  btptr T = NULL;
  int n;
  cin>>n;
  insert(T, n);
  int num, d;
  cin>>num>>d;
  print_nodes(T, num, d, d);
  return 0;
}

// 4 5 7 11 0 0 12 0 0 8 13 0 0 14 0 0 6 9 15 0 0 16 0 0 10 17 0 0 18 0 0