#include <bits/stdc++.h>
using namespace std;

#define mat vector<vector<int>>
#define vect vector<int>
#define vect_b vector<bool>

struct edge
{
  int u;
  int v;
  int w;
};

void add_edge(int u, int v, int w, mat &V, vector<edge> &Graph_Edges)
{
  V[u][v] = w;
  V[v][u] = w;
  Graph_Edges.push_back({u, v, w});
}

int Find(int u, vector<int> &S)
{
  if (S[u] == -1)
  {
    return u;
  }
  else
    return Find(S[u], S);
}

void Union(int u, int v, vector<int> &S)
{
  if (S[u] == -1)
  {
    S[u] = v;
  }
  else if (S[v] == -1)
  {
    S[v] = u;
  }
  else
  {
    S[Find(v, S)] = Find(u, S);
  }
}

bool comp(edge a, edge b)
{
  return a.w < b.w;
}

void print_cycle(int path[100], int i, int x, int n, int &max, mat&V, int &u, int &v){
  bool flag = false;
  for(int j=0; j<n; j++){
    if(path[j] == i){
      flag = true;
    }
    if(path[j] == x) {
      if(max <= V[path[j]][i]){
        max = V[path[j]][i];
        u=path[j];
        v=i;
      }
      flag = false;
    }
    if(flag) {
      if(max < V[path[j]][path[j+1]]){
        max = V[path[j]][path[j+1]];
        u=path[j];
        v=path[j+1];
      }
    }
  }
}

void detect_cycles(mat &V, vect_b visited, int x, int path[100], int index, int &n, int &max, int &u, int &v, int prev){
  bool flag=false;
  for(int i=1; i<visited.size(); i++){
    if(visited[i] == false){
      flag=true;
    }
  }
  if(!flag) return;
  visited[x] = true;
  path[index] = x;
  index++;
  for(int i=1; i<V.size(); i++){
    if(V[x][i] != INT_MAX && i != prev){
      if(visited[i]) {
        print_cycle(path, i, x, index, max, V, u, v);
        n++;
      } else {
        detect_cycles(V, visited, i, path, index, n, max, u, v, x);
      }
    }
  }
}


void kruskal_a(mat &V, vector<edge> &GE, int num){
  int n=1;
  while(n != 0){
    n=0;
    vect_b visited(num, false);
    int path[100];
    int max = INT_MIN;
    int u, v;
    detect_cycles(V, visited, 4, path, 0, n, max, u, v, 0);
    V[u][v] = INT_MAX;
    V[v][u] = INT_MAX;
    for(int x=0; x<GE.size(); x++){
      if((GE[x].u == u && GE[x].v == v) || (GE[x].u == v && GE[x].v == u)){
        GE.erase(GE.begin()+x);
      }
    }
  }
}

int main()
{
  int n;
  n = 8;
  mat V(n, vect(n, INT_MAX));
  vector<pair<int, int>> Edges;
  vector<edge> Graph_Edges;
  add_edge(5, 7, 6, V, Graph_Edges);
  add_edge(4, 7, 4, V, Graph_Edges);
  add_edge(1, 2, 2, V, Graph_Edges);
  add_edge(3, 4, 2, V, Graph_Edges);
  add_edge(1, 4, 1, V, Graph_Edges);
  add_edge(6, 7, 1, V, Graph_Edges);
  add_edge(1, 3, 4, V, Graph_Edges);
  add_edge(2, 4, 2, V, Graph_Edges);
  add_edge(4, 5, 7, V, Graph_Edges);
  add_edge(4, 6, 8, V, Graph_Edges);
  add_edge(3, 6, 5, V, Graph_Edges);
  add_edge(2, 5, 10, V, Graph_Edges);
  kruskal_a(V, Graph_Edges, n);
  cout << "MST consists of following edges: \n";
  for (auto x : Graph_Edges)
  {
    cout << x.u << " " << x.v << endl;
  }
  return 0;
}