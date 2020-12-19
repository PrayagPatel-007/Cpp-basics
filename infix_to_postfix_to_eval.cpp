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

void push_i(struct stack_generic &S, int n) {
    if (S.top == S.size - 1) {
        cout<<"Stack full!!";
    } else {
        S.top = S.top + 1;
        S.elements[S.top].i = n;
    }
}

void push_c(struct stack_generic &S, char c) {
    if (S.top == S.size - 1) {
        cout<<"Stack full!!";
    } else {
        S.top = S.top + 1;
        S.elements[S.top].c = c;
    }
}

int pop_i(struct stack_generic &S) {
    if (S.top == -1) {
        return 0;
    } else {
        int n = S.elements[S.top].i;
        S.top = S.top - 1;
        return n;
    }
}

char pop_c(struct stack_generic &S) {
    if (S.top == -1) {
        return 'a';
    } else {
        char c = S.elements[S.top].c;
        S.top = S.top - 1;
        return c;
    }
}

int peek_i(struct stack_generic &S) {
    if (S.top == -1) {
        return 0;
    } else {
        return S.elements[S.top].i;
    }
}

int peek_c(struct stack_generic &S) {
    if (S.top == -1) {
        return 'a';
    } else {
        return S.elements[S.top].c;
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
        case 'a': return 0;
    }
}

int infix_2_postfix(struct stack_generic &S, char str[], int tags[], union union_generic arr[]){
    char arr_c[] = {'*', '+', '-', '/', '(', ')', '{', '}', '[', ']'};
    int number;
    char optr;
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
                while (peek_c(S) != '(') {
                    arr[j].c = pop_c(S);
                    tags[j] = 1;
                    j++;
                }
                pop_c(S);
            }else if(optr == '{') {
                push_c(S, optr);
            } else if (optr == '}'){
                while (peek_c(S) != '{') {
                    arr[j].c = pop_c(S);
                    tags[j] = 1;
                    j++;
                }
                pop_c(S);
            }else if(optr == '[') {
                push_c(S, optr);
            } else if (optr == ']'){
                while (peek_c(S) != '[') {
                    arr[j].c = pop_c(S);
                    tags[j] = 1;
                    j++;
                }
                pop_c(S);
            } else {
                while (precedence(peek_c(S)) >= precedence(optr)){
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
    return j;
}

void postfix_eval(struct stack_generic &S, union union_generic arr[], int tags[], int n) {
    int number;
    char optr;
    S.top=-1;
    S.size=15;
    for(int i=0; i<n; i++) {
        if (tags[i] == 0) {
            number = arr[i].i;
            push_i(S, number);
        } else {
            optr = arr[i].c;
            int opnd2 = pop_i(S);
            int opnd1 = pop_i(S);
            push_i(S, eval(opnd1, opnd2, optr));
        }
    }
    cout<<pop_i(S);
}

int main() {
    union union_generic arr[100];
    int tags[100];
    char str[50];
    struct stack_generic S;
    cout<<"Enter the string: ";
    cin.getline(str, 50);
    int j = infix_2_postfix(S, str, tags, arr);
    postfix_eval(S, arr, tags, j);
    return 0;
}