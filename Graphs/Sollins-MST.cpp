#include <bits/stdc++.h>
using namespace std;

#define mat vector<vector<int>>
#define vect vector<int>
#define vect_b vector<bool>


void add_edge(int u, int v, int w, mat &V)
{
  V[u][v] = w;
  V[v][u] = w;
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

bool all_together(vect &S){
  for(int i=1; i<S.size(); i++){
    if(S[i] == -1){
      return false;
    }
  }
  return true;
}

int min_adj(mat &V, int u, mat &S){
  int min = INT_MAX;
  int min_num;
  for(int v=1; v<V.size(); v++){
    if(V[u][v] != INT_MAX && min > V[u][v] && Find(u, S) != Find(v, S)){
      min = V[u][v];
      min_num = v;
    }
  }
  return min_num;
}

mat sollin(mat &V, int n, vector<pair<int, int>> &Edges)
{
  mat S;
  while(!all_together(S)){
    for(int i=1; i<V.size(); i++){
      int v = min_adj(V, i, S);
      Union(i, v, S);
      Edges.push_back({i, v});
      add_edge(i, v, V[i][v], V_new);
    }
  }
  return V_new;
}

int main()
{
  int n;
  n = 8;
  mat V(n, vect(n, INT_MAX));
  vector<pair<int, int>> Edges;
  add_edge(1, 2, 2, V);
  add_edge(1, 3, 4, V);
  add_edge(1, 4, 1, V);
  add_edge(2, 4, 2, V);
  add_edge(3, 4, 2, V);
  add_edge(4, 5, 7, V);
  add_edge(4, 6, 8, V);
  add_edge(4, 7, 4, V);
  add_edge(3, 6, 5, V);
  add_edge(6, 7, 1, V);
  add_edge(5, 7, 6, V);
  add_edge(2, 5, 10, V);
  vect S(n, -1);
  mat V_new = sollin(V, S, n, Edges);
  cout << "MST consists of following edges: \n";
  for (auto x : Edges)
  {
    cout << x.first << " " << x.second << endl;
  }
  return 0;
}