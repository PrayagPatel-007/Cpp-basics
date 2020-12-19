#include<bits/stdc++.h>
using namespace std;

#define mat vector<vector<int>>
#define vect vector<int>
#define vect_b vector<bool>

void add_edge(mat &V, int u, int v){
  V[u][v] = 1;
}

void DFS(mat &V, int x, vect &num, vect &low, vect &SCC){
  static int t=0;
  num[x] = low[x] = t++;
  SCC.push_back(x);
  for(int i=0; i<V.size(); i++){
    if(V[x][i]){
      if(num[i] == -1){
        DFS(V, i, num, low, SCC);
        low[x] = min(low[x], low[i]);
      } else{
        if(find(SCC.begin(), SCC.end(), i) != SCC.end())
        low[x] = min(low[x], num[i]);
      }
    }
  }
  if(low[x] == num[x]) {
    for(int i=SCC.size()-1; i>=0; i--){
      if(SCC[i] == x){
        cout<<SCC[i]<<endl;
        SCC.pop_back();
        break;
      } else {
        cout<<SCC[i]<<" ";
        SCC.pop_back();
      }
    }
  }
}


int main(){
  int n=11;
  mat V(n, vect(n, 0));
  vect num(n, -1), low(n, 0);
  add_edge(V, 1,2);
  add_edge(V,1,4);
  add_edge(V,4,5);
  add_edge(V,3,1);
  add_edge(V,3,4);
  add_edge(V,3,5);
  add_edge(V,2,3);
  add_edge(V,2,6);
  add_edge(V,6,3);
  add_edge(V,7,6);
  add_edge(V,7,8);
  add_edge(V,8,6);
  add_edge(V,9,8);
  add_edge(V,8,10);
  add_edge(V,10,9);
  vect SCC;
  for(int i=1; i<n; i++){
    if(num[i] == -1){
      DFS(V, i, num, low, SCC);
    }
  }
  return 0;
}