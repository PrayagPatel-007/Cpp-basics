#include<bits/stdc++.h>
using namespace std;

string distinct(string str1, string str2){
  set<char> St;
  for(int i=0; i<str1.length(); i++){
    St.insert(str1[i]);
  }
  for(int i=0; i<str2.length(); i++){
    St.insert(str2[i]);
  }
  string str;
  for(auto x : St){
    str.push_back(x);
  }
  return str;
}

string build_st(string S[], string A, int i, int l, int r){
  if(l == r){
    S[i] = A[l];
    return S[i];
  } else {
    int mid = (l+r)/2;
    S[i] = distinct(build_st(S, A, 2*i+1, l, mid), build_st(S, A, 2*i+2, mid+1, r));
    return S[i];
  }
}

string get_distinct(string S[], int i, int l, int r, int Sl, int Sr){
  if(l>=Sl && r<=Sr){
    return S[i];
  } else if(Sr<l || Sl>r) {
    return "";
  } else {
    int mid = (l+r)/2;
    return distinct(get_distinct(S, 2*i+1, l, mid, Sl, Sr), get_distinct(S, 2*i+2, mid+1, r, Sl, Sr));
  }
}

void update(string S[], string str, int i, int l, int r, int index){
  if(index >= l && index <= r){
    if(l == r) S[i] = str;
    else {
      int mid = (l+r)/2;
      update(S, str, 2*i+1, l, mid, index);
      update(S, str, 2*i+2, mid+1, r, index);
      S[i] = distinct(S[2*i+1], S[2*i+2]);
    }
  } else {
    return;
  }
}


int main(){
  string A;
  string S[40];
  char c;
  int i=0;
  cin>>c;
  while(c != '#'){
    A.push_back(c);
    i++;
    cin>>c;
  }
  build_st(S, A, 0, 0, i-1);
  int q;
  cin>>q;
  int x, y;
  while(q != 0){
    cin>>x>>y;
    if(x == 1) {
      string z;
      cin>>z;
      update(S, z, 0, 0, i-1, y-1);
      A[y] = z[0];
    } else if(x == 2){
      int z;
      cin>>z;
      cout<<get_distinct(S, 0, 0, i-1, y-1, z-1).length()<<endl;
    }
    q--;
  }
  return 0;
}

// d f c b b c f e e e d b a e a # 17 1 6 e 1 4 b 2 6 14 1 7 b 1 12 c 2 6 8 2 1 6 1 7 c 1 2 f 1 10 a 2 7 9 1 10 a 1 14 b 1 1 f 2 1 11 1 14 e 2 14 15
