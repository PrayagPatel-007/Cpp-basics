#include<bits/stdc++.h>
using namespace std;

// struct gtnode {
//   char data;
//   int n_c=0;
//   struct gtnode *child[10];
// };

struct gtnode {
  struct gtnode *fc; // first child
  char data;
  struct gtnode *ns; // next sibling
};

//     A                A
//    /                /|\
//   B - F - J        B F J
//  /                /|\
// C - D - E        C D E

typedef struct gtnode *gtptr;

// BFT  ==  Level Order
// DFT  ==  Recursive