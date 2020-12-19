#include<bits/stdc++.h>
using namespace std;

struct bstnode {
  struct bstnode *lchild;
  int data;
  struct bstnode *rchild;
};

typedef struct bstnode *bstptr;

void insert_bnode(bstptr &T, int k){
  if (T == NULL){
    T = new(bstnode);
    T -> data = k;
    T -> lchild = NULL;
    T -> rchild = NULL;
  } else {
    if (k < T -> data){
      insert_bnode(T -> lchild, k);
    } else {
      insert_bnode(T -> rchild, k);
    }
  }
}


void create_bst(bstptr &T){
  int k;
  cin>>k;
  if (k != -1){
    insert_bnode(T, k);
    create_bst(T);
  }
}

void make_vector(bstptr T, vector<int> &v){
  if(T != NULL){
    make_vector(T->lchild, v);
    v.push_back(T->data);
    make_vector(T->rchild, v);
  }
}

void print_sum(vector<int> v1, vector<int> v2){
  int sum1, sum2, sum;
  int h = v2.size() - 2;
  for(int i=0; i<v1.size(); i++){
    sum1 = v1.size() - 1;
    sum2 = v2.size() - 1;
    for (int j = h; j >= 0; j--)
    {
      sum = v1[i] + v2[j];
      while(v1[sum1] > sum){
        sum1--;
      }
      while(v2[sum2] > sum){
        sum2--;
      }
      if (v1[sum1] == sum || v2[sum2] == sum){
        cout<<"("<<v1[i]<<", "<<v2[j]<<", "<<sum<<")\n";
      }
    }
  }
}

int main(){
  bstptr T1 = NULL, T2 = NULL;
  create_bst(T1);
  create_bst(T2);
  vector<int> v1, v2;
  make_vector(T1, v1);
  make_vector(T2, v2);
  print_sum(v1, v2);
  return 0;
}
