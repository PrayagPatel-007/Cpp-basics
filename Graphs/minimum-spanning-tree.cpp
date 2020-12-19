#include<bits/stdc++.h>
using namespace std;

void add(vector<vector<int>> &V, int u, int v, int w){
  V[u][v] = w;
  V[v][u] = w;
}

pair<int, pair<int, int>> find_min(vector<vector<int>> &V, vector<int> &Visit){
  int min = INT_MAX;
  int id1 = INT_MAX, id2;
  for(int i=1; i<V.size(); i++){
    if(Visit[i]) {
      for(int j=1; j<V.size(); j++){
        if(V[i][j] > 0 && !Visit[j]) {
          if(min > V[i][j]) {
            min = V[i][j];
            id1 = i;
            id2 = j;
          }
        }
      }
    }
  }
  return {min, {id1, id2}};
}

bool all_visited(vector<int> &Visit){
  for(int i=1; i<Visit.size(); i++){
    if(Visit[i] == 0) return false;
  }
  return true;
}

void dijsktra(vector<vector<int>> &V, vector<int> &Visit){
  int curr = 1;
  int sum=0;  
  vector<pair<int, int>> pairs;
  while(!all_visited(Visit)){
    Visit[curr] = 1;
    curr = find_min(V, Visit).second.second;
    if(find_min(V, Visit).second.first != INT_MAX){
      sum += find_min(V, Visit).first;
      pairs.push_back(find_min(V, Visit).second);
    }
  }
  for(auto x : pairs) {
    cout<<x.first<<" "<<x.second<<endl;
  }
  cout<<sum;
}

int main(){
  int n;
  n = 8;
  vector<vector<int>> V(n, vector<int> (n, 0));
  vector<int> Visit(n, 0), D(n, INT_MAX), prev(n, 0);
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
  dijsktra(V, Visit);
  return 0;
}