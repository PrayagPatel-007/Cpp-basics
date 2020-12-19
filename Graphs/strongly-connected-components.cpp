#include<bits/stdc++.h>
using namespace std;

#define mat vector<vector<int>>
#define vect vector<int>
#define vect_b vector<bool>

void add_edge(mat &V, int u, int v){
  V[u][v] = 1;
}

void transpose(mat &V){
  for(int i=1; i<V.size(); i++){
    for(int j=1; j<i; j++){
      swap(V[i][j], V[j][i]);
    }
  }
}

void post_order(mat &V, vect &post, vect_b &visited, int x, int &last){
  visited[x] = true;
  for(int i=1; i<V.size(); i++){
    if(V[x][i] == 1 && !visited[i]){
      post_order(V, post, visited, i, last);
    }
  }
  post[x] = last;
  last++;
}

int find_unvisited(vect_b &visited){
  for(int i=1; i<visited.size(); i++){
    if(!visited[i]){
      return i;
    }
  }
  return -1;
}

int maxim(vect post, vect_b &visited){
  int max = INT_MIN;
  int max_num = INT_MIN;
  for(int i=1; i<post.size(); i++){
    if(!visited[i] && max < post[i]){
      max = post[i];
      max_num = i;
    }
  }
  return max_num;
}

void simple_DFS(mat &V, vector<bool> &Visit, int x){
  Visit[x] = true;
  cout<<x<<" ";
  for(int i=1; i<V.size(); i++){
    if(V[x][i] == 1 && !Visit[i]){
      simple_DFS(V, Visit, i);
    }
  }
}

void DFS(mat &V, vect &post, vect_b &visited){
  while(maxim(post, visited) != INT_MIN){
    simple_DFS(V, visited, maxim(post, visited));
    cout<<endl;
  }
}

int main(){
  int n;
  n = 11;
  mat V(n, vect(n, 0));
  vect_b visited(n, false);
  vect post(n, 0);
  int last=1;
  add_edge(V, 1,2);
  add_edge(V,1,4);
  add_edge(V,4,5);
  add_edge(V,3,1);
  add_edge(V,3,4);
  add_edge(V,3,5);
  add_edge(V,2,3);
  add_edge(V,2,6);
  add_edge(V,6,3);
  add_edge(V,7,6);
  add_edge(V,7,8);
  add_edge(V,8,6);
  add_edge(V,9,8);
  add_edge(V,8,10);
  add_edge(V,10,9);
  post_order(V, post, visited, 2, last);
  post_order(V, post, visited, 7, last);
  transpose(V);
  fill(visited.begin(), visited.end(), false);
  DFS(V, post, visited);
  return 0;
}