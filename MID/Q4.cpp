#include<bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node *next;
};

typedef struct node *lptr;

int find_point(lptr L1, lptr L2){
  while(L2 != NULL){
    lptr p=L1;
    while(p != NULL){
      if(L2 == p) return L2->data;
      p=p->next;
    }
    L2=L2->next;
  }
}

void print_arr(string arr[], int n){
  for(int i=0; i<n; ++i){
    cout<<arr[i]<<" ";
  }
}

void print(lptr L1, lptr L2, lptr L3, lptr L4){
  int x2 = find_point(L1, L2);
  int x3 = find_point(L1, L3);
  int x4 = find_point(L1, L4);
  string arr[10];
  int i=1;
  arr[0]="L1";
  while(L1 != NULL){
    if(L1->data == x2 || L1->data == x3 || L1->data == x4){
      if(L1->data == x2){
        cout<<"L2 meets ";
        print_arr(arr, i);
        cout<<"at "<<x2<<"\n";
        arr[i] = "L2";
        i++;
      } else if(L1->data == x3){
        cout<<"L3 meets ";
        print_arr(arr, i);
        cout<<"at "<<x3<<"\n";
        arr[i] = "L3";
        i++;
      } else if(L1->data == x4){
        cout<<"L4 meets ";
        print_arr(arr, i);
        cout<<"at "<<x4<<"\n";
        arr[i] = "L4";
        i++;
      }
    }
    L1=L1->next;
  }
}

void insert(lptr &L, int n){
  if(L == NULL){
    L = new(node);
    L->data = n;
    L->next = NULL;
  } else {
    insert(L->next, n);
  }
}

lptr find_node(lptr L, int n){
  while(L!= NULL){
    if(L->data == n){
      return L;
    }
    L=L->next;
  }
}

void add_last(lptr &L, lptr k){
  if(L->next == NULL){
    L=k;
  }else{
    add_last(L->next, k);
  }
}

void print_ll(lptr L){
  if(L != NULL){
    cout<<L->data<<" ";
    print_ll(L->next);
  }
}

int main(){
  lptr L1=NULL, L2=NULL, L3=NULL, L4=NULL;
  int n;
  cin>>n;
  while(n != -1){
    insert(L1, n);
    cin>>n;
  }
  int last=0;
  cin>>n;
  while(n != -1){
    insert(L2, n);
    last=n;
    cin>>n;
  }
  add_last(L2, find_node(L1, last));
  last=0;
  cin>>n;
  while(n != -1){
    insert(L3, n);
    last=n;
    cin>>n;
  }
  add_last(L3, find_node(L1, last));
  last=0;
  cin>>n;
  while(n != -1){
    insert(L4, n);
    last=n;
    cin>>n;
  }
  add_last(L4, find_node(L1, last));
  print(L1, L2, L3, L4);
  return 0;
}

// 1 2 3 5 8 27 9 36 72 -1 15 45 10 36 -1 6 18 5 -1 4 12 25 27 -1