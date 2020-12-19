#include<bits/stdc++.h>
using namespace std;

#define mat vector<vector<int>>
#define vect vector<int>
#define vect_b vector<bool>

void AT_DT(mat &V, vect &AT, vect &DT, int &last, int x, vect_b &visited){
  AT[x] = last;
  visited[x] = true;
  last++;
  for(int i=0; i<V.size(); i++){
    if(V[x][i] == 1 && !visited[i])
      AT_DT(V, AT, DT, last, i, visited);
  }
  DT[x] = last;
  last++;
}

bool all_visited(vect_b &visited){
  for(int i=0; i<visited.size(); i++){
    if(visited[i] == false) return false;
  }
  return true;
}

void AT_DT_unconnected(mat &V, vect &AT, vect &DT, int &last, vect_b &visited){
  while(!all_visited(visited)){
    for(int i=0; i<visited.size(); i++){
      if(visited[i] == false) AT_DT(V, AT, DT, last, i, visited);
    }
  }
}

void print_atdt(vect &AT, vect &DT){
  for(int i=0; i<AT.size(); i++){
    cout<<i<<" "<<AT[i]<<" "<<DT[i]<<endl;
  }
}

int main(){
  int n, m;
  cin>>n>>m;
  mat V(n, vect(n, 0));
  int u, v;
  for(int i=0; i<m; i++){
    cin>>u>>v;
    V[u][v] = 1;
  }
  vect AT(n), DT(n);
  vect_b visited(n, false);
  int last = 0;
  AT_DT_unconnected(V, AT, DT, last, visited);
  print_atdt(AT, DT);
  return 0;
}