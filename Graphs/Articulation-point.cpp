#include<bits/stdc++.h>
using namespace std;

#define mat vector<vector<int>>
#define vect vector<int>
#define vect_b vector<bool>

void add_edge(mat &V, int u, int v){
  V[u][v] = 1;
  V[v][u] = 1;
}

void DFS(mat &V, int x, vect &num, vect &low, vect &p, vect_b &art_pt, vector<pair<int, int>> &bridges){
  static int t=0;
  num[x] = low[x] = t++;
  int dfsc = 0;
  for(int i=0; i<V.size(); i++){
    if(V[x][i]){
      if(num[i] == -1){
        dfsc++;
        p[i] = x;
        DFS(V, i, num, low, p, art_pt, bridges);
        low[x] = min(low[x], low[i]);
        if(p[x] == -1 && dfsc > 1){
          art_pt[x] = true;
        }
        if(p[x] != -1 && low[i] >= num[x]){
          art_pt[x] = true;
        }
        if(low[i] > num[x]){
          bridges.push_back({x, i});
        }
      } else if (i != p[x]){
        low[x] = min(low[x], num[i]);
      }
    }
  }
}

int main(){
  int n;
  n = 9;
  mat V(n, vect(n, 0));
  vect num(n, -1), low(n, 0), p(n, -1);
  vect_b art_pt(n, false);
  vector<pair<int, int>> Bridges;
  add_edge(V, 0, 1);
  add_edge(V, 0, 2);
  add_edge(V, 2, 1);
  add_edge(V, 2, 3);
  add_edge(V, 4, 3);
  add_edge(V, 2, 5);
  add_edge(V, 6, 5);
  add_edge(V, 6, 7);
  add_edge(V, 8, 5);
  add_edge(V, 8, 7);
  DFS(V, 0, num, low, p, art_pt, Bridges);
  for(int i=0; i< art_pt.size(); i++){
    if(art_pt[i]){
      cout<<i<<" ";
    }
  }
  cout<<endl;
  for(auto x : Bridges){
    cout<<x.first<<" "<<x.second<<endl;
  }
  return 0;
}