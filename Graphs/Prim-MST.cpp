#include <bits/stdc++.h>
using namespace std;

#define mat vector<vector<int>>
#define vect vector<int>
#define vect_b vector<bool>

void add(mat &V, int u, int v, int w)
{
  V[u][v] = w;
  V[v][u] = w;
}

int smallest(vect &D, vect_b &visited)
{
  int min = INT_MAX, min_num;
  for (int i = 1; i < D.size(); i++)
  {
    if (!visited[i] && min > D[i])
    {
      min = D[i];
      min_num = i;
    }
  }
  return min_num;
}

bool all_visited(vect_b &visited)
{
  for (int i = 1; i < visited.size(); i++)
  {
    if (!visited[i])
      return false;
  }
  return true;
}

void find_prim_mst(mat &V, vect_b &visited, vect &D, vect &prev)
{
  int sum = 0;
  vector<pair<int, int>> Edges;
  int curr = 1;
  while (!all_visited(visited))
  {
    visited[curr] = true;
    for (int i = 1; i < V.size(); i++)
    {
      if (!visited[i] && V[curr][i] > 0)
      {
        if (D[i] > V[curr][i])
        {
          D[i] = V[curr][i];
          prev[i] = curr;
        }
      }
    }
    if(prev[curr] != 0){
      sum += V[curr][prev[curr]];
      Edges.push_back({prev[curr], curr});
    }
    curr = smallest(D, visited);
  }
  cout << "Sum: " << sum << endl;
  cout << "MST consists of following edges: \n";
  for (auto x : Edges)
  {
    cout << x.first << " " << x.second << endl;
  }
}

int main()
{
  int n;
  n = 8;
  mat V(n, vect(n, 0));
  vect_b visited(n, false);
  vect D(n, INT_MAX), prev(n, 0);
  add(V, 1, 2, 2);
  add(V, 1, 4, 1);
  add(V, 1, 3, 4);
  add(V, 4, 2, 3);
  add(V, 4, 3, 2);
  add(V, 4, 6, 8);
  add(V, 4, 7, 4);
  add(V, 4, 5, 7);
  add(V, 3, 6, 5);
  add(V, 7, 6, 1);
  add(V, 7, 5, 6);
  add(V, 2, 5, 10);
  find_prim_mst(V, visited, D, prev);
  return 0;
}