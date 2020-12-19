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
    int maze[10][10] = {{1, 0, 1, 0, 0, 0, 1, 1, 1, 1},
                        {0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
                        {1, 1, 1, 1, 0, 0, 1, 0, 0, 0},
                        {1, 0, 0, 1, 0, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
                        {0, 1, 0, 1, 0, 0, 1, 1, 1, 1},
                        {0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
                        {0, 0, 0, 1, 0, 0, 1, 1, 1, 0},
                        {1, 0, 1, 0, 1, 0, 0, 1, 0, 0},
                        {1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
                        };
    int count = 1;
    struct Queue_ Q;
    Q.r=-1;
    Q.f=-1;
    Q.size = 1000;
    for (int i=0; i<10; i++) {
        for (int j = 0; j < 10; j++)
        {
            int curx, cury;
            if (maze[i][j] == 1) {
                count++;
                curx = j;
                cury = i;
                enqueue(Q, j, i);
                maze[i][j] = count;
                while (Q.r != -1) {
                    struct coord c = dequeue(Q);
                    curx = c.x;
                    cury = c.y;
                    if(maze[cury+1][curx] == 1 && cury+1< 10) {
                        maze[cury+1][curx] = count;
                        enqueue(Q, curx, cury+1);
                        // cout<<curx<<cury+1<<" ";
                    }
                    if(maze[cury-1][curx] == 1 && cury-1>= 0) {
                        maze[cury-1][curx] = count;
                        enqueue(Q, curx, cury-1);
                        // cout<<curx<<cury-1<<" ";
                    }
                    if(maze[cury][curx+1] == 1  && curx+1< 10) {
                        maze[cury][curx+1] = count;
                        enqueue(Q, curx+1, cury);
                        // cout<<curx+1<<cury<<" ";
                    }
                    if(maze[cury][curx-1] == 1 && curx-1>= 0) {
                        maze[cury][curx-1] = count;
                        enqueue(Q, curx-1, cury);
                        // cout<<curx-1<<cury<<" ";
                    }
                    if(maze[cury+1][curx-1] == 1 && cury+1< 10) {
                        if (curx - 1>=0) {
                            maze[cury+1][curx-1] = count;
                            enqueue(Q, curx-1, cury+1);
                            // cout<<curx-1<<cury+1<<" ";
                        }
                        
                        
                    }
                    if(maze[cury+1][curx+1] == 1 && cury+1< 10) {
                        if (curx+1<10) {
                            maze[cury+1][curx+1] = count;
                            enqueue(Q, curx+1, cury+1);
                            // cout<<curx+1<<cury+1<<" ";
                        }
                        
                        
                    }
                    if(maze[cury-1][curx+1] == 1 && cury-1>= 0) {
                        if (curx+1<10) {
                            maze[cury-1][curx+1] = count;
                            enqueue(Q, curx+1, cury-1);
                            // cout<<curx+1<<cury-1<<" ";
                        }
                        
                    }
                    if(maze[cury-1][curx-1] == 1 && cury-1>= 0) {
                        if (curx-1>= 0) {
                            maze[cury-1][curx-1] = count;
                            enqueue(Q, curx-1, cury-1); 
                            // cout<<curx-1<<cury-1<<" ";    
                        }
                    } 
                }
            }
        }
    }
    // cout<<endl;
    cout<<count-1<<endl;
    return 0;
}