#include<bits/stdc++.h>
using namespace std;

int build_st(int S[], int A[], int i, int l, int r){
  if(l == r){
    S[i] = A[l];
    return S[i];
  } else {
    int mid = (l+r)/2;
    S[i] = build_st(S, A, 2*i+1, l, mid) + build_st(S, A, 2*i+2, mid+1, r);
    return S[i];
  }
}

int get_sum(int S[], int i, int l, int r, int Sl, int Sr){
  if(l>=Sl && r<=Sr){
    return S[i];
  } else if(Sr<l || Sl>r) {
    return 0;
  } else {
    int mid = (l+r)/2;
    return get_sum(S, 2*i+1, l, mid, Sl, Sr) + get_sum(S, 2*i+2, mid+1, r, Sl, Sr);
  }
}

void update(int S[], int A[], int n, int i, int l, int r, int index){
  if(index >= l && index <= r){
    S[i] = S[i] + (n - A[index]);
    if(l != r){
      int mid = (l+r)/2;
      update(S, A, n, 2*i+1, l, mid, index);
      update(S, A, n, 2*i+2, mid+1, r, index);
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
  cout<<"Enter range (l - h) for sum: ";
  cin>>l>>r;
  cout<<get_sum(S, 0, 0, n-1, l, r)<<endl;
  int index, num;
  cout<<"Enter index and the new number: ";
  cin>>index>>num;
  update(S, A, num, 0, 0, n-1, index);
  A[index] = num;
  print(S, 0, 0, n-1);
  cout<<endl;
  return 0;
}

// 9 1 2 3 4 5 6 7 8 9 1 4 4 20