#include<bits/stdc++.h>
using namespace std;

struct stack_ {
    int size;
    int top;
    int elements[50];
};

struct stack_c {
    int size;
    int top;
    char elements[50];
};

void push(struct stack_ &S, int n) {
    if (S.top == S.size - 1) {
        cout<<"Stack full!!";
    } else {
        S.top = S.top + 1;
        S.elements[S.top] = n;
    }
}

void push_c(struct stack_c &S, char c) {
    if (S.top == S.size - 1) {
        cout<<"Stack full!!";
    } else {
        S.top = S.top + 1;
        S.elements[S.top] = c;
    }
}

int pop(struct stack_ &S) {
    if (S.top == -1) {
        cout<<"Stack Empty!!";
        return 0;
    } else {
        int n = S.elements[S.top];
        S.top = S.top - 1;
        return n;
    }
}

char pop_c(struct stack_c &S) {
    if (S.top == -1) {
        cout<<"Stack Empty!!";
        return 0;
    } else {
        char c = S.elements[S.top];
        S.top = S.top - 1;
        return c;
    }
}

int find_index(char arr[], char c, int n) {
    for (int i=0; i<n; i++) {
        if (arr[i] == c){
            return i;
        }
    }
}

bool in_array(char arr[], char c, int n) {
    for (int i=0; i<n; i++) {
        if (arr[i] == c){
            return true;
        }
    }
    return false;
}


void reee(string a) {
    struct stack_c S;
    S.top=-1;
    S.size=15;
    char OB[3] = {'{', '[', '('};
    char CB[3] = {'}', ']', ')'};
    bool is_complete = true;
    for (int i=0; i<a.length(); i++) {
        if(in_array(OB, a[i], 3)){
            push_c(S, a[i]);
        } else if (in_array(CB, a[i], 3)){
            if(S.top != -1) {
                char x = pop_c(S);
                if (find_index(CB, a[i], 3) != find_index(OB, x, 3)) {
                    is_complete = false;
                    break;
                }
            } else {
                is_complete = false;
                break;
            }
            
        }
    }
    if (S.top != -1){
        is_complete = false;
    }
    if(is_complete) {
        cout<<"T";
    } else {
        cout<<"F";
    }
}

int main() {
    reee("{{}}{{}[]}");
    return 0;
}