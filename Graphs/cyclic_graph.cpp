#include<bits/stdc++.h>
using namespace std;

#define mat vector<vector<int>>
#define vect vector<int>

void DFS(mat &V, vector<bool> &Visit, int x){
  Visit[x] = true;
  for(int i=1; i<V.size(); i++){
    if(V[x][i] == 1) {
      cout<<"("<<x<<", "<<i<<") ";
      if(!Visit[i]) DFS(V, Visit, i);
    }
  }
}

void BFS(mat &V, vector<bool> Visit, int x){
  queue<int> Q;
  Q.push(x);
  while(!Q.empty()){
    int i = Q.front();
    Visit[i] = true;
    Q.pop();
    for(int j=1; j<V.size(); j++){
      if(V[i][j] == 1){
        cout<<"("<<i<<", "<<j<<") ";
      }
      if(V[i][j] == 1 && Visit[j] == false){
        Q.push(j);
      }
    }
  }
}

void simple_DFS(mat &V, vector<bool> &Visit, int x){
  Visit[x] = true;
  for(int i=1; i<V.size(); i++){
    if(V[x][i] == 1 && !Visit[i]){
      simple_DFS(V, Visit, i);
    }
  }
}

bool is_connected(mat &V, vector<bool> &Visit){
  simple_DFS(V, Visit, 1);
  for(int i=1; i<V.size(); i++){
    if(!Visit[i]){
      return false;
    }
  }
  return true;
}

void path_print(mat &V, vector<bool> &Visit, int path[], int S, int g, int index=0){
  Visit[S] = true;
  path[index] = (S);
  index++;
  if(S == g){
    for(int i=0; i<index; i++){
      cout<<path[i]<<" ";
    }cout<<endl;
    return;
  } 
  for(int i=1; i<V.size(); i++){
    if(V[S][i] == 1 && !Visit[i]){
      path_print(V, Visit, path, i, g, index);
    }
  }
}

int main(){
  int n;
  cin>>n;
  mat V(n+1, vect (n+1, 0));
  int u, v;
  cin>>u;
  while(u != 0){
    cin>>v;
    V[u][v] = 1;
    V[v][u] = 1;
    cin>>u;
  }
  vector<bool> Visit(n+1, false);
  int path[30];
  DFS(V, Visit, 1);
  fill(Visit.begin(), Visit.end(), false);
  path_print(V, Visit, path, 1, 5);
  return 0;
}