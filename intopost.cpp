#include<bits/stdc++.h>
#include<string>
using namespace std;



struct stack_c {
    int size;
    int top;
    char elements[50];
};

void push_c(struct stack_c &S, char c) {
    if (S.top == S.size - 1) {
        cout<<"Stack full!!";
    } else {
        S.top = S.top + 1;
        S.elements[S.top] = c;
    }
}

int pop_c(struct stack_c &S) {
    if (S.top == -1) {
        cout<<"Stack Empty!!";
        return 0;
    } else {
        char c = S.elements[S.top];
        S.top = S.top - 1;
        return c;
    }
}

char peek(struct stack_c &S) {
    if (S.top == -1) {
        return 'p';
    } else {
        return S.elements[S.top];
    }
}

int precedence(char c){
    switch (c) {
        case '+': return 1;
        case '-': return 1;
        case '/': return 2;
        case '*': return 2;
        case '%': return 3;
        case '(': return 0;
        case '{': return 0;
        case '[': return 0;
        case 'p': return 0;
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
    struct stack_c S;
    char arr_c[] = {'*', '+', '-', '/', '(', ')', '{', '}', '[', ']'};
    int number;
    char optr;
    union Uni arr[100];
    int tags[100];
    int j=0;
    S.top=-1;
    S.size=15;
    string arr_s[100];
    char *tok =  strtok(str, " ");
    int count=0;
    while(tok != NULL){
        arr_s[count] = tok;
        tok = strtok(NULL, " ");
        count++;
    }
    for(int i=0; i<count; i++) {
        if (!in_array(arr_c, arr_s[i][0], 10)) {
            number = atoi(arr_s[i].c_str());
            arr[j].i = number;
            tags[j] = 0;
            j++;
        } else {
            optr = arr_s[i][0];
            if (S.top == -1) {
                push_c(S, optr);
            } else if(optr == '(') {
                push_c(S, optr);
            } else if (optr == ')'){
                while (peek(S) != '(') {
                    arr[j].c = pop_c(S);
                    tags[j] = 1;
                    j++;
                }
                pop_c(S);
            }else if(optr == '{') {
                push_c(S, optr);
            } else if (optr == '}'){
                while (peek(S) != '{') {
                    arr[j].c = pop_c(S);
                    tags[j] = 1;
                    j++;
                }
                pop_c(S);
            }else if(optr == '[') {
                push_c(S, optr);
            } else if (optr == ']'){
                while (peek(S) != '[') {
                    arr[j].c = pop_c(S);
                    tags[j] = 1;
                    j++;
                }
                pop_c(S);
            } else {
                while (precedence(peek(S)) >= precedence(optr)){
                    arr[j].c = pop_c(S);
                    tags[j] = 1;
                    j++;
                }
                push_c(S, optr);
            }
        }
    }
    while (S.top > -1) {
        arr[j].c = pop_c(S);
        tags[j] = 1;
        j++;
    }
    for (int i=0; i<j; i++) {
        if (tags[i] == 0) {
            cout<<arr[i].i<<" ";
        } else {
            cout<<arr[i].c<<" ";
        }
    }
    return 0;
}