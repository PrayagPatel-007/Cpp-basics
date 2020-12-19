#include<bits/stdc++.h>
using namespace std;

#define mat vector<vector<bool>>
#define vect vector<int>
#define vect_b vector<bool>

void add_edge(mat &V, vect &D, int u, int v){  // add edge to graph
  V[u][v] = true;
  V[v][u] = true;
  D[v]++;
  D[u]++;
}

void remove_edge(mat &V, vect &D, int u, int v){  // remove edge from graph
  V[u][v] = false;
  V[v][u] = false;
  D[v]--;
  D[u]--;
}


//remove adjacent vertices to the given vertices
void remove_adj_edges(mat &V, vect &D, int u, vect_b &removed_vertices){   
  for(int i=1; i<V.size(); i++){
    if(V[u][i] && !removed_vertices[i]){
      remove_edge(V, D, u, i);
      removed_vertices[i] = true;
    }
  }
}

// find maximum degree in the left vertices
int find_max_degree(vect &D, vect_b &removed_vertices){
  int max = INT_MIN, max_num = INT_MIN;
  for(int i=D.size()-1; i>=0; i--){
    if(!removed_vertices[i] && max < D[i]){
      max = D[i];
      max_num = i;
    }
  }
  return max_num;
}


// return true if there are no vertices left
bool all_removed(vect_b &removed_vertices){
  for(int i=1; i<removed_vertices.size(); i++){
    if(!removed_vertices[i]){
      return false;
    }
  }
  return true;
}


// prints the dominating set
void find_ds(mat &V, vect &D){
  vect_b removed_vertices(V.size(), false);
  while(!all_removed(removed_vertices)){
    int x = find_max_degree(D, removed_vertices);
    removed_vertices[x] = true;
    remove_adj_edges(V, D, x, removed_vertices);
    cout<<(char)(x+96)<<" ";
  }
}

int main(){
  int n=7;
  mat V(n, vector<bool>(n, false));
  vect D(n, 0);
  add_edge(V, D, 1, 2);
  add_edge(V, D, 3, 2);
  add_edge(V, D, 1, 5);
  add_edge(V, D, 2, 5);
  add_edge(V, D, 3, 4);
  add_edge(V, D, 4, 5);
  add_edge(V, D, 3, 6);
  cout<<"{ ";
  find_ds(V, D);
  cout<<"}";
  return 0;
}

/*
INPUT GRAPH
     b -- c -- f
   / |   |
 a --e---d
*/