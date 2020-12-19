#include<bits/stdc++.h>
using namespace std;

int min(int x, int y){
  return (x < y) ? x : y;
}

int build_st(int S[], int A[], int i, int l, int r){
  if(l == r){
    S[i] = A[l];
    return S[i];
  } else {
    int mid = (l+r)/2;
    S[i] = min(build_st(S, A, 2*i+1, l, mid), build_st(S, A, 2*i+2, mid+1, r));
    return S[i];
  }
}

int get_min(int S[], int i, int l, int r, int Sl, int Sr){
  if(l>=Sl && r<=Sr){
    return S[i];
  } else if(Sr<l || Sl>r) {
    return INT_MAX;
  } else {
    int mid = (l+r)/2;
    return min(get_min(S, 2*i+1, l, mid, Sl, Sr), get_min(S, 2*i+2, mid+1, r, Sl, Sr));
  }
}

void update(int S[], int A[], int n, int i, int l, int r, int index){
  if(index >= l && index <= r){
    if(l == r) S[i] = n;
    else {
      int mid = (l+r)/2;
      update(S, A, n, 2*i+1, l, mid, index);
      update(S, A, n, 2*i+2, mid+1, r, index);
      S[i] = min(S[2*i+1], S[2*i+2]);
    }
  } else {
    return;
  }
}

void print_ranges(int S1[], int S2[], int n1, int n2){
  int high = (n1 < n2) ? n1 : n2;
  for(int l=0; l<high-1; l++){
    for(int r=l+1; r<high; r++){
      int x = get_min(S1, 0, 0, n1-1, l, r);
      int y = get_min(S2, 0, 0, n2-1, l, r);
      if(x == y) cout<<l<<" "<<r<<endl;
    }
  }
}

int main(){
  int A1[20], A2[20], S1[50], S2[50];
  int n1, n2;
  cin>>n1;
  for(int i=0; i<n1; i++){
    cin>>A1[i];
  }
  cin>>n2;
  for(int i=0; i<n2; i++){
    cin>>A2[i];
  }
  build_st(S1, A1, 0, 0, n1-1);
  build_st(S2, A2, 0, 0, n2-1);
  print_ranges(S1, S2, n1, n2);
  return 0;
}

// 7 3 4 1 7 11 2 10 7 15 3 10 2 11 4 18