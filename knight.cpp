#include<bits/stdc++.h>
using namespace std;

struct coord {
    int x;
    int y;
};

struct Queue_ {
    int size;
    int f;
    int r;
    struct coord elements[1000];
};


void enqueue(struct Queue_ &Q, int x, int y) {
    if ((Q.r+1)%Q.size == Q.f) {
        cout<<"Queue_ full";
    } else {
        if (Q.r == -1) {
            Q.r++;
            Q.f++;
        } else {
            Q.r = (Q.r+1)%Q.size;
        }
        struct coord n;
        n.x = x;
        n.y = y;
        Q.elements[Q.r] = n;
    }
}

struct coord dequeue(struct Queue_ &Q) {
    if (Q.f == -1) {
        struct coord s;
        cout<<"Queue_ Empty";
        return s;
    } else {
        struct coord s;
        if (Q.f == Q.r) {
            s = Q.elements[Q.f];
            Q.f = -1;
            Q.r = -1;
        } else {
            s = Q.elements[Q.f];
            Q.f++;
        }
        return s;
    }
} 

int main() {
    int count = 0;
    int sx, sy, dx, dy;
    cin>>sx>>sy>>dx>>dy;
    int curx, cury;
    curx = sx;
    cury = sy;
    bool done = false;
    while (!done) {
        if(curx-1>=0 && cury+2< 8) {
            curx -= 1;
            cury += 2;
        } else if(cury+1 < 8 && curx -2 >= 0) {
            curx -= 2;
            cury += 1;
        }else if(cury - 2 >= 0 && curx -1 >= 0) {
            cury -= 2;
            curx -=1;
        } else if (cury-1 >= 0 && curx - 2 >= 0) {
            cury-=1;
            curx-=2;
        }
        done = false;
        count++;
        if(curx == dx && cury == dy) {
            done=true;
        }
    }
    // cout<<endl;
    cout<<count;
    return 0;
}