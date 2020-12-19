#include<bits/stdc++.h>
using namespace std;

int smallest(vector<int> &D, vector<int> &Visit){
  int min = INT_MAX, min_num;
  for(int i=1; i<D.size(); i++){
    if(Visit[i] == 0 && min > D[i]){
      min = D[i];
      min_num = i;
    }
  }
  return min_num;
}

bool all_visited(vector<int> &Visit){
  for(int i=1; i<Visit.size(); i++){
    if(Visit[i] == 0) return false;
  }
  return true;
}

void dijsktra(vector<vector<int>> &V, vector<int> &Visit, vector<int> &D, vector<int> &prev, int S){
  D[S] = 0;
  int curr = S;
  while(!all_visited(Visit)){
    Visit[curr] = 1;
    for(int i=1; i<V.size(); i++){
      if(Visit[i] == 0 &&  V[curr][i] > 0) {
        if(D[i] > V[curr][i] + D[curr]){
          D[i] = V[curr][i] + D[curr];
          prev[i] = curr;
        }
      }
    }
    curr = smallest(D, Visit);
  }
}

int find_source(vector<vector<int>> &V, int n){
  for(int i=1; i<n; i++){
    int x=0;
    for(int j=0; j<n; j++){
      if(V[j][i] != INT_MAX)
      x++;
    } 
    if(x == 0) {
      return i;
    }
  }
}

int main(){
  int n;
  n = 8;
  vector<vector<int>> V(n+1, vector<int> (n, INT_MAX));
  vector<int> Visit(n, 0), D(n, INT_MAX), prev(n, 0);
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
  int S = find_source(V, n);
  dijsktra(V, Visit, D, prev, S);
  for(int i=0; i<n; i++){
    if(i != S){
      if(D[i] == INT_MAX) cout<<-1<<" ";
      else cout<<D[i]<<" ";
    } 
  }
  return 0;
}