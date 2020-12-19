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

void max_bends(btptr T, bool left, int i, int &max, int arr[]){
  if(T != NULL){
    if(max <= i){
      max = i;
      arr[T->data] = i;
    }
    if (left) {
      max_bends(T->lchild, true, i, max, arr);
      max_bends(T->rchild, false, i+1, max, arr);
    } else {
      max_bends(T->rchild, false, i, max, arr);
      max_bends(T->lchild, true, i+1, max, arr);
    }
  }
}

void print_bend_path(btptr T, int max, int arr1[], int arr2[], int lastIndex){
  if(T != NULL){
    arr2[lastIndex] = T -> data;
    lastIndex++;
    if (arr1[T->data] == max){
      // j = lastIndex - max - 2 for the start of the bend subsequence
      for(int i=0; i<lastIndex; i++){
        cout<<arr2[i]<<" ";
      }cout<<endl;
      return;
    }
    print_bend_path(T->lchild, max, arr1, arr2, lastIndex);
    print_bend_path(T->rchild, max, arr1, arr2, lastIndex);
  }
}

int main(){
  btptr T = NULL;
  int n;
  cin>>n;
  insert(T, n);
  int max=INT_MIN;
  int arr[20] = {0};
  int arr2[30];
  max_bends(T->lchild, true, 0, max, arr);
  max_bends(T->rchild, false, 0, max, arr);
  print_bend_path(T, max, arr, arr2, 0);
  return 0;
}
