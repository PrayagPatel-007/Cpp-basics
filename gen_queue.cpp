#include<bits/stdc++.h>
using namespace std;

union u_gen {
    int i;
    char c;
    float f;
};

struct gen_queue {
    int size;
    int f;
    int r;
    union u_gen elements[100];
    int tags[100];
};

void enqueue(struct gen_queue &Q, union u_gen x, int tag) 
{
    if ((Q.r + 1) % Q.size == Q.f)
    {
        cout << "Queue_ full";
    }
    else
    {
        if (Q.r == -1)
        {
            Q.r++;
            Q.f++;
        }
        else
        {
            Q.r = (Q.r + 1) % Q.size;
        }
        if (tag == 0)
        {
            Q.elements[Q.r].i = x.i;
            Q.tags[Q.r] = 0;
        }
        else if (tag == 1)
        {
            Q.elements[Q.r].c = x.c;
            Q.tags[Q.r] = 1;
        } else 
        {
            Q.elements[Q.r].f = x.f;
            Q.tags[Q.r] = 2;
        }
    }
}

union u_gen dequeue(struct gen_queue &Q)
{
    if (Q.f == -1)
    {
        union u_gen s;
        cout << "Queue_ Empty";
        return s;
    }
    else
    {
        union u_gen s;
        if (Q.f == Q.r)
        {
            s = Q.elements[Q.f];
            Q.f = -1;
            Q.r = -1;
        }
        else
        {
            s = Q.elements[Q.f];
            Q.f = Q.f+1%Q.size;
        }
        return s;
    }
}

int main () {
    struct gen_queue Q3;
    Q3.size = 10;
    Q3.r = -1;
    Q3.f = -1;
    int inp, choice;
    union u_gen el;
    cout<<"Enqueue(0) or Dequeue(1) (-1 to exit): ";
    cin>>inp;
    while (inp != -1) {
        if (inp == 0) {
            cout<<"Enter type - number(0), character(1), float(2): ";
            cin>>choice;
            switch (choice) {
                case 0:
                    cin>>el.i;
                    enqueue(Q3, el, 0);
                    break;
                case 1:
                    cin>>el.c;
                    enqueue(Q3, el, 1);
                    break;
                case 2:
                    cin>>el.f;
                    enqueue(Q3, el, 2);
                    break;
            }
        } else {
            dequeue(Q3);
        }
        cout<<"Enqueue(0) or Dequeue(1) (-1 to exit): ";
        cin>>inp;
    }
    while (Q3.r != -1) {
        if (Q3.tags[Q3.f] == 0) {
            cout<<dequeue(Q3).i<<" ";
        } else if (Q3.tags[Q3.f] == 1) {
            cout<<dequeue(Q3).c<<" ";
        } else if (Q3.tags[Q3.f] == 2) {
            cout<<dequeue(Q3).f<<" ";
        } 
    }
    return 0;
}

