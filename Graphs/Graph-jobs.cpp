#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<vector<int>> &V, int u, int v){
  V[u][v] = 1;
}

void fill_in_degree(vector<int> &In, vector<vector<int>> &V, int n){
  for(int i=1; i<n; i++){
    for(int j=1; j<n; j++){
      In[i] += V[j][i];
    }
  }
}

int find_0_indegree(vector<int> &In){
  for(int i=1; i<In.size(); i++){
    if(In[i] == 0) {
      return i;
    }
  }
  return -2;
}

void print_order(vector<vector<int>> &V, vector<int> &In, int x){
  cout<<x<<" ";
  In[x] = -1;
  for(int i=1; i<In.size(); i++){
    if (V[x][i] == 1) {
      In[i]--;
    }
  }
  if(find_0_indegree(In) == -2) return;
  print_order(V, In, find_0_indegree(In));
}

int main(){
  int n;
  cin>>n;
  vector<vector<int>> V(n+1, vector<int> (n+1, 0));
  int u, v;
  cin>>u;
  while(u != 0){
    cin>>v;
    add_edge(V, u, v);
    cin>>u;
  }
  vector<int> In(n+1, 0);
  fill_in_degree(In, V, n+1);
  print_order(V, In, find_0_indegree(In));
  return 0;
}

// Topological Sort