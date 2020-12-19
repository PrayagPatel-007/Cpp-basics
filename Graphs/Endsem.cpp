#include<bits/stdc++.h>
using namespace std;

#define mat vector<vector<bool>>
#define vect vector<int>
#define SIZE 25                              //can work for other matrix size as well

struct path {                                // a graph vertex structure
  pair<int, int> coord;
  pair<int, int> vel;
  int parent=-1;
};


// a helper function to push the vertex into queue track the vertex and also have it in the main array S
void push_func(path S[1000], queue<path> &Q, bool track[SIZE][SIZE], int x, int y, int vx, int vy, int p, int &n){
  pair<int, int> coord = {x, y};
  pair<int, int> vel = {vx, vy};
  path T = {coord, vel, p};
  Q.push(T);
  S[n++] = T;
  track[x][y] = true;
}


// a helper function to have x and y valid
bool compare(int x, int y, bool track[SIZE][SIZE]){
  if(x < SIZE && x >= 0 && y < SIZE && y>= 0 && !track[x][y]){
    return true;
  }
  return false;
}


// the main function to find the path and construct the graph
int find_path (path S[1000], int y, int size, bool track[SIZE][SIZE]){
  queue<path> Q;
  pair<int, int> coord = {0, y};
  pair<int, int> vel = {0, 0};
  Q.push({coord, vel, -1});
  int n=0;
  S[n++] = {coord, vel, -1};
  track[0][y] = true;
  int i=0;
  while(!Q.empty()){
    int X = Q.front().coord.first;
    int Y = Q.front().coord.second;
    int Vx = Q.front().vel.first;
    int Vy = Q.front().vel.second;
    Q.pop();
    if(X == 24){
      return i;
    }
    if(compare(X+Vx+1, Y+Vy, track)){
      push_func(S, Q, track, X+Vx+1, Y+Vy, Vx+1, Vy, i, n);
    }
    if(compare(X+Vx-1, Y+Vy, track)){
      push_func(S, Q, track, X+Vx-1, Y+Vy, Vx-1, Vy, i, n);
    }
    if(compare(X+Vx, Y+Vy+1, track)){
      push_func(S, Q, track, X+Vx, Y+Vy+1, Vx, Vy+1, i, n);
    }
    if(compare(X+Vx, Y+Vy-1, track)){
      push_func(S, Q, track, X+Vx, Y+Vy-1, Vx, Vy-1, i, n);
    }
    if(compare(X+Vx+1, Y+Vy-1, track)){
      push_func(S, Q, track, X+Vx+1, Y+Vy-1, Vx+1, Vy-1, i, n);
    }
    if(compare(X+Vx+1, Y+Vy+1, track)){
      push_func(S, Q, track, X+Vx+1, Y+Vy+1, Vx+1, Vy+1, i, n);
    }
    if(compare(X+Vx-1, Y+Vy-1, track)){
      push_func(S, Q, track, X+Vx-1, Y+Vy-1, Vx-1, Vy-1, i, n);
    }
    if(compare(X+Vx-1, Y+Vy+1, track)){
      push_func(S, Q, track, X+Vx-1, Y+Vy+1, Vx-1, Vy+1, i, n);
    }
    i++;
  }
}


// using the S array making the vector of path coordinates
void print(path S[1000], int x, vector<path> &Path_coord){
  if(S[x].parent == -1){
    Path_coord.push_back(S[x]);
  } else {
    Path_coord.push_back(S[x]);
    print(S, S[x].parent, Path_coord);
  }
}

int main(){
  path S[1000];
  int y;
  cin>>y;
  bool track[SIZE][SIZE];
  for(int i=0; i<SIZE; i++){
    for(int j=0; j<SIZE; j++){
      track[i][j] = false;
    }
  }
  int m = find_path(S, y, SIZE, track);
  vector<path> Path_coord;
  print(S, m, Path_coord);
  reverse(Path_coord.begin(), Path_coord.end());
  for(auto x : Path_coord){
    cout<<x.coord.first<<" "<<x.coord.second<<"\t"<<x.vel.first<<" "<<x.vel.second<<endl;
  }
  return 0;
}