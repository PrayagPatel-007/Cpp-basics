#include<bits/stdc++.h>
using namespace std;

struct coord {
    int x;
    int y;
};

struct stack_ {
    int size;
    int top;
    struct coord elements[50];
};

void push(struct stack_ &S, int curx, int cury) {
    if (S.top == S.size - 1) {
        cout<<"Stack full!!";
    } else {
        S.top = S.top + 1;
        S.elements[S.top].x = curx;
        S.elements[S.top].y = cury;
    }
}

struct coord pop(struct stack_ &S) {
    if (S.top == -1) {
        struct coord n;
        cout<<"Stack Empty!!";
        return n;
    } else {
        struct coord n = S.elements[S.top];
        S.top = S.top - 1;
        return n;
    }
}

int main() {
    int maze[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 0, 1, 1, 1, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 1, 1, 1, 0, 0, 1, 0},
                        {0, 1, 0, 1, 0, 1, 1, 0},
                        {0, 1, 0, 1, 0, 0, 0, 0},
                        {0, 1, 0, 1, 1, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        };
    int spx, spy, dpx, dpy;
    cin>>spx>>spy>>dpx>>dpy;
    bool is_route = false;
    struct stack_ S;
    S.top=-1;
    S.size = 20;
    int curx = spx, cury = spy;
    push(S, spx, spy);
    maze[spx][spy] = 2;
    while (S.top > -1) {
        if (curx == dpx && cury == dpy) {
            is_route = true;
            break;
        }
        pop(S);
        if (maze[curx-1][cury] == 1) {
            maze[curx-1][cury] = 2;
            curx = curx-1;
            cury = cury;
            push(S, curx, cury);
        }
        if (maze[curx+1][cury] == 1) {
            maze[curx+1][cury] = 2;
            curx = curx+1;
            cury = cury;
            push(S, curx, cury);
        }
        if (maze[curx][cury-1] == 1) {
            maze[curx][cury-1] = 2;
            curx = curx;
            cury = cury-1;
            push(S, curx, cury);
        }
        if (maze[curx][cury+1] == 1) {
            maze[curx][cury+1] = 2;
            curx = curx;
            cury = cury+1;
            push(S, curx, cury);
        }
    }
    if(is_route) {
        cout<<1;
    } else {
        cout<<0;
    }
    return 0;
}