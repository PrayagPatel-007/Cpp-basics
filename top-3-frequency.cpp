#include<bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node *next;
};

typedef struct node *lptr;

void create_ll(lptr &L){
  int n;
  cin>>n;
  if(n != -1){
    L = new(node);
    L -> data = n;
    L ->next=NULL;
    create_ll(L->next);
  }
}

void find_in_freq(int freq[], lptr arrl[], int n){
  for(int i=0; i<n; i++){
    lptr L = arrl[i];
    while(L!= NULL){
      freq[L->data]++;
      L= L-> next;
    }
  }
}

void print(lptr L){
  if(L != NULL){
    cout<<L->data<<" ";
    print(L->next);
  }
}

void print_freq(int freq[]){
  int max=-999;
  int counter = 0;
  int index = 0;
  for(int i =99; i>=0; i--){
    if(max<freq[i]){
      max = freq[i];
      index = i;
      counter=0;
    } else if(max == freq[i]){
      counter++;
    }
  }
  cout<<index<<" "<<max<<endl;
  freq[index] = 0;
  while(counter != 0){
    print_freq(freq);
    counter--;
  }
}

int main(){
  int n;
  cin>>n;
  int freq[100] = {0};
  lptr arrl[100] = {NULL};
  for(int i=0; i<n; i++){
    create_ll(arrl[i]);
  }
  find_in_freq(freq, arrl, n);
  print_freq(freq);
  print_freq(freq);
  print_freq(freq);
  return 0;
}

