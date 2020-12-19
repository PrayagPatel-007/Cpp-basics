#include<bits/stdc++.h>
using namespace std;

struct all {
  int min;
  int max;
  float avg;
  int sum;
};

int min(int x, int y){
  return (x < y) ? x : y;
}

int max(int x, int y){
  return (x > y) ? x : y;
}

struct all build_st(struct all S[], int A[], int i, int l, int r){
  if(l == r){
    S[i].sum = A[l];
    S[i].min = A[l];
    S[i].max = A[l];
    S[i].avg = A[l];
    return S[i];
  } else {
    int mid = (l+r)/2;
    S[i].sum = build_st(S, A, 2*i+1, l, mid).sum + build_st(S, A, 2*i+2, mid+1, r).sum;
    S[i].avg = (float)S[i].sum / (float)(r-l+1);
    S[i].min = min(build_st(S, A, 2*i+1, l, mid).min, build_st(S, A, 2*i+2, mid+1, r).min);
    S[i].max = max(build_st(S, A, 2*i+1, l, mid).max, build_st(S, A, 2*i+2, mid+1, r).max);
    return S[i];
  }
}

int get_sum(struct all S[], int i, int l, int r, int Sl, int Sr){
  if(l>=Sl && r<=Sr){
    return S[i].sum;
  } else if(Sr<l || Sl>r) {
    return 0;
  } else {
    int mid = (l+r)/2;
    return get_sum(S, 2*i+1, l, mid, Sl, Sr) + get_sum(S, 2*i+2, mid+1, r, Sl, Sr);
  }
}

float get_avg(struct all S[], int i, int l, int r, int n, int Sl, int Sr){
  if(l>=Sl && r<=Sr){
    return (float)S[i].sum;
  } else if(Sr<l || Sl>r) {
    return 0;
  } else {
    int mid = (l+r)/2;
    if(l == 0 && r == n)
    return ((float)(get_avg(S, 2*i+1, l, mid, n, Sl, Sr) + get_avg(S, 2*i+2, mid+1, r, n, Sl, Sr)) / (float)(Sr-Sl+1));
    else return (float)(get_avg(S, 2*i+1, l, mid, n, Sl, Sr) + get_avg(S, 2*i+2, mid+1, r, n, Sl, Sr));
  }
}

int get_min(struct all S[], int i, int l, int r, int Sl, int Sr){
  if(l>=Sl && r<=Sr){
    return S[i].min;
  } else if(Sr<l || Sl>r) {
    return INT_MAX;
  } else {
    int mid = (l+r)/2;
    return min(get_min(S, 2*i+1, l, mid, Sl, Sr), get_min(S, 2*i+2, mid+1, r, Sl, Sr));
  }
}

int get_max(struct all S[], int i, int l, int r, int Sl, int Sr){
  if(l>=Sl && r<=Sr){
    return S[i].max;
  } else if(Sr<l || Sl>r) {
    return INT_MIN;
  } else {
    int mid = (l+r)/2;
    return max(get_max(S, 2*i+1, l, mid, Sl, Sr), get_max(S, 2*i+2, mid+1, r, Sl, Sr));
  }
}

void update(struct all S[], int A[], int n, int i, int l, int r, int index){
  if(index >= l && index <= r){
    S[i].sum = S[i].sum + (n - A[index]);
    S[i].avg = ((float)S[i].sum / (float)(r-l+1));
    if(l == r) {S[i].min = n; S[i].max = n;}
    if(l != r){
      int mid = (l+r)/2;
      update(S, A, n, 2*i+1, l, mid, index);
      update(S, A, n, 2*i+2, mid+1, r, index);
      S[i].min = min(S[2*i+1].min, S[2*i+2].min);
      S[i].max = max(S[2*i+1].max, S[2*i+2].max);
    }
  } else {
    return;
  }
}

int main(){
  struct all S[40];
  int A[20];
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>A[i];
  }
  build_st(S, A, 0, 0, n-1);
  int q;
  cin>>q;
  int x, y, z;
  while(q != 0){
    cin>>x>>y>>z;
    if(x == 0) {
      update(S, A, z, 0, 0, n-1, y);
      A[y] = z;
    } else if(x == 1){
      cout<<get_min(S, 0, 0, n-1, y, z)<<endl;
    } else if(x == 2){
      cout<<get_max(S, 0, 0, n-1, y, z)<<endl;
    } else if(x == 3){
      cout<<get_sum(S, 0, 0, n-1, y, z)<<endl;
    } else if(x == 4){
      cout<<get_avg(S, 0, 0, n-1, n-1, y, z)<<endl;
    }
    q--;
  }
  return 0;
}


// 10 1 2 3 4 5 6 7 8 9 10 12 1 2 7 2 3 9 3 2 6 4 0 5 0 6 13 0 2 7 0 9 12 0 0 17 1 0 4 2 5 9 3 2 7 4 6 9
// 10 1 2 3 4 5 6 7 8 9 10 8 1 2 7 2 3 9 3 2 6 4 0 5 0 6 13 0 2 7 0 9 12 0 0 17