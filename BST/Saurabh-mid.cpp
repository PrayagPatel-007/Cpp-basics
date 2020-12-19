#include<bits/stdc++.h> 
using namespace std; 

void addEdge(vector<int> adj[], int u, int v, vector<int> &I) 
{ 
	adj[u].push_back(v); 
  I[v]++;
} 

void Display_edges(vector<int> adj[], int V) 
{ 
	for (int v = 0; v < V; ++v) 
	{ 
		for (auto x : adj[v]) {
		  cout << v <<" "<< x <<endl; 
    }
	} 
} 

int find_0_indegree(vector<int> I){
  for(int i=1; i<I.size(); i++){
    if(I[i] == 0){
      return i;
    }
  }
}

int find_lca(vector<int> adj[], int x, int u, int arr[], int index=0){
  arr[index++] = x;
  if(x == u){
    return index;
  } else {
    for(int v : adj[x]){
      return find_lca(adj, v, u, arr, index);
    }
  }
}

void find_all(vector<int> adj[], int n){
  int arr1[100];
  int arr2[100];
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      int n1 = find_lca(adj, 0, i, arr1);
      int n2 = find_lca(adj, 0, j, arr2);
      bool flag = false;
      for(int x=n1-1; x>=0; x--){
        for(int y=n2-1; y>=0; y--){
          if(arr1[x] == arr2[y]){
            cout<<i<<" "<<j<<" "<<arr1[x]<<endl;
            flag = true;
            break;
          }
        }
        if(flag) break;
      }
    }
  }
}

int main() 
{ 
	int V = 5; 
	vector<int> adj[V]; 
  vector<int> I(V, 0);
	addEdge(adj, 0, 1, I); 
	addEdge(adj, 0, 4, I); 
	addEdge(adj, 0, 2, I); 
	addEdge(adj, 1, 3, I); 
	Display_edges(adj, V); 
  find_all(adj, 5);
	return 0; 
} 
