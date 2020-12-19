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

void print_path(vector<int> &prev, int S, int g, vector<vector<int>> &V){
  if(g !=  S){
    print_path(prev, S, prev[g], V);
  }
  if(g == S) {
    cout<<g<<" ";
  } else {
    cout<<"<--"<<V[prev[g]][g]<<"--> "<<g<<" ";
  }
}

void dijsktra(vector<vector<int>> &V, vector<int> &Visit, vector<int> &D, vector<int> &prev, int S, int g){
  D[S] = 0;
  int curr = S;
  while(curr != g){
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
  cout<<D[curr]<<endl;
  print_path(prev, S, g, V);
}

int main(){
  int n;
  cin>>n;
  vector<vector<int>> V(n+1, vector<int> (n+1, 0));
  vector<int> Visit(n+1, 0), D(n+1, INT_MAX), prev(n+1, 0);
  int u, v, w;
  cin>>u;
  while(u != 0){
    cin>>v>>w;
    V[u][v] = w;
    cin>>u;
  }
  int S, g;
  cin>>S>>g;
  dijsktra(V, Visit, D, prev, S, g);
  return 0;
}

// 7   
// 1 2 2
// 1 4 1
// 2 5 10
// 2 4 3
// 4 3 2
// 4 6 8
// 4 7 4
// 4 5 2
// 3 1 4
// 3 6 5
// 5 7 6
// 7 6 1
// 0
// 1 6