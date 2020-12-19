#include<bits/stdc++.h>
using namespace std;

struct hnode {
  struct hnode *lchild;
  pair<int, char> data;
  struct hnode *rchild; 
};

typedef struct hnode *hptr;

struct cmp {
  bool operator()(hnode *T1, hnode *T2){
    if(T1->data.first == T2->data.first) {
      return T1->data.second < T2->data.second;
    }
    return T1->data.first < T2->data.first;
  }
};

// hptr max_element(vector<hptr> A){
//   hptr min = A[0];
//   for(int i=0; i<A.size(); i++){
//     if (min->data.first > A[i]->data.first){
//       min = A[i];
//     }
//   }
//   return min;
// }

// hptr huffman_encoder(vector<hptr> A){
//   if(A.size() == 1) return A[0];
//   hptr h1, h2;
//   h1 = max_element(A);
//   vector<hptr>::iterator it;
//   it = find(A.begin(), A.end(), h1);
//   A.erase(it);
//   h2 = max_element(A);
//   it = find(A.begin(), A.end(), h2);
//   A.erase(it);
//   hptr T = new(hnode);
//   T->data.second = '#';
//   T->data.first = h1->data.first + h2->data.first;
//   T->lchild = h2;
//   T->rchild = h1;
//   A.push_back(T);
//   return huffman_encoder(A);
// }

hptr huffman_encoder(set<hptr, cmp> A){
  if(A.size() == 1) return *A.begin();
  hptr h1, h2;
  h1 = *A.begin();
  A.erase(h1);
  h2 = *A.begin();
  A.erase(h2);
  hptr T = new(hnode);
  T->data.second = '#';
  T->data.first = h1->data.first + h2->data.first;
  T->lchild = h2;
  T->rchild = h1;
  A.insert(T);
  return huffman_encoder(A);
}

void print_arr(int arr[], int n){
  for(int i=0; i<n; i++){
    cout<<arr[i];
  }
}

void hoffman_encode(hptr T, hptr T1, string s, int i, int arr[], int lastIndex){
  if(T == NULL) return;
  if(i == s.length()) return;
  if(s[i] == T->data.second) {
    print_arr(arr, lastIndex);
    hoffman_encode(T1, T1, s, i+1, arr, 0);
  } else {
    arr[lastIndex] = 0;
    hoffman_encode(T->lchild, T1, s, i, arr, lastIndex+1);
    arr[lastIndex] = 1;
    hoffman_encode(T->rchild, T1, s, i, arr, lastIndex+1);
  }
}

void huffman_decoder(hptr T, hptr T1, string s, int i){
  if(T == NULL) return;
  if(T->lchild == NULL && T->rchild == NULL) {
    cout<<T->data.second;
    huffman_decoder(T1, T1, s, i);
    return;
  }
  if (s[i] == '0') huffman_decoder(T->lchild, T1, s, i+1);
  else if (s[i] == '1') huffman_decoder(T->rchild, T1, s, i+1);
}

int main(){
  hptr H = NULL;
  vector<hptr> v;
  set<hptr, cmp> S;
  int n;
  char c;
  cin>>c;
  while(c != '#'){
    hptr T = new(hnode);
    T->data.second = c;
    cin>>n;
    T->data.first = n;
    T->lchild = NULL;
    T->rchild = NULL;
    S.insert(T);
    cin>>c;
  }
  H = huffman_encoder(S);
  int arr[30];
  string s = "sepn";
  hoffman_encode(H, H, s, 0, arr, 0);
  s = "111000011111";
  huffman_decoder(H, H, s, 0);
  return 0;
}

// a 10 e 15 s 3 t 4 p 13 n 1 #