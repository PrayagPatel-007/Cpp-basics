#include<bits/stdc++.h>
using namespace std;

int min(int x, int y){
  return (x < y) ? x : y;
}

int max(int x, int y){
  return (x > y) ? x : y;
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

void print(int S[], int i, int l, int r){
  if(l == r){
    cout<<S[i]<<" ";
  } else {
    int mid = (l+r) / 2;
    print(S, 2*i+1, l, mid);
    print(S, 2*i+2, mid+1, r);
  }
}

int main(){
  int S[50] = {0}, A[10];
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>A[i];
  }
  build_st(S, A, 0, 0, n-1);
  int l, r;
  cout<<"Enter range (l - h) for min: ";
  cin>>l>>r;
  cout<<get_min(S, 0, 0, n-1, l, r)<<endl;
  int index, num;
  cout<<"Enter index and the new number: ";
  cin>>index>>num;
  update(S, A, num, 0, 0, n-1, index);
  A[index] = num;
  print(S, 0, 0, n-1);
  cout<<endl;
  cout<<"Enter range (l - h) for min: ";
  cin>>l>>r;
  cout<<get_min(S, 0, 0, n-1, l, r)<<endl;
  return 0;
}

// 9 1 5 8 3 2 6 9 7 4 1 5 3 67 1 3