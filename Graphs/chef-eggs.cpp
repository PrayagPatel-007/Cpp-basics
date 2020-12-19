#include<bits/stdc++.h>
using namespace std;

#define mat vector<vector<int>>
#define vect vector<int>
#define vect_b vector<bool>

void add_edge(mat &V, int u, int v){
  V[u][v] = 1;
}

void fill_in_degree(vector<int> &In, vector<vector<int>> &V, int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(V[j][i]==1){
        In[i]++;
      }
    }
  }
}

void find_min_time(mat &V, vect &In, vect_b &visited){
  for(int i=1; i<In.size(); i++){
    if(In[i] == 0){
      cout<<(char)(i+64)<<" ";
    }
  }
  vect in_0;
  for(int i=1; i<In.size(); i++){
    if(In[i] == 0) {
      In[i] = -1;
      in_0.push_back(i);
    }
  }
  if(in_0.empty()) return;
  for(auto x : in_0){
    for(int j=1; j<V.size();j++){
      if(V[x][j]){
        In[j]--;
      }
    }
  }
  find_min_time(V, In, visited);
}

int main(){
  int n;
  n = 10;
  mat V(n, vect(n, 0));
  vect In(n, 0);
  vect_b visited(n, false);
  add_edge(V, 1, 2);
  add_edge(V, 2, 3);
  add_edge(V, 3, 4);
  add_edge(V, 4, 5);
  add_edge(V, 6, 8);
  add_edge(V, 8, 9);
  add_edge(V, 9, 3);
  fill_in_degree(In, V, n);
  In[7] = INT_MAX;
  find_min_time(V, In, visited);
  return 0;
}