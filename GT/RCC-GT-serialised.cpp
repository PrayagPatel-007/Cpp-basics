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

void create_gt(gtptr GT){
  char c;
  int n;
  cin>>c>>n;
  GT->data = c;
  int i=n;
  if(i == 0) return;
  if(i > 0){
    GT->fc = new_gtnode('#');
    create_gt(GT->fc);
    i--;
  }
  gtptr C = GT->fc;
  while (i > 0){
    C->ns = new_gtnode('#');
    create_gt(C->ns);
    i--;
    C = C->ns;
  } 
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
  create_gt(GT);
  print_serialised(GT);
  return 0;
}

//  A 3 B 3 C 0 D 0 E 0 F 2 G 0 H 0 J 4 K 0 L 0 M 2 P 0 Q 0 N 0