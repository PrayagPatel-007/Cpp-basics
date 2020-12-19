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

int kruskal(mat &V, vect &S, int n, vector<pair<int, int>> &Edges, vector<edge> &Graph_Edges)
{
  int i = 0;
  int index = 0;
  int sum = 0;
  int u, v;
  sort(Graph_Edges.begin(), Graph_Edges.end(), comp);
  while (i < n - 2)
  {
    u = Graph_Edges[index].u;
    v = Graph_Edges[index].v;
    if (Find(u, S) != Find(v, S))
    {
      Union(u, v, S);
      sum += V[u][v];
      i++;
      Edges.push_back({u, v});
    }
    index++;
  }
  return sum;
}

int main()
{
  int n;
  n = 8;
  mat V(n, vect(n, INT_MAX));
  vector<pair<int, int>> Edges;
  vector<edge> Graph_Edges;
  add_edge(1, 2, 2, V, Graph_Edges);
  add_edge(1, 3, 4, V, Graph_Edges);
  add_edge(1, 4, 1, V, Graph_Edges);
  add_edge(2, 4, 2, V, Graph_Edges);
  add_edge(3, 4, 2, V, Graph_Edges);
  add_edge(4, 5, 7, V, Graph_Edges);
  add_edge(4, 6, 8, V, Graph_Edges);
  add_edge(4, 7, 4, V, Graph_Edges);
  add_edge(3, 6, 5, V, Graph_Edges);
  add_edge(6, 7, 1, V, Graph_Edges);
  add_edge(5, 7, 6, V, Graph_Edges);
  add_edge(2, 5, 10, V, Graph_Edges);
  vect S(n, -1);
  cout << "Sum: " << kruskal(V, S, n, Edges, Graph_Edges) << endl;
  cout << "MST consists of following edges: \n";
  for (auto x : Edges)
  {
    cout << x.first << " " << x.second << endl;
  }
  return 0;
}