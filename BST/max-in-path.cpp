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

void print_arr(int arr[], int n){
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
}

void find_path(btptr T, int v1[], int v2[], int n1, int n2, bool &first, int i1, int i2, int &num_i1){
  if(T != NULL){
    if (first) {
      v1[i1] = T->data;
      i1++;
    }  
    v2[i2] = T->data;
    i2++;
    if(!first && (T->data == n2 || T->data == n1)){
      int min = (num_i1 > i2) ? i2 : num_i1;
      for(int i=0; i<min; i++){
        if(v1[i] != v2[i]){
          min = i-1;
          break;
        }
      }
      int max = INT_MIN;
      for(int i=min; i<num_i1-1; i++){
        if(max < v1[i]) max = v1[i];
      }
      for(int i=min; i<i2-1; i++){
        if(max < v2[i]) max = v2[i];
      }
      if(max == INT_MIN) cout<<"NO elements between\n";
      else cout<<max<<endl;
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
  int n;
  btptr T = NULL;
  cin>>n;
  insert(T, n);
  int v1[40];
  int v2[40];
  bool first = true;
  int i1=0;
  int n1, n2;
  cin>>n1>>n2;
  find_path(T, v1, v2, n1, n2, first,0,0,i1);
  first = true;
  i1=0;
  cin>>n1>>n2;
  find_path(T, v1, v2, n1, n2, first,0,0,i1);
  first =true;
  i1=0; 
  cin>>n1>>n2;
  find_path(T, v1, v2, n1, n2, first,0,0,i1);
  return 0;
}