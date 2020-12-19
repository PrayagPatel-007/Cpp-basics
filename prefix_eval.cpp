#include <bits/stdc++.h>
using namespace std;

//HELPER

union Uni {
    int i;
    char c;
};

bool is_int(char c)
{
    if (c >= 48 && c <= 57)
    {
        return true;
    }
    return false;
}

struct Queue_
{
    int size;
    int f;
    int r;
    union Uni elements[500];
};

void enqueue(struct Queue_ &Q, union Uni x, int tag)
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
        }
        else
        {
            Q.elements[Q.r].c = x.c;
        }
    }
}

union Uni dequeue(struct Queue_ &Q)
{
    if (Q.f == -1)
    {
        union Uni s;
        cout << "Queue_ Empty";
        return s;
    }
    else
    {
        union Uni s;
        if (Q.f == Q.r)
        {
            s = Q.elements[Q.f];
            Q.f = -1;
            Q.r = -1;
        }
        else
        {
            s = Q.elements[Q.f];
            Q.f++;
        }
        return s;
    }
}

union Uni eval(int opnd1, int opnd2, char optr)
{
    union Uni s;
    switch (optr)
    {
    case '*':
        s.i = opnd1 * opnd2;
        break;
    case '/':
        s.i = opnd1 / opnd2;
        break;
    case '+':
        s.i = opnd1 + opnd2;
        break;
    case '-':
        s.i = opnd1 - opnd2;
        break;
    }
    return s;
}

// Question

void pre_eval(struct Queue_ &Q1, int tags[])
{
    struct Queue_ Q2;
    Q2.f = -1;
    Q2.r = -1;
    Q2.size = 1000;
    int tags2[3];
    int i = -1;
    while (Q1.r - Q1.f != 0)
    {
        int ind = -1;
        int n = Q1.r - Q1.f + 1;
        while (ind < n - 1)
        {
            while (Q2.r - Q2.f + 1 < 3 && ind < n - 1)
            {
                i++;
                ind++;
                enqueue(Q2, dequeue(Q1), tags[i]);
                tags2[0] = tags2[1];
                tags2[1] = tags2[2];
                tags2[2] = tags[i];
            }
            bool is_calc = false;
            if (tags2[0] == 1 && tags2[1] == 0)
            {
                if (tags2[2] == 0)
                {
                    is_calc = true;
                }
            }
            if (is_calc)
            {
                char c = dequeue(Q2).c;
                int op1 = dequeue(Q2).i;
                int op2 = dequeue(Q2).i;
                enqueue(Q1, eval(op1, op2, c), 0);
                tags[Q1.r] = 0;
            }
            else
            {
                int index = 0;
                if (ind == n - 1)
                {
                    while (Q2.f != -1)
                    {
                        enqueue(Q1, dequeue(Q2), tags2[index]);
                        tags[Q1.r] = tags2[index];
                        index++;
                    }
                    break;
                }
                union Uni x = dequeue(Q2);
                enqueue(Q1, x, tags2[0]);
                tags[Q1.r] = tags2[0];
            }
        }
    }
}

int main()
{
    char P[] = "-+*9+28*+4863";
    struct Queue_ Q;
    Q.r = -1;
    Q.f = -1;
    Q.size = 1000;
    int tags[1000];
    for (int i = 0; i < 13; i++)
    {
        union Uni x;
        if (is_int(P[i]))
        {
            tags[i] = 0;
            x.i = P[i] - '0';
            enqueue(Q, x, 0);
        }
        else
        {
            tags[i] = 1;
            x.c = P[i];
            enqueue(Q, x, 1);
        }
    }
    pre_eval(Q, tags);
    cout << dequeue(Q).i;
    return 0;
}
