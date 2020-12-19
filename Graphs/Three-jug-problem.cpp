#include<bits/stdc++.h>
using namespace std;

struct triplet {
  int x, y, z;
};

void func(bool V[624][624], int x, int y, int z, queue<triplet> &Q, triplet S[624], int &i, int &n, vector<vector<vector<bool>>> &MAT){
  Q.push({x, y, z});
  S[n++] = {x, y, z};
  V[i-1][n-1] = true;
  MAT[x][y][z] = true;
}

int three_jug (bool V[624][624], triplet S[624], vector<vector<vector<bool>>> &MAT){
  queue<triplet> Q;
  int n = 0;
  triplet T = {12, 0, 0};
  S[n++] = T;
  int X=12, Y=7, Z=5;
  Q.push(T);
  MAT[8][0][0] = true;
  int i=1;
  while(true){
    triplet t = Q.front();
    Q.pop();
    if(i == 480){
      return i;
    }
    if(t.x > 0){
      if(t.y < Y){
        int m = min(t.x, Y - t.y);
        if(!MAT[t.x-m][t.y+m][t.z]){
          func(V, t.x-m, t.y+m, t.z, Q, S, i, n, MAT);
        }
      }
      if(t.z < Z){
        int m = min(t.x, Z - t.z);
        if(!MAT[t.x-m][t.y][t.z+m]){
          func(V, t.x-m, t.y, t.z+m, Q, S, i, n, MAT);
        }
      }
      if(!MAT[0][t.y][t.z]){
        func(V, 0, t.y, t.z, Q, S, i, n, MAT);
      }
    }
    if(t.y > 0){
      if(t.x < X){
        int m = min(t.y, X - t.x);
        if(!MAT[t.x+m][t.y-m][t.z]){func(V, t.x+m, t.y-m, t.z, Q, S, i, n, MAT);}
      }
      if(t.z < Z){
        int m = min(t.y, Z - t.z);
        if(!MAT[t.x][t.y-m][t.z+m]){func(V, t.x, t.y-m, t.z+m, Q, S, i, n, MAT);}
      }
      if(!MAT[t.x][0][t.y]){
        func(V, t.x, 0, t.z, Q, S, i, n, MAT);
      }
    }
    if(t.z > 0){
      if(t.x < X){
        int m = min(t.z, X - t.x);
        if(!MAT[t.x+m][t.y][t.z-m]){
          func(V, t.x+m, t.y, t.z-m, Q, S, i, n, MAT);
        }
      }
      if(t.y < Y){
        int m = min(t.z, Y - t.y);
        if(!MAT[t.x][t.y+m][t.z-m]){
          func(V, t.x, t.y+m, t.z-m, Q, S, i, n, MAT);
        }
      }
      if(!MAT[t.x][t.y][0]){
        func(V, t.x, t.y, 0, Q, S, i, n, MAT);
      }
    }
    if(t.x < X){
      if(!MAT[X][t.y][t.z]){
        func(V, X, t.y, t.z, Q, S, i, n, MAT);
      }
    }
    if(t.y < Y){
      if(!MAT[t.x][Y][t.z]){
        func(V, t.x, Y, t.z, Q, S, i, n, MAT);
      }
    }
    if(t.z < Z){
      if(!MAT[t.x][t.y][Z]){
        func(V, t.x, t.y, Z, Q, S, i, n, MAT);
      }
    }
    i++;
  }
}

void print(vector<int> &Edges, bool V[624][624], int x){
  if(x == 0) return;
  for(int i=0; i<624; i++){
    if(V[i][x]){
      Edges.push_back(i);
      print(Edges, V, i);
    }
  }
}

int main(){
  bool V[624][624];
  for(int i=1; i<624; i++){
    for(int j=1; j<624; j++){
      V[i][j] = false;
    }
  }
  vector<vector<vector<bool>>> MAT(13, vector<vector<bool>>(8, vector<bool>(6, false)));
  triplet S[624];
  int m = three_jug(V, S, MAT)-1;
  vector<int> Edges;
  Edges.push_back(m);
  print(Edges, V, m);
  reverse(Edges.begin(), Edges.end());
  for(auto x : Edges){
    cout<<S[x].x<<" "<<S[x].y<<" "<<S[x].z<<endl;
  }
}