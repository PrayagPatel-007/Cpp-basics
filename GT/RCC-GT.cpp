#include<bits/stdc++.h>
using namespace std;

struct gtnode {
  struct gtnode *fc;
  char data;
  struct gtnode *ns;
};

typedef struct gtnode *gtptr;

gtptr new_gtnode(char c){
  gtptr T = new(gtnode);
  T->data = c;
  T->fc = T->ns = NULL;
  return T;
}

void create_gt(gtptr &GT, char c){
  char chr;
  if(GT == NULL){
    GT = new_gtnode(c);
  } 
  cin>>chr;
  if(chr != '.') create_gt(GT->fc, chr);
  cin>>chr;
  if(chr != '.') create_gt(GT->ns, chr);
}

void print_level(gtptr GT){
  queue<gtptr> Q;
  Q.push(GT);
  gtptr T = new(gtnode);
  T->data = '#';
  T->fc = T->ns = NULL;
  Q.push(T);
  while(true){
    gtptr B = Q.front();
    Q.pop();
    if(Q.empty()){
      break;
    }
    if(B->data == '#'){
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

void print_brackets(gtptr GT){
  if(GT){
    cout<<GT->data;
    if(GT->fc){
      cout<<"(";
      print_brackets(GT->fc);
      cout<<")";
    } 
    print_brackets(GT->ns);
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

int main() {
  gtptr GT = NULL;
  char c;
  cin>>c;
  create_gt(GT, c);
  // print_level(GT);
  // print_brackets(GT);
  print_serialised(GT);
  return 0;
}

// A B C . D . E . . F G .  H . . J K . L . M P . Q . . N . . . .