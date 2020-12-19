#include<bits/stdc++.h>
using namespace std;

struct btnode {
  struct btnode *lchild;
  char data;
  struct btnode *rchild;
};

typedef struct btnode *btptr;

void insert(btptr &T, string k, int &i){
  if(T == NULL){
    T = new(btnode);
    T->data = k[i];
    i++;
    T->lchild = NULL;
    T->rchild = NULL;
  }
  if(k[i] != '#'){
    insert(T->lchild, k, i);
  } else i++;
  if(k[i] != '#'){
    insert(T->rchild, k, i);
  } else i++;
}

void print_arr(int arr[], int n){
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
}

void find_path(btptr T, char v1[], char v2[], int n1, int n2, bool &first, int i1, int i2, int &num_i1){
  if(T != NULL){
    if (first) {
      v1[i1] = T->data;
      i1++;
    }  
    v2[i2] = T->data;
    i2++;
    if(!first && (T->data == n2 || T->data == n1)){
      int min = (num_i1 > i2) ? i2 : num_i1;
      int i=0;
      while(v1[i] == v2[i] && i<min){
          cout<<v1[i]<<" ";
          i++;
        }
      return;
    } else if(T->data == n1 || T->data == n2){
      first = false;
      num_i1 = i1;
    } 
    find_path(T->lchild, v1, v2, n1, n2, first, i1, i2, num_i1);
    find_path(T->rchild, v1, v2, n1, n2, first, i1, i2, num_i1);
  }
}

int main() {
  string n;
  btptr T = NULL;
  cin>>n;
  int i=0;
  insert(T, n, i);
  char v1[40];
  char v2[40];
  bool first = true;
  int i1=0;
  char n1, n2;
  cin>>n1>>n2;
  find_path(T, v1, v2, n1, n2, first,0,0,i1);
  return 0;
}