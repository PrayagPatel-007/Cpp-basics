#include<bits/stdc++.h>
using namespace std;

struct tnode{
  bool wrd = false;
  struct tnode *ptr[36] = {NULL};
};

typedef struct tnode *Tptr;

// Insert in trie function
void insert_trie(Tptr &T, string s, int i=0){
  if(T == NULL){
    T = new(tnode);
  }
  if(i == s.length()){
    T->wrd = true;
  }
  if(i >= s.length()) return;
  insert_trie(T->ptr[s[i]-'a'], s, i+1);
}

// Print possible words that start with arr[i][j]
void print_possible_words(Tptr T, char arr[][4], int i, int j, char ar[], int index=0){
  if(i < 0 || j >= 4) return;
  if(arr[i][j] != '#' &&  T->ptr[arr[i][j] - 'a']){   // # is for visited path
    char c = arr[i][j];
    ar[index] = c;
    arr[i][j] = '#';
    index++;
    if(T->ptr[c - 'a']->wrd) {
      for(int x=0; x<index; x++){
        cout<<ar[x];
      } cout<<endl;
    }
    print_possible_words(T->ptr[c - 'a'], arr, i+1, j, ar, index);
    print_possible_words(T->ptr[c - 'a'], arr, i, j+1, ar, index);
    print_possible_words(T->ptr[c - 'a'], arr, i-1, j, ar, index);
    print_possible_words(T->ptr[c - 'a'], arr, i, j-1, ar, index);
    arr[i][j] = c;     // backtrack
  } else {
    return;
  }
}

// traverse through whole board and find possible words
void find_words(Tptr T, char arr[][4]){
  char ar[10];
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      print_possible_words(T, arr, i, j, ar);
    }
  }
}

int main(){
  // Since the input format was not given I have taken an example input directly through initialisation
  // However It can also be taken from user
  char arr[4][4] = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
  string s;
  Tptr T = NULL;
  cin>>s;
  while(s != "#"){
    insert_trie(T, s);
    cin>>s;
  }
  find_words(T, arr);   // Function to print all possible words
  return 0;
}

// INPUT
// oath oa eat pea rain #
