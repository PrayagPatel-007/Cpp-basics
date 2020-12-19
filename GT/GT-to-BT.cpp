#include<bits/stdc++.h>
using namespace std;

struct gtnode {
  struct gtnode *fc;
  char data;
  struct gtnode *ns;
  bool flag=false;
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

void gt_to_bt(gtptr GT){
  if(GT){
    GT->flag = true;
    cout<<GT->data;
    gtptr p1 = NULL, p2 = NULL;
    gtptr p = GT->fc;
    while(p != NULL && !p->flag){
      if (p1 == NULL) p1 = p;
      else p2 = p;
      p = p->ns;
    }
    gt_to_bt(p1);
    gt_to_bt(p2);
  } else {
    cout<<".";
  }
}

int main() {
  gtptr GT = NULL;
  char c;
  cin>>c;
  create_gt(GT, c);
  gt_to_bt(GT);
  return 0;
}

// A B F I . J . . S K . . H . . C . D L M . N . . P . Q . . E  . . .