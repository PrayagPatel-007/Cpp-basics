#include <bits/stdc++.h>
using namespace std;

#define m 5

struct Bdnode
{
  int cnt = 0;
  int keys[m - 1] = {0};
  struct Bdnode *ptr[m] = {NULL};
};

struct OVnode
{
  int cnt = m;
  int keys[m];
  struct Bdnode *ptr[m + 1] = {NULL};
};

typedef struct Bdnode *Bdptr;
typedef struct OVnode *ovptr;

void sort(int arr[], Bdptr ptr[], int n, bool flag)
{
  int i = n - 2;
  while (i >= 0 && arr[i] > arr[i + 1])
  {
    swap(arr[i], arr[i + 1]);
    if (flag)
      swap(ptr[i + 1], ptr[i + 2]);
    i--;
  }
}

void overflow_adjust(Bdptr &B, ovptr &O, Bdptr &BT, Bdptr &p1, Bdptr &p2, int &n, int flag)
{
  for (int i = 0; i < m - 1; i++)
  {
    O->keys[i] = BT->keys[i];
    O->ptr[i] = BT->ptr[i];
  }
  O->ptr[m - 1] = BT->ptr[m - 1];
  O->keys[m - 1] = n;
  sort(O->keys, O->ptr, m, flag);
  int mid = (m) / 2;
  int middle = O->keys[mid];
  for (int i = 0; i <= O->cnt; i++)
  {
    if (O->keys[i] == n)
    {
      O->ptr[i] = p1;
      O->ptr[i + 1] = p2;
    }
  }
  BT->cnt = 0;
  BT->ptr[0] = O->ptr[0];
  for (int i = 0; i < mid; i++)
  {
    BT->keys[i] = O->keys[i];
    BT->ptr[i + 1] = O->ptr[i + 1];
    BT->cnt++;
  }
  int x = 0;
  B->ptr[x] = O->ptr[mid + 1];
  for (int i = mid + 1; i < m; i++)
  {
    B->keys[x] = O->keys[i];
    B->ptr[x + 1] = O->ptr[i + 1];
    x++;
    B->cnt++;
  }
  p1 = BT;
  p2 = B;
  n = middle;
}

void Add(Bdptr &BT, Bdptr &T, int &n, bool &flag, Bdptr parent, Bdptr &p1, Bdptr &p2, int index)
{
  if (BT == NULL)
  {
    Bdptr K = new (Bdnode);
    K->keys[0] = n;
    K->cnt++;
    K->ptr[0] = p1;
    K->ptr[1] = p2;
    T = K;
    BT = K;
  }
  else
  {
    if (BT->ptr[0] != NULL)
    {
      int i = 0;
      while (BT->keys[i] < n && i < BT->cnt)
      {
        i++;
      }
      Add(BT->ptr[i], T, n, flag, BT, p1, p2, i);
    }
    if (BT->ptr[0] == NULL || flag)
    {
      if (BT->cnt != m - 1)
      {
        BT->keys[BT->cnt] = n;
        BT->cnt++;
        sort(BT->keys, BT->ptr, BT->cnt, flag);
        for (int i = 0; i < BT->cnt; i++)
        {
          if (BT->keys[i] == n)
          {
            BT->ptr[i] = p1;
            BT->ptr[i + 1] = p2;
            break;
          }
        }
        flag = false;
      }
      else
      {
        // OVERFLOW
        Bdptr B = new (Bdnode);
        ovptr O = new (OVnode);
        overflow_adjust(B, O, BT, p1, p2, n, flag);
        // if(!flag) {
        //   p2->ptr[m-1] = p1->ptr[m-1];
        //   p1->ptr[m-1] = p2;
        // }
        flag = true;
        if (parent == NULL)
        {
          Add(parent, T, n, flag, parent, p1, p2, index);
        }
      }
    }
  }
}

Bdptr max_node(Bdptr T)
{
  while (T->ptr[T->cnt])
  {
    T = T->ptr[T->cnt];
  }
  return T;
}

void remove_k(Bdptr T, int k)
{
  int i;
  for (i = 0; i < T->cnt; i++)
  {
    if (T->keys[i] == k)
      break;
  }
  for (int j = i; j < T->cnt - 1; j++)
  {
    T->keys[i] = T->keys[i + 1];
    T->ptr[i + 1] = T->ptr[i + 2];
  }
  T->cnt--;
}

void Delete(Bdptr &BT, Bdptr &T, int &n, bool &flag, Bdptr parent, Bdptr &p1, int index)
{
  if (BT->ptr[0] != NULL)
  {
    int i = 0;
    bool found = false;
    while (BT->keys[i] <= n && i < BT->cnt)
    {
      if (BT->keys[i] == n)
      {
        found = true;
        break;
      }
      i++;
    }
    if (!found)
      Delete(BT->ptr[i], T, n, flag, BT, p1, i);
    else
    {
      Bdptr P = max_node(BT->ptr[i]);
      swap(P->keys[P->cnt - 1], BT->keys[i]);
      Delete(BT->ptr[i], T, n, flag, BT, p1, i);
    }
  }
  if (BT->ptr[0] == NULL || flag)
  {
    remove_k(BT, n);
    int i = 0;
    while (i < BT->cnt && n > BT->keys[i])
    {
      i++;
    }
    BT->ptr[i] = p1;
    flag = false;
    if (BT->cnt < (m - 1) / 2)
    {
      if (parent && index - 1 >= 0 && parent->ptr[index - 1] && parent->ptr[index - 1]->cnt > (m - 1) / 2)
      {
        // left sibling
        Bdptr P = parent->ptr[index - 1];
        for (int i = 1; i <= BT->cnt; i++)
        {
          BT->keys[i] = BT->keys[i - 1];
          BT->ptr[i] = BT->ptr[i - 1];
        }
        BT->ptr[BT->cnt + 1] = BT->ptr[BT->cnt];
        BT->keys[0] = parent->keys[index - 1];
        BT->cnt++;
        BT->ptr[0] = P->ptr[P->cnt];
        parent->keys[index - 1] = P->keys[P->cnt - 1];
        P->cnt--;
      }
      else if (parent && index + 1 < m && parent->ptr[index + 1] && parent->ptr[index + 1]->cnt > (m - 1) / 2)
      {
        // right sibling
        Bdptr P = parent->ptr[index + 1];
        BT->keys[BT->cnt] = parent->keys[index];
        BT->cnt++;
        BT->ptr[BT->cnt] = P->ptr[0];
        parent->keys[index] = P->keys[0];
        for (int i = 1; i < P->cnt; i++)
        {
          P->keys[i - 1] = P->keys[i];
          P->ptr[i - 1] = P->ptr[i];
        }
        P->ptr[P->cnt - 1] = P->ptr[P->cnt];
        P->cnt--;
      }
      else
      {
        if (parent)
        {
          // merge
          flag = true;
          if (index - 1 >= 0)
          {
            Bdptr P = parent->ptr[index - 1];
            P->keys[P->cnt] = parent->keys[index - 1];
            P->cnt++;
            for (int i = 0; i < BT->cnt; i++)
            {
              P->keys[P->cnt] = BT->keys[i];
              P->ptr[P->cnt] = BT->ptr[i];
              P->cnt++;
            }
            P->ptr[P->cnt] = BT->ptr[BT->cnt];
            p1 = P;
            n = parent->keys[index - 1];
          }
          else
          {
            Bdptr P = parent->ptr[index + 1];
            BT->keys[BT->cnt] = parent->keys[index];
            BT->cnt++;
            for (int i = 0; i < P->cnt; i++)
            {
              BT->keys[BT->cnt] = P->keys[i];
              BT->ptr[BT->cnt] = P->ptr[i];
              BT->cnt++;
            }
            BT->ptr[BT->cnt] = P->ptr[P->cnt];
            p1 = BT;
            n = parent->keys[index];
          }
        }
        else
        {
          if (BT->cnt == 0)
            T = BT->ptr[0];
        }
      }
    }
  }
}

void print_level(Bdptr MT)
{
  queue<Bdptr> Q;
  Q.push(MT);
  Bdptr B = new (Bdnode);
  Q.push(B);
  while (true)
  {
    MT = Q.front();
    Q.pop();
    if (Q.empty())
    {
      cout << endl;
      break;
    }
    if (MT == B)
    {
      cout << endl;
      Q.push(B);
    }
    for (int i = 0; i < MT->cnt; i++)
    {
      cout << MT->keys[i] << " ";
    }
    for (int i = 0; i <= MT->cnt; i++)
    {
      if (MT->ptr[i])
        Q.push(MT->ptr[i]);
    }
  }
}

int main()
{
  Bdptr BT = NULL;
  int n, d, num;
  bool flag = false;
  Bdptr p1 = NULL, p2 = NULL;
  cin >> num;
  Bdptr parent = NULL;
  while (num != 0)
  {
    parent = NULL;
    p1 = NULL;
    p2 = NULL;
    flag = false;
    Add(BT, BT, num, flag, parent, p1, p2, -1);
    cin >> num;
  }
  print_level(BT);
  cin >> num;
  while (num != 0)
  {
    parent = NULL;
    p1 = NULL;
    flag = false;
    Delete(BT, BT, num, flag, parent, p1, -1);
    print_level(BT);
    cin >> num;
  }
  return 0;
}

// 5 10 15 20 30 25 31 40 50 45 55 33 35 60 65 28 32 0
// 5 10 15 20 30 35 70 0
// 4 5 6 14 15 16 17 18 19 20 21 90 99 100 101 82 89 80 52 59 13 85 44 32 27 0