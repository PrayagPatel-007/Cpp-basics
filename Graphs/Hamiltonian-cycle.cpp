#include<bits/stdc++.h>
using namespace std;

#define mat vector<vector<int>>
#define vect vector<int>
#define vect_b vector<bool>

bool in_arr(int arr[], int n, int m){
  for(int i=0; i<n; i++){
    if(arr[i] == m){
      return false;
    }
  }
  return true;
}

void find_cycle(mat &V, int path[], int index){
  if(index == V.size()) {
    if(V[path[index-1]][path[0]] == 1){
      return;
    }
  }
  for(int i=2; i<V.size(); i++){
    for(int j=1; j<V.size(); j++){
      if(V[i][j]){
        if(!in_arr(path, index, j)){
          path[index] = j;
          find_cycle(V, path, index+1);
        }
      }
    }
  }
}

void ham_cycle(mat &V){
  int path[100];
  path[0] = 1;
  find_cycle(V, path, 1);
  for(auto x : path){
    cout<<path[x]<<" ";
  }
}

int main(){
  int n;
  mat V(n, vect(n, 0));
  ham_cycle(V);
  return 0;
}