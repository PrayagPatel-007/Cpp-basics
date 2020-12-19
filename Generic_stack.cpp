#include<bits/stdc++.h>
using namespace std;

union union_generic {
    int i;
    char c;
    bool b;
};

struct stack_generic {
    int size;
    int top;
    union union_generic elements[50];
};

void push(struct stack_generic &S, union union_generic n, int tags[]) {
    if (S.top == S.size - 1) {
        cout<<"Stack full!!";
    } else {
        S.top = S.top + 1;
        switch(tags[S.top]) {
            case 0: S.elements[S.top].i = n.i;
            case 1: S.elements[S.top].c = n.c;
            case 2: S.elements[S.top].b = n.b;
        }
    }
}

union union_generic pop(struct stack_generic &S, int tags[]) {
    if (S.top == -1) {
        union union_generic n;
        cout<<"Stack Empty!!";
        return n;
    } else {
        union union_generic n = S.elements[S.top];
        S.top = S.top - 1;
        return n;
    }
}

int main() {
    struct stack_generic S;
    union union_generic inp;
    int tags[50], i=0, j=0, choice, num;
    S.top=-1;
    S.size=15;
    while (true){
        cout<<"Push(1) or Pop(0): ";
        cin>>choice;
        if(choice==1){
            cout<<"Press 0 for num, 1 for char, 2 for bool: ";
            cin>>tags[j];
            switch(tags[j]){
                case 0: cin>>inp.i; break;
                case 1: cin>>inp.c; break;
                case 2: cin>>inp.b; break;
            }
            push(S, inp, tags);
            j++;
        } else if (choice == 0) {
            pop(S, tags);
        } else {
            break;
        }
    }
    while (S.top > -1) {
        switch(tags[S.top]) {
            case 0: cout<<pop(S, tags).i<<" "; break;
            case 1: cout<<pop(S, tags).c<<" "; break;
            case 2: cout<<pop(S, tags).b<<" "; break;
        }
        i++;
    }
    return 0;
}
