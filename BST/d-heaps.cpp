#include<bits/stdc++.h>
using namespace std;

void perculate_up(int H[], int i, int d){
  while(i > 0){
    if(H[(i-1)/d] > H[i]) {swap(H[i], H[(i-1)/d]);
    i = (i-1)/d;}
    else break;
  }
}

int main(){
  int H[50];
  int n, i=0, d=4;
  cin>>n;
  while(n != -1){
    H[i] = n;
    perculate_up(H, i, d);
    i++;
    cin>>n;
  }
  for(int j=0; j<i; j++) cout<<H[j]<<" ";
  return 0;
}
