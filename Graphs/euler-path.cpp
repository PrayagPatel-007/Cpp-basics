#include<bits/stdc++.h>
using namespace std;

#define mat vector<vector<int>>
#define vect vector<int>
#define vect_b vector<bool>

struct node {
  int data;
  struct node *next;
};

typedef struct node *lptr;

void insert_node(lptr &T, int k){
  if(T == NULL){
    T = new(node);
    T->data = k;
    T->next = NULL;
  } else {
    insert_node(T->next, k);
  }
}

void add_edge(mat &V, int u, int v, vect &D){
  V[u][v] = 1;
  V[v][u] = 1;
  D[u]++;
  D[v]++;
}

void remove_edge(mat &V, int u, int v, vect &D){
  V[u][v] = 0;
  V[v][u] = 0;
  D[u]--;
  D[v]--;
}

int find_deg(lptr L, vect D){
  if(L == NULL){
    return 1;
  } else {
    lptr p = L;
    while(p){
      if(D[p->data] > 0) {
        return p->data;
      }
      p = p->next;
    }
    return -1;
  }
}

void DFS(mat &V, int x, vect &D, lptr &T, bool &flag){
  insert_node(T, x);
  if(D[x] == 0){
    flag = false;
    return;
  }
  for(int i=1; i<V.size(); i++){
    if(V[x][i] == 1 && flag){
      remove_edge(V, x, i, D);
      DFS(V, i, D, T, flag);
    }
  }
}

void add_end(lptr &P, lptr t){
  if(P == NULL){
    P = t;
  } else {
    add_end(P->next, t);
  }
}

void splice(lptr &T, int k, lptr &P){
  if(T == NULL) {
    T = P;
  } else if (T->next->data == k) {
    add_end(P, T->next->next);
    T->next = P;
    return;
  } else {
    splice(T->next, k, P);
  }
}

lptr euler_path(mat &V, vect &D){
  lptr T = NULL;
  while(find_deg(T, D) != -1){
    int k = find_deg(T, D);
    lptr P = NULL;
    bool flag = true;
    DFS(V, k, D, P, flag);
    splice(T, k, P);
  }
  return T;
}

int main(){
  int n = 13;
  mat V(n, vect(n, 0));
  vect D(n, 0);
  add_edge(V, 1,3, D);
  add_edge(V,1,4, D);
  add_edge(V,4,3, D);
  add_edge(V,3,2, D);
  add_edge(V,3,6, D);
  add_edge(V,3,9, D);
  add_edge(V,7,3, D);
  add_edge(V,4,7, D);
  add_edge(V,4,10, D);
  add_edge(V,4,11, D);
  add_edge(V,5,4, D);
  add_edge(V,5,10, D);
  add_edge(V,2,8, D);
  add_edge(V,8,9, D);
  add_edge(V,6,9, D);
  add_edge(V,7,9, D);
  add_edge(V,10,9, D);
  add_edge(V,10,7, D);
  add_edge(V,12,9, D);
  add_edge(V,10,11, D);
  add_edge(V,10,12, D);
  lptr T = euler_path(V, D);
  lptr p = T;
  while(p){
    cout<<p->data<<" ";
    p = p->next;
  }
  return 0;
}