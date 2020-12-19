#include<bits/stdc++.h>
using namespace std;

struct gtnode {
  struct gtnode *fc;
  char data;
  struct gtnode *ns;
};

typedef gtnode *gtptr;

gtptr new_gtnode(char c){
  gtptr T = new(gtnode);
  T->data = c;
  T->fc = T->ns = NULL;
  return T;
}

void create_gt(queue<gtptr> Q){
  if(Q.empty()) return;
  char c;
  int n;
  cin>>c>>n;
  gtptr T = Q.front();
  Q.pop();
  T->data = c;
  int i=n;
  if(i > 0) {
    T->fc = new_gtnode('#');
    Q.push(T->fc);
    i--;
  }
  gtptr C = T->fc;
  while(i > 0){
    C->ns = new_gtnode('#');
    Q.push(C->ns);
    i--;
    C = C->ns;
  }
  create_gt(Q);
}

void print_serialised(gtptr GT){
  if(GT){
    cout<<GT->data;
    if(!GT->fc) cout<<".";
    else print_serialised(GT->fc);
    if(!GT->ns) cout<<".";
    else print_serialised(GT->ns);
  }
}

int main(){
  gtptr GT = new_gtnode('#');
  queue<gtptr> GQ;
  GQ.push(GT);
  create_gt(GQ);
  print_serialised(GT);
  return 0;
}

// A 3 B 3 F 2 J 4 C 0 D 0 E 0 G 0 H 0 K 0 L 0 M 2 N 0 P 0 Q 0