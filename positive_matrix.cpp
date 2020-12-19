#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mat[4][5] = {{-1, -9, 0, -1, 0},
                     {-8, -3, -2, 9, -7},
                     {2, 0, 0, -6, 0},
                     {0, -7, -3, 5, -4}};
    int tags[4][5];
    int count = 0;
    bool is_done = false;
    while (!is_done)
    {
        is_done = true;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                tags[i][j] = 0;
            }
        }
        count++;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                int curx = j, cury = i;
                if (mat[i][j] > 0 && tags[i][j] == 0)
                {
                    tags[i][j] = 1;
                    if (mat[cury + 1][curx] < 0 && cury + 1 < 4)
                    {
                        tags[i + 1][j] = 1;
                        mat[cury + 1][curx] = -mat[cury + 1][curx];
                    }
                    if (mat[cury - 1][curx] < 0 && cury - 1 >= 0)
                    {
                        tags[i - 1][j] = 1;
                        mat[cury - 1][curx] = -mat[cury - 1][curx];
                    }
                    if (mat[cury][curx + 1] < 0 && curx + 1 < 5)
                    {
                        tags[i][j + 1] = 1;
                        mat[cury][curx + 1] = -mat[cury][curx + 1];
                    }
                    if (mat[cury][curx - 1] < 0 && curx - 1 >= 0)
                    {
                        tags[i][j - 1] = 1;
                        mat[cury][curx - 1] = -mat[cury][curx - 1];
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (mat[i][j] < 0)
                {
                    is_done = false;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}
