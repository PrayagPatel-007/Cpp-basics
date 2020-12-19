#include<bits/stdc++.h>
using namespace std;

struct gtnode {
  struct gtnode *fc;
  char data;
  struct gtnode *ns;
  int n_c=0;
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

int calc_nc(gtptr GT){
  if(GT->fc == NULL) return 1;
  int sum=1;
  gtptr p = GT->fc;
  while(p != NULL){
    p->n_c = calc_nc(p);
    sum+= p->n_c;
    p = p->ns;
  }
  GT->n_c = sum;
  return GT->n_c;
}

void count_min_time(gtptr GT, int &max, int i=0){
  if(GT){
    if(max < i) max = i;
    gtptr p = GT->fc;
    int maximum = INT_MIN;
    gtptr max_ptr = NULL;
    while(p != NULL){
      if(maximum < p->n_c && !p->flag) {
        maximum = p->n_c;
        max_ptr = p;
      }
      p = p->ns;
    }
    if(max_ptr != NULL) {
      max_ptr->flag = true;
      count_min_time(max_ptr, max, i+1);
      count_min_time(GT, max, i+1);
    }
  }
}

int main() {
  gtptr GT = NULL;
  char c;
  cin>>c;
  create_gt(GT, c);
  calc_nc(GT);
  int max = INT_MIN;
  count_min_time(GT, max);
  cout<<max;
  return 0;
}

// A B H N . O . . I . J . . C . D . E K P . . L Q . . . F . G M . . . .
// A B . C D . . . .