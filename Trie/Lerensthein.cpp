#include <bits/stdc++.h>
using namespace std;

int min(int a, int b, int c)
{
  int min = (b < c) ? b : c;
  min = (min < a) ? min : a;
  return min;
}

int difference(string s1, string s2)
{
  int m = s1.length();
  int n = s2.length();
  int arr[m + 1][n + 1];
  for (int j = 0; j <= n; j++)
  {
    arr[0][j] = j;
  }
  for (int j = 0; j <= m; j++)
  {
    arr[j][0] = j;
  }
  for (int j = 1; j <= m; j++)
  {
    for (int k = 1; k <= n; k++)
    {
      if (s1[j - 1] != s2[k - 1])
      {
        arr[j][k] = 1 + min(arr[j - 1][k], arr[j][k - 1], arr[j - 1][k - 1]);
      }
      else
      {
        arr[j][k] = arr[j - 1][k - 1];
      }
    }
  }
  stack<string> S;
  int M = m, N = n;
  while (m >= 0 && n >= 0)
  {
    if (m - 1 >= 0 && n - 1 >= 0 && s1[m - 1] == s2[n - 1])
    {
      string str = "N ";
      str.push_back(s1[m - 1]);
      str.push_back(' ');
      str.push_back(s2[n - 1]);
      S.push(str);
      m = m - 1;
      n = n - 1;
    }
    else if (m - 1 >= 0 && n - 1 >= 0 && arr[m][n] == 1 + arr[m - 1][n - 1])
    {
      string str = "C ";
      str.push_back(s1[m - 1]);
      str.push_back(' ');
      str.push_back(s2[n - 1]);
      S.push(str);
      m--;
      n--;
    }
    else if (m - 1 >= 0 && arr[m][n] == 1 + arr[m - 1][n])
    {
      string str = "D ";
      str.push_back(s1[m - 1]);
      S.push(str);
      m--;
    }
    else if (arr[m][n] == 1 + arr[m][n - 1])
    {
      string str = "A ";
      str.push_back(s2[n - 1]);
      S.push(str);
      n--;
    }
    if (m == 0 && n == 0)
      break;
  }
  while (!S.empty())
  {
    cout << S.top() << endl;
    S.pop();
  }
  cout << arr[M][N];
}

int main()
{
  string s1, s2;
  int n;
  cin >> n;
  while (n--)
  {
    cin >> s1 >> s2;
    cout<<s1<<" "<<s2<<endl;
    difference(s1, s2);
    cout<<endl;
  }
  return 0;
}

// 3 some sort so some soft state