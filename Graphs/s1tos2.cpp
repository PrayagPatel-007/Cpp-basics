#include<bits/stdc++.h>
using namespace std;

int min(int a, int b, int c){
  int min = (b<c) ? b : c;
  min = (min < a)? min : a;
  return min;
}

int difference(string s1, string s2){
  int m = s1.length();
  int n = s2.length();
  int arr[m+1][n+1];
  for(int j=0; j<=n; j++){
    arr[0][j] = j;
  }
  for(int j=0; j<=m; j++){
    arr[j][0] = j;
  }
  for(int j=1; j<=m; j++){
    for(int k=1; k<=n; k++){
      if(s1[j-1] != s2[k-1]) {
        arr[j][k] = 1 + min(arr[j-1][k], arr[j][k-1], arr[j-1][k-1]);
      } else {
        arr[j][k] = arr[j-1][k-1];
      }
    }
  }
  return arr[m][n];
}

