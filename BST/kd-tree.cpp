#include<bits/stdc++.h>
using namespace std;

struct kdnode{
  struct kdnode *lchild;
  int data[20];
  struct kdnode *rchild;
};

typedef struct kdnode *kdptr;

void insert(kdptr &T, int arr[], int n, int index){
  if(T == NULL){
    T = new(kdnode);
    T->lchild = NULL;
    T->rchild = NULL;
    for(int i=0; i<n; i++){
      T->data[i] = arr[i];
    }
  } else {
    if(T->data[index] > arr[index])
    insert(T->lchild, arr, n, (index+1)%n);
    else
    insert(T->rchild, arr, n, (index+1)%n);
  }
}

bool same_array(int arr1[], int arr2[], int n){
  for(int i=0; i<n; i++){
    if(arr1[i] != arr2[i]) return false;
  }
  return true;
}

bool find_kd(kdptr T, int arr[], int n, int i){
  if (same_array(arr, T->data, n)){
    return true;
  } else {
    if(T->data[i] > arr[i])
    return find_kd(T->lchild, arr, n, (i+1)%n);
    else
    return find_kd(T->rchild, arr, n, (i+1)%n);
  }
}

void print_levels (kdptr T, int d){
  queue<kdptr> Q;
  Q.push(T);
  kdptr E, B = T;
  E=new(kdnode);
  E->data[0]=-1;
  E->lchild=NULL;
  E->rchild=NULL;
  Q.push(E);
  while(true){
    B = Q.front();
    Q.pop();
    if(Q.empty()){
      break;
    }
    if(B->data[0] == -1){
      cout<<endl;
      Q.push(B);
    }else {
      cout<<"( ";
      for(int j=0; j<d; j++){
        cout<<B->data[j]<<" ";
      }cout<<")";
    }
    if (B -> lchild != NULL)
      Q.push(B->lchild);
    if (B -> rchild != NULL)
      Q.push(B->rchild);
  }
}

int main(){
  kdptr T = NULL;
  int n, d;
  cin>>n>>d;
  for(int i=0;i<n/d;++i){
    int arr[d];
    for(int j=0; j<d;j++){
      cin>>arr[j];
    }
    insert(T, arr, d, 0);
  }
  // int arr[] = {10, 11,12};
  // cout<<find_kd(T, arr, d, 0);
  print_levels(T, d);
  return 0;
}

// 12 3 1 2 3 4 5 6 7 8 9 10 11 12
// 21 3 20 8 10 3 18 70 70 15 4 10 80 16 40 30 10 10 25 15 85 30 75 