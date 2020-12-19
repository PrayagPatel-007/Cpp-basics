#include<bits/stdc++.h>
using namespace std;

#define mat vector<vector<int>>
#define vect vector<int>
#define vect_b vector<bool>

void print_cycle(int path[], int i, int x, int n){
  bool flag = false;
  for(int j=0; j<n; j++){
    if(path[j] == i){
      flag = true;
    }
    if(flag) cout<<path[j]<<" ";
    if(path[j] == x) {
      flag = false;
    }
  }
}

void detect_cycles(mat &V, vect_b visited, int x, int path[], int index, int &n){
  visited[x] = true;
  path[index] = x;
  index++;
  for(int i=1; i<V.size(); i++){
    if(V[x][i]){
      if(visited[i]) {
        print_cycle(path, i, x, index);
        n++;
        cout<<i<<endl;
      } else {
        detect_cycles(V, visited, i, path, index, n);
      }
    }
  }
}

int main() {
  int n, m;
  cin>>n>>m;
  mat V(n+1, vect(n+1, 0));
  int u, v;
  for(int i=0; i<m; i++){
    cin>>u>>v;
    V[u][v] = 1;
  }
  vect_b visited(n+1, false);
  int path[40];
  n=0;
  detect_cycles(V, visited, 1, path, 0, n);
  cout<<n;
  return 0;
}

/*
6 8 
1 2
2 3
2 4
3 4 
4 5
1 5
5 6
6 1
*/