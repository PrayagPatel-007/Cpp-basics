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

void print_array(int arr[], int n){
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int sum_array(int arr[], int n){
  int sum=0;
  for(int i=0; i<n; i++){
    sum += arr[i];
  }
  return sum;
}

int num_even(int arr[], int n){
  int count=0;
  for(int i=0; i<n; i++){
    if(arr[i] % 2 == 0){
      count++;
    }
  }
  return count;
}

int num_odd(int arr[], int n){
  int count=0;
  for(int i=0; i<n; i++){
    if(arr[i] % 2 != 0){
      count++;
    }
  }
  return count;
}

void print_paths(bstptr T, int arr[], int lastIndex){
  if(T != NULL && T->lchild == NULL && T->rchild == NULL){
    arr[lastIndex] = T->data;
    lastIndex++;
    print_array(arr, lastIndex);
    return;
  }
  if(T != NULL){
    arr[lastIndex] = T->data;
    print_paths(T->lchild, arr, lastIndex+1);
    print_paths(T->rchild, arr, lastIndex+1);
  }
}

void path_sum(bstptr T, int arr[], int lastIndex, int sum){
  if(T != NULL && T->lchild == NULL && T->rchild == NULL){
    arr[lastIndex] = T->data;
    lastIndex++;
    if(sum_array(arr, lastIndex) == sum){
      print_array(arr, lastIndex);
    }
    return;
  }
  if(T != NULL){
    arr[lastIndex] = T->data;
    path_sum(T->lchild, arr, lastIndex+1, sum);
    path_sum(T->rchild, arr, lastIndex+1, sum);
  }
}

void min_max_even_odd(bstptr T, int arr[], int lastIndex, int &min, int &max, int &max_even, int &max_odd){
  if(T != NULL && T->lchild == NULL && T->rchild == NULL){
    arr[lastIndex] = T->data;
    lastIndex++;
    if(min > sum_array(arr, lastIndex)){
      min = sum_array(arr, lastIndex);
    } 
    if (max < sum_array(arr, lastIndex)){
      max = sum_array(arr, lastIndex);
    }
    if(max_even < num_even(arr, lastIndex)){
      max_even = num_even(arr, lastIndex);
    } 
    if (max_odd < num_odd(arr, lastIndex)){
      max_odd = num_odd(arr, lastIndex);
    }
    return;
  }
  if(T != NULL){
    arr[lastIndex] = T->data;
    min_max_even_odd(T->lchild, arr, lastIndex+1, min, max, max_even, max_odd);
    min_max_even_odd(T->rchild, arr, lastIndex+1, min, max, max_even, max_odd);
  }
}

void print_even(bstptr T, int arr[], int lastIndex, int even){
  if(T != NULL && T->lchild == NULL && T->rchild == NULL){
    arr[lastIndex] = T->data;
    lastIndex++;
    if(even == num_even(arr, lastIndex)){
      print_array(arr, lastIndex);
    }
    return;
  }
  if(T != NULL){
    arr[lastIndex] = T->data;
    print_even(T->lchild, arr, lastIndex+1, even);
    print_even(T->rchild, arr, lastIndex+1, even);
  }
}

void print_odd(bstptr T, int arr[], int lastIndex, int odd){
  if(T != NULL && T->lchild == NULL && T->rchild == NULL){
    arr[lastIndex] = T->data;
    lastIndex++;
    if(odd == num_odd(arr, lastIndex)){
      print_array(arr, lastIndex);
    }
    return;
  }
  if(T != NULL){
    arr[lastIndex] = T->data;
    print_odd(T->lchild, arr, lastIndex+1, odd);
    print_odd(T->rchild, arr, lastIndex+1, odd);
  }
}

void print_min_max_path(bstptr T, int arr[]){
  int min = 9999, max = -9999;
  int even, odd;
  min_max_even_odd(T, arr, 0, min, max, even, odd);
  path_sum(T, arr, 0, max);
  path_sum(T, arr, 0, min);
}

void print_max_even_odd(bstptr T, int arr[]){
  int min = 9999, max = -9999;
  int even = 0, odd = 0;
  min_max_even_odd(T, arr, 0, min, max, even, odd);
  print_even(T, arr, 0, even);
  print_odd(T, arr, 0, odd);
}

void leftmost_path(bstptr T){
  if(T != NULL){
    cout<<T->data<<" ";
    if(T -> lchild != NULL){
      leftmost_path(T->lchild);
    } else if(T -> rchild != NULL){
      leftmost_path(T -> rchild);
    } else {
      cout<<endl;
    }
  }
}

void rightmost_path(bstptr T){
  if(T != NULL){
    cout<<T->data<<" ";
    if(T -> rchild != NULL){
      rightmost_path(T->rchild);
    } else if(T -> lchild != NULL){
      rightmost_path(T -> lchild);
    } else {
      cout<<endl;
    }
  }
}

int main(){
  bstptr T = NULL;
  create_bst(T);
  int arr[20];
  print_paths(T, arr, 0);
  leftmost_path(T);
  rightmost_path(T);
  print_min_max_path(T, arr);
  path_sum(T, arr, 0, 22);
  print_max_even_odd(T, arr);
  return 0;
}

