#include<bits/stdc++.h>
using namespace std;

void fill_in_degree(vector<int> &In, vector<vector<int>> &V, int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(V[j][i] != INT_MAX){
        In[i]++;
      }
    }
  }
}

int find_0_indegree(vector<int> &In){
  for(int i=0; i<In.size(); i++){
    if(In[i] == 0) {
      return i;
    }
  }
  return -2;
}

void print_order(vector<vector<int>> &V, vector<int> &In, int x, vector<int> &D){
  for(int i=0; i<V.size(); i++){
    if(V[x][i] != INT_MAX){
      if(D[i] < D[x] + V[x][i]){
        D[i] = D[x] + V[x][i];
      }
    }
  }
  In[x] = -1;
  for(int i=0; i<In.size(); i++){
    if (V[x][i] != INT_MAX) {
      In[i]--;
    }
  }
  if(find_0_indegree(In) == -2) return;
  print_order(V, In, find_0_indegree(In), D);
}

int main(){
  int n;
  n = 8;
  vector<vector<int>> V(n, vector<int> (n, INT_MAX));
  V[7][5] = -4;
  V[7][3] = 4;
  V[7][0] = 6;
  V[7][1] = -1;
  V[5][1] = 2;
  V[3][0] = 3;
  V[3][4] = 5;
  V[0][6] = 2;
  V[1][6] = 8;
  V[1][4] = 1;
  V[1][2] = -4;
  vector<int> In(n, 0);
  vector<int> D(n, INT_MIN);
  fill_in_degree(In, V, n);
  int S = find_0_indegree(In);
  D[S] = 0;
  In[S] = -1;
  print_order(V, In, S, D);
  for(int i=0; i<n; i++){
    if(i != S){
      if(D[i] == INT_MIN) cout<<-1<<" ";
      else cout<<D[i]<<" ";
    } 
  }
  return 0;
}