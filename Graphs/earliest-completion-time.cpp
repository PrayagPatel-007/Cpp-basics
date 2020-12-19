#include<bits/stdc++.h>
using namespace std;

void fill_in_degree(vector<int> &In, vector<vector<double>> &V, int n){
  for(int i=1; i<n; i++){
    for(int j=0; j<n; j++){
      if(V[j][i] >= 0)
      In[i]++;
    }
  }
}

void fill_out_degree(vector<int> &Ou, vector<vector<double>> &V, int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(V[i][j] >= 0)
      Ou[i]++;
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

void print_order(vector<vector<double>> &V, vector<int> &In, int x, vector<double> &Time){
  In[x] = -1;
  for(int i=1; i<In.size(); i++){
    if (V[i][x] >= 0){
      double k = Time[i] + V[i][x];
      Time[x] = (Time[x] < k) ? k : Time[x];
    }
  }
  for(int i=1; i<In.size(); i++){
    if (V[x][i] >= 0) {
      In[i]--;
    }
  }
  if(find_0_indegree(In) == -2) return;
  print_order(V, In, find_0_indegree(In), Time);
}

int find_0_outdegree(vector<int> &Ou){
  for(int i=0; i<Ou.size()-1; i++){
    if(Ou[i] == 0){
      return i;
    }
  }
  return -2;
}

int main(){
  int n, m;
  n = 8;
  vector<vector<double>> V(n+1, vector<double> (n+1, -1));
  vector<double> W(n+1, 0);
  m = 8;
  W[1] = 3.1;
  W[2] = 2.0;
  W[3] = 4.6;
  W[4] = 1.8;
  W[5] = 0.3;
  W[6] = 4;
  W[7] = 3.7;
  V[1][3] = W[1];
  V[1][5] = W[1];
  V[2][5] = W[2];
  V[3][4] = W[3];
  V[3][6] = W[3];
  V[5][6] = W[5];
  V[4][7] = W[4];
  V[6][7] = W[6];
  vector<int> In(n+1, 0);
  vector<int> Ou(n+1, 0);
  vector<double> Time(n+1, 0);
  fill_in_degree(In, V, n);
  fill_out_degree(Ou, V, n);
  while(find_0_indegree(In) != -2 && find_0_indegree(In) != n){
    V[0][find_0_indegree(In)] = 0;
    Ou[0]++;
    In[find_0_indegree(In)]++;
  }
  while(find_0_outdegree(Ou) != -2 && find_0_outdegree(Ou) != 0){
    V[find_0_outdegree(Ou)][n] = W[find_0_outdegree(Ou)];
    In[n]++;
    Ou[find_0_outdegree(Ou)]++;
  }
  print_order(V, In, 0, Time);
  cout<<Time[n];
  return 0;
}
