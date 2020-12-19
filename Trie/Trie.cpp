#include<bits/stdc++.h>
using namespace std;

struct tnode{
  bool wrd = false;
  struct tnode *ptr[36] = {NULL};
};

typedef struct tnode *Tptr;

void insert_trie(Tptr &T, string s, int i=0){
  if(T == NULL){
    T = new(tnode);
    if(i == s.length()){
      T->wrd = true;
    }
  }
  if(i >= s.length()) return;
  if(s[i] >= 48 && s[i] <= 57) {
    insert_trie(T->ptr[s[i]-'0'+26], s, i+1);
  } else
    insert_trie(T->ptr[s[i]-'a'], s, i+1);
}

// bool search(Tptr T, string s, int i=0){
//   if(i >= s.length() && T->wrd) return true;
//   if(T->ptr[s[i]-'a']){
//     return search(T->ptr[s[i]-'a'], s, i+1);
//   } else {
//     return false;
//   }
// }

void print(Tptr T, char arr[], int index){
  if(T){
    if(T->wrd) {
      for(int j=0; j<index; j++){
        cout<<arr[j];
      }cout<<endl;
    }
    for(int i=0; i<26; i++){
      if(T->ptr[i]){
        arr[index] = (char)(i+'a');
        print(T->ptr[i], arr, index+1);
      }
    }
    for(int i=26; i<36; i++){
      if(T->ptr[i]){
        arr[index] = (char)(i+'0'-26);
        print(T->ptr[i], arr, index+1);
      }
    }
  } 
}

int main(){
  Tptr T = NULL;
  string s;
  while(true){
    cin>>s;
    if(s[s.length()-1] == '#') {
      s.pop_back();
      insert_trie(T, s);
      break;
    } else {
      insert_trie(T, s);
    }
  }
  char arr[40];
  print(T, arr, 0);
  return 0;
}

// abd5c2 ac8b9 bd367a cdd294a1 da5b4c63 #
// abd5c2 ac8b9 bd367a cdd294a1 da5b4c63#