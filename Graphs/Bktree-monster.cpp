#include<bits/stdc++.h>
using namespace std;

struct Bknode {
  string s;
  struct Bknode *ptr[15] = {NULL};
};

typedef struct Bknode *Bkptr;

int min(int a, int b, int c){
  int min = (b<c) ? b : c;
  min = (min < a)? min : a;
  return min;
}

int difference(string s1, string s2){
  int m = s1.length();
  int n = s2.length();
  int arr[m+1][n+1];
  for(int j=0; j<=n; j++){
    arr[0][j] = j;
  }
  for(int j=0; j<=m; j++){
    arr[j][0] = j;
  }
  for(int j=1; j<=m; j++){
    for(int k=1; k<=n; k++){
      if(s1[j-1] != s2[k-1]) {
        arr[j][k] = 1 + min(arr[j-1][k], arr[j][k-1], arr[j-1][k-1]);
      } else {
        arr[j][k] = arr[j-1][k-1];
      }
    }
  }
  return arr[m][n];
}

void insert_bk(Bkptr &T, string s){
  if(T == NULL){
    T = new(Bknode);
    T->s = s;
  } else {
    int diff = difference(T->s, s);
    insert_bk(T->ptr[diff], s);
  }
}

void search(vector<string> &V, string key, int N, Bkptr T){
  if(T){
    int D = difference(T->s, key);
    if(D == N) V.push_back(T->s);
    int i = D-N+1;
    if(i < 0) i = 0;
    for(int j=i; j<=D+N; j++){
      search(V, key, N, T->ptr[j]);
    }
  }
}

void search_all(Bkptr T){
  if(T){
    cout<<T->s<<endl;
    for(int i=1; i<10; i++){
      vector<string> V;
      search(V, T->s, i, T);
      if(V.size()){
        cout<<i<<" ";
        for(auto x : V){
          cout<<x<<" ";
        } cout<<endl;
      }
    }
    for(int i=0; i<15; i++){
      search_all(T->ptr[i]);
    }
  }
}

int main(){
  Bkptr T = NULL;
  string s;
  cin>>s;
  while (s != "#")
  {
    insert_bk(T, s);
    cin>>s;
  }
  search_all(T);
  return 0;
}

// some same soft mole soda salmon #