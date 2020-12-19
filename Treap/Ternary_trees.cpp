#include<bits/stdc++.h>
using namespace std;

struct tnode {
  struct tnode *lc = NULL;
  char data;
  struct tnode *ep = NULL;
  struct tnode *rc = NULL;
  bool flag=false;
};

typedef struct tnode *tptr;

void insert(tptr &T, string s, int i=0){
  if(i < s.length()){
    char c = s[i];
    if(T == NULL){
      T = new(tnode);
      T->data = c;
      if(i == s.length() - 1) T->flag = true;
      insert(T->ep, s, i+1);
    } else {
      if(T->data == c) {
        if(i == s.length() -1)
          T->flag = true;
        insert(T->ep, s, i+1);
      }
      else if(T->data > c) insert(T->lc, s, i);
      else insert(T->rc, s, i);
    }
  }
}

bool search(tptr T, string s, int i=0){
  if(i >= s.length()) return false;
  if(T){
    char c = s[i];
    if(T->data == c && i == s.length()-1 && T->flag) return true;
    if(T->data == c) return search(T->ep, s, i+1);
    else if(T->data > c) return search(T->lc, s, i); 
    else return search(T->rc, s, i); 
  } else {
    return false;
  }
}

int main() {
  tptr T = NULL;
  string s;
  for(int i=0; i<3; i++){
    cin>>s;
    insert(T,s);
  }
  for(int i=0; i<2; i++){
    cin>>s;
    cout<<search(T, s)<<endl;
  }
  return 0;
}