#include<bits/stdc++.h>
using namespace std;

struct stack_ {
  int top;
  int size;
  struct node *elements[50];
};

struct node {
  char data;
  struct node *next;
};

typedef struct node *lptr;

void push(struct stack_ &S, lptr L){
  if(S.top == S.size - 1) cout<<"Stack Full";
  else{
    S.top = S.top + 1;
    S.elements[S.top] = L;
  }
}

lptr pop(struct stack_ &S){
  if(S.top == -1) cout<<"Stack Empty!";
  else {
    lptr T = S.elements[S.top];
    S.top--;
    return T;
  }
}

void print_ll(lptr L){
  if(L != NULL){
    cout<<L->data<<" ";
    print_ll(L->next);
  }
}

void insert(lptr &L, char c) {
  if(L == NULL) {
    L = new(node);
    L->next = NULL;
    L->data = c;
  } else {
    insert(L->next, c);
  }
}

int main() {
  char c;
  struct stack_ S;
  S.top=-1;
  S.size=20;
  cin>>c;
  while(c != '*'){
    lptr L=NULL;
    while(c != '#'){
      insert(L, c);
      cin>>c;
    }
    push(S, L);
    cin>>c;
  }
  while(S.top != -1){
    lptr T = pop(S);
    print_ll(T);
    cout<<endl;
  }
  return 0;
}

// a b c d # g h i j k # k b # r t s a m f # *