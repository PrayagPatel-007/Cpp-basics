#include<bits/stdc++.h>
using namespace std;

void perculate_up(int H[], int i){
  while(i > 0){
    if(H[(i-1)/2] > H[i]) {swap(H[i], H[(i-1)/2]);
    i = (i-1)/2;}
    else break;
  }
}

void perculate_down(int H[], int n){
  int i=0;
  while(2*i + 1 < n){
    int min;
    if(2*i + 2 < n)
    min = (H[2*i+1] > H[2*i+2]) ? 2*i + 2 : 2*i + 1;
    else 
    min = 2*i + 1;
    if(H[min] < H[i]) {swap(H[min], H[i]);
    i = min;}
    else break; 
  }
}

void heap_sort(int H[], int n){
  while(n != 0){
    cout<<H[0]<<" ";
    H[0] = H[n-1];
    perculate_down(H, n-1);
    n--;
  }
}

int main(){
  int H[50];
  int n, i=0;
  cin>>n;
  while(n != -1){
    H[i] = n;
    perculate_up(H, i);
    i++;
    cin>>n;
  }
  heap_sort(H, i);
  return 0;
}