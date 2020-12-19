#include<bits/stdc++.h>
using namespace std;

struct dlnode {
  struct dlnode *left;
  int data;
  struct dlnode *right;
};

typedef struct dlnode *dlptr;

void create_dll (dlptr &D){
    int n;
    char c;
    cin>>c;
    if(c != '#'){
        n = c-'0';
        if(D == NULL){
            D = new(dlnode);
            D -> data = n;
            D -> left = NULL;
            D -> right = NULL;
            create_dll(D);
        } else {
            dlptr T = new(dlnode);
            T -> data = n;
            T -> left = D;
            T -> right = NULL;
            D -> right = T;
            create_dll(T);
        }
    }
}

void insert_left(dlptr &D, int n){
  if(D == NULL){
    D = new(dlnode);
    D->right=NULL;
    D->left=NULL;
    D->data=n;
  } else {
    dlptr T = new(dlnode);
    T -> left = NULL;
    T -> right = D;
    T -> data = n;
    D -> left = T;
    D = T;
  }
}

void add_ (dlptr D1, dlptr D2, dlptr &D3, int carry){
  if(D1 != NULL && D2 != NULL){
    int sum = D1->data + D2->data + carry;
    carry=sum/10;
    sum=sum%10;
    insert_left(D3, sum);
    add_(D1->left, D2->left, D3, carry);
  } else if (D1 == NULL && D2 != NULL) {
    int sum = D2->data + carry;
    carry=sum/10;
    sum=sum%10;
    insert_left(D3, sum);
    add_(D1, D2->left, D3, carry);
  } else if (D1 != NULL && D2 == NULL){
    int sum = D1->data + carry;
    carry=sum/10;
    sum=sum%10;
    insert_left(D3, sum);
    add_(D1->left, D2, D3, carry);
  } else if(carry != 0) {
    int sum =carry;
    sum=sum%10;
    insert_left(D3, sum);
    return;
  } else {
    return;
  }
}

dlptr last_node(dlptr D){
    if(D == NULL){
        return D;
    }
    if(D->right == NULL){
        return D;
    }
    last_node(D->right);
}

void print(dlptr D){
  if(D != NULL){
    cout<<D->data;
    print(D->right);
  }
}

int main(){
  dlptr D1 = NULL, D2 = NULL, D3= NULL;
  create_dll(D1);
  create_dll(D2);
  add_(last_node(D1), last_node(D2), D3, 0);
  print(D3);
  return 0;
}