#include<bits/stdc++.h>
using namespace std;

struct stdnode {
  int rno;
  struct regnode *slptr = NULL;
};

struct coursenode {
  char cname;
  struct regnode *clptr = NULL;
};

struct regnode {
  int rrno;
  struct regnode *sfp = NULL;
  char rcname;
  struct regnode *cfp = NULL;
  struct regnode *next = NULL;
};

typedef struct regnode *rptr;

void connect_S(rptr &std, rptr &R){
  if(std == NULL){
    std = R;
    return;
  }
  connect_S(std -> sfp, R);
}

void connect_C(rptr &crs, rptr &R){
  if(crs == NULL){
    crs = R;
    return;
  }
  connect_C(crs -> cfp, R);
}

rptr insert_rptr (rptr &R, int n, int c){
  if(R == NULL){
    R = new(regnode);
    R -> rrno = n;
    R -> rcname = c;
    R -> next = NULL;
    return R;
  }
  insert_rptr(R -> next, n, c);
}

bool is_enrolled(int n, rptr R){
  while(R != NULL){
    if(R -> rrno == n){
      return true;
    }
    R = R -> cfp;
  }
  return false;
}

bool has_taken(char c, rptr R){
  while(R != NULL){
    if(R -> rcname == c){
      return true;
    }
    R = R -> sfp;
  }
  return false;
}

void print_crs_2(rptr std1, rptr std2){
  if(std1 != NULL){
    if(has_taken(std1->rcname, std2)){
      cout<<std1->rcname<<" ";
    }
    print_crs_2(std1->sfp, std2);
  } else {
    cout<<endl;
    return;
  }
}

void print_std_2(rptr crs1, rptr crs2){
  if(crs1 != NULL){
    print_std_2(crs1->cfp, crs2);
    if(is_enrolled(crs1->rrno, crs2)){
      cout<<crs1->rrno<<" ";
    }
  }
}

void print_crs (rptr std){
  if(std != NULL){
    cout<<std->rcname<<" ";
    print_crs(std -> sfp);
  } else {
    cout<<endl;
    return;
  }
}

void print_std (rptr crs){
  if(crs != NULL){
    cout<<crs->rrno<<" ";
    print_std(crs -> cfp);
  } else {
    cout<<endl;
    return;
  }
}

int main() {
  struct stdnode S[5];
  struct coursenode C[4];
  char c;
	int n;
	cin >> n >> c;
  rptr REG = NULL;
	while (n != -1 || c != '#')
	{
		S[n-1].rno = n;
		C[c - 'A'].cname = c;
		rptr R = insert_rptr(REG, n, c);
    connect_S(S[n-1].slptr, R);
    connect_C(C[c - 'A'].clptr, R);
		cin >> n >> c;
	}
  rptr R = REG;
  cin>>n;
  print_crs(S[n-1].slptr);
  cin>>c;
  print_std(C[c-'A'].clptr);
  int n1, n2;
  char c1, c2;
  cin>>c1>>c2;
  print_std_2(C[c2-'A'].clptr, C[c1-'A'].clptr);
  cout<<endl;
  cin>>n1>>n2;
  print_crs_2(S[n1-1].slptr, S[n2-1].slptr);
  while(R != NULL){
    cout<<R->rrno<<" "<<R->rcname<<" ";
    R = R -> next;
  }
  return 0;
}
