#include<bits/stdc++.h>
using namespace std;

union u {
  struct tnode *ptr[4] = {NULL};
  struct tlnode *strptr;
};


struct tnode {
  bool flag=true;
  union u cptr;
};

typedef struct tnode *Tptr;

struct tlnode {
  string s;
};

typedef struct tlnode *Tlptr;

Tptr make_str_node(string s){
  Tptr T = new(tnode);
  T->flag=false;
  T->cptr.strptr = new(tlnode);
  T->cptr.strptr->s = s;
  return T; 
}

void insert_trie(Tptr &T, string s, int i=0){
  if(i >= s.length()){
    T->cptr.ptr[3] = make_str_node(s);
    return;
  }
  if(T->cptr.ptr[s[i]-'A'] == NULL){
    T->cptr.ptr[s[i]-'A'] = make_str_node(s);
    return;
  } else {
    Tptr P = T->cptr.ptr[s[i]-'A'];
    if(!P->flag) {
      Tptr N = new(tnode);
      N->cptr.ptr[P->cptr.strptr->s[i+1]-'A'] = P;
      T->cptr.ptr[s[i]-'A'] = N;
    }
    insert_trie(T->cptr.ptr[s[i]-'A'], s, i+1);
  }
}

void print_sort(Tptr T){
  if(T->flag==false){
    cout<<T->cptr.strptr->s<<" ";
    return;
  }
  for(int i=0; i<4; i++){
    if(T->cptr.ptr[i])
      print_sort(T->cptr.ptr[i]);
  }
}

int main(){
  Tptr T = new(tnode);
  string s;
  cin>>s;
  while(s != "#"){
    insert_trie(T, s);
    cin>>s;
  }
  print_sort(T);
  return 0;
}

// AAB CABB BAA ABBBC BCCCAA BC A ABB #