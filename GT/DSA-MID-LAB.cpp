#include<bits/stdc++.h>
using namespace std;

// STRUCTURE OF GENERAL TREE
struct gtnode {
  struct gtnode *fc;
  int data;
  struct gtnode *ns;
};

struct node {
  int data;
  struct node *next;
};

typedef struct node *lptr;
typedef struct gtnode *gtptr;

// FUNCTION TO CREATE A NEW GENERAL TREE NODE
gtptr new_gtnode(int n){
  gtptr T = new(gtnode);
  T->data = n;
  T->fc = T->ns = NULL;
  return T;
}

// FUNCTION TO CREATE A GENERAL TREE
void create_gt(gtptr &GT, int n){
  int num;
  if(GT == NULL){
    GT = new_gtnode(n);
  } 
  cin>>num;
  if(num != -1) create_gt(GT->fc, num);
  cin>>num;
  if(num != -1) create_gt(GT->ns, num);
}

// FUNCTION TO FIND THE NUMBER OF NODES IN A HEAP ORDERED-SUBSET S WITH ROOT GT
void create_heap(gtptr GT, int last, int &num){
  if(GT->data > last){
    num++;
    last = GT->data;
  } 
  gtptr p = GT->fc;
  while(p != NULL){
    create_heap(p, last, num);
    p = p->ns;
  }
}

// FUNCTION TO PRINT THE PREORDER OF THE HEAP ROOTED AT GT
void preorder_heap(gtptr GT, int last){
  if(GT->data > last){
    cout<<GT->data<<" ";
    last = GT->data;
  } 
  gtptr p = GT->fc;
  while(p != NULL){
    preorder_heap(p, last);
    p = p->ns;
  }
}


// FUNCTION TO FIND THE HEAP-ORDERED SUBSET WHICH HAS MAXIMUM NODES
void find_num(gtptr GT, int &max, gtptr &P) {
  int num = 0;
  if(GT){
    gtptr p = GT->fc;
    while(p != NULL){
      num = 0;
      if(p->data < GT->data){
        create_heap(p, 0, num);
        if(max < num) {
          max = num;
          P = p;
        }
        find_num(p, max, P);
      }
      p = p ->ns;
    }
  }
}


// FUNCTION TO FIND THE MAX HEAP-ORDERED SUBSET AND PRINT ITS PREORDER
void find_largest(gtptr GT){
  int num=0;
  int max=INT_MIN;
  gtptr P;
  create_heap(GT, 0, num);
  if(max < num) {
    max = num;
    P = GT;
  }
  find_num(GT, max, P);
  cout<<"The preorder of the largest Heap formed is: ";
  preorder_heap(P, 0);
}


// FUNCTION TO PRINT LEVEL ORDER OF A GENERAL TREE
void print_level(gtptr GT){
  queue<gtptr> Q;
  Q.push(GT);
  gtptr T = new(gtnode);
  T->data = -1;
  T->fc = T->ns = NULL;
  Q.push(T);
  while(true){
    gtptr B = Q.front();
    Q.pop();
    if(Q.empty()){
      break;
    }
    if(B->data == -1){
      cout<<endl;
      Q.push(B);
    } else {
      gtptr p = B;
      while(p != NULL){
        cout<<p->data<<" ";
        if(p->fc) Q.push(p->fc);
        p = p->ns;
      }
    }
  }
}


// FUNCTION TO CREATE NEW NODE
lptr get_node(int x){
  lptr T = new(node);
  T->data =x;
  T->next = NULL;
  return T;
}


// FUNCTION TO CREATE A LINKED LIST
void insert_node(lptr &L, int x){
  if(L == NULL){
    L = get_node(x);
  } 
  cin>>x;
  if(x != -1)
    insert_node(L->next, x);
}


// FUNCTION TO FIND THE NUMBER OF NODES IN HEAP ORDERED SUBSET WITH ROOT L
void find_num_node(lptr L, int &num){
  int last = L->data;
  L = L->next;
  while(L != NULL){
    if(L->data > last){
      num++;
      last = L->data;
    }
    L = L->next;
  }
}


// FUNCTION TO FIND MAXIMUM HEAP ORDERED SUBSET IN L AND PRINT ITS PREORDER
void largest_heap(lptr L){
  int last=INT_MAX;
  int max = INT_MIN;
  lptr P;
  int num=0;
  while(L != NULL){
    num=0;
    if(L->data < last){
      find_num_node(L, num);
      if(max < num){ 
        last = L->data;
        max = num;
        P = L;
      }
    }
    L = L->next;
  }
  cout<<"The preorder of the Heap is: ";
  last = P->data;
  while(P != NULL){
    if(P->data >= last){
      last = P->data;
      cout<<P->data<<" ";
    }
    P = P->next;
  }
}

int main() {

  // GENERAL TREE
  gtptr GT=NULL;
  int n;
  cin>>n;
  create_gt(GT, n);    // CREATE A GENERAL TREE
  print_level(GT);     // LEVEL PRINTING
  cout<<endl;
  find_largest(GT);    // PRINTING PREORDER OF LARGEST HEAP-ORDERED SUBSET
  cout<<endl;
  // LINKED LIST
  lptr L = NULL;
  cin>>n;
  insert_node(L, n);  // CREATE A LINKED LIST
  largest_heap(L);    // PREORDER LARGEST HEAP
  return 0;
}


// INPUT FOR THE GENERAL TREE
// 3 1 9 3 2 -1 3 -1 -1 -1 -1 4 2 5 -1 8 8 -1 4 2 -1 7 -1 9 -1 -1 -1 9 6 -1 -1 -1 -1 1 -1 5 5 7 -1 9 -1 3 -1 -1 6 -1 -1 -1 -1

// EXPECTED OUTPUT
// 3
// 1 4 1 5
// 9 2 5 6
// 3 5 8 9 7 9 3
// 2 3 8 4 6
// 2 7 9
// The preorder of the largest Heap formed is: 3 9 4 5 8 9 9 5 7 9 6


// INPUT FOR LINKED LIST
// 7 5 1 2 3 4 8 9 -1

// EXPECTED OUTPUT
// The preorder of the Heap is: 1 2 3 4 8 9