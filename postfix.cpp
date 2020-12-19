#include<bits/stdc++.h>
using namespace std;

struct stack_ {
    int size;
    int top;
    int elements[50];
};

void push(struct stack_ &S, int n) {
    if (S.top == S.size - 1) {
        cout<<"Stack full!!";
    } else {
        S.top = S.top + 1;
        S.elements[S.top] = n;
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

int eval(int opnd1, int opnd2, char optr) {
    switch (optr) {
        case '*': return opnd1 * opnd2;
        case '/': return opnd1 / opnd2;
        case '+': return opnd1 + opnd2;
        case '-': return opnd1 - opnd2;
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


int main() {
    char arr_c[4] = {'+', '-', '*', '/'};
    int number;
    char optr;
    struct stack_ S;
    S.top=-1;
    S.size=15;
    char str[50];
    cout<<"Enter the string with each character spaced: ";
    cin.getline(str, 50);
    string arr_s[100];
    char *tok =  strtok(str, " ");
    int count=0;
    while(tok != NULL){
        arr_s[count] = tok;
        tok = strtok(NULL, " ");
        count++;
    }
    for(int i=0; i<count; i++) {
        if (!in_array(arr_c, arr_s[i][0], 4)) {
            number = atoi(arr_s[i].c_str());
            push(S, number);
        } else {
            optr = arr_s[i][0];
            int opnd2 = pop(S);
            int opnd1 = pop(S);
            push(S, eval(opnd1, opnd2, optr));
        }
    }
    cout<<pop(S);
    return 0;
}