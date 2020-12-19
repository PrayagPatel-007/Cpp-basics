#include<bits/stdc++.h>
using namespace std;

// HELPER FUNCTIONS

bool in_array_str(string arr[], string c, int n) {
    for (int i=0; i<n; i++) {
        if (arr[i] == c){
            return true;
        }
    }
    return false;
}


struct stack_c {
    int size;
    int top;
    char elements[50];
};

struct stack_ {
    int size;
    int top;
    int elements[50];
};

struct stack_s {
    int top;
    int size;
    string elements[50];
};

void push_s (struct stack_s &S, string s) {
    if (S.top == S.size - 1) {
        cout<<"Stack full!!";
    } else {
        S.top = S.top + 1;
        S.elements[S.top] = s;
    }
}

string pop_s (struct stack_s &S) {
    if (S.top == -1) {
        cout<<"Stack Empty!!";
        return "0";
    } else {
        return S.elements[S.top--];
    }
}


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




// 6 POSSIBLE CONVERSIONS

void pre_2_post(string arr_s[], int n, string arr_c[]) {
    if (n == 1) {
        cout<<arr_s[0];
        return;
    }
    for (int j=0; j<n-2; j++) {
        if (in_array_str(arr_c, arr_s[j], 3)) {
            if (!in_array_str(arr_c, arr_s[j+1], 3)) {
                if (!in_array_str(arr_c, arr_s[j+2], 3)){
                    arr_s[j] = arr_s[j+1] + arr_s[j+2] + arr_s[j];
                    for (int k = j+1; k<n; k++){
                        arr_s[k] = arr_s[k + 2];
                    }
                }
            }
        }
    }
    n = n -2;
    pre_2_post(arr_s, n, arr_c);
}

void post_2_pre(string arr_s[], int n, string arr_c[]) {
    if (n == 1) {
        cout<<arr_s[0];
        return;
    }
    for (int j=0; j<n-2; j++) {
        if (!in_array_str(arr_c, arr_s[j], 3)) {
            if (!in_array_str(arr_c, arr_s[j+1], 3)) {
                if (in_array_str(arr_c, arr_s[j+2], 3)){
                    arr_s[j] = arr_s[j+2] + arr_s[j] + arr_s[j+1];
                    for (int k = j+1; k<n; k++){
                        arr_s[k] = arr_s[k + 2];
                    }
                }
            }
        }
    }
    n = n -2;
    post_2_pre(arr_s, n, arr_c);
}

string infix_2_post(string str) {
    struct stack_c S;
    char arr_c[] = {'*', '+', '-', '/', '(', ')', '{', '}', '[', ']'};
    char optr;
    string s;
    S.top=-1;
    S.size=15;
    for(int i=0; i<str.length(); i++) {
        if (!in_array(arr_c, str[i], 10)) {
            s.append(1, str[i]);
        } else {
            optr = str[i];
            if (S.top == -1) {
                push_c(S, optr);
            } else if(optr == '(') {
                push_c(S, optr);
            } else if (optr == ')'){
                while (peek(S) != '(') {
                    s.append(1, pop_c(S));
                }
                pop_c(S);
            }else if(optr == '{') {
                push_c(S, optr);
            } else if (optr == '}'){
                while (peek(S) != '{') {
                    s.append(1, pop_c(S));
                }
                pop_c(S);
            }else if(optr == '[') {
                push_c(S, optr);
            } else if (optr == ']'){
                while (peek(S) != '[') {
                    s.append(1, pop_c(S));
                }
                pop_c(S);
            } else {
                while (precedence(peek(S)) >= precedence(optr)){
                    s.append(1, pop_c(S));
                }
                push_c(S, optr);
            }
        }
    }
    while (S.top > -1) {
        s.append(1, pop_c(S));
    }
    return s;
}

string post_2_infix(string str) {
    char arr_c[4] = {'+', '-', '*', '/'};
    string optr;
    struct stack_s S;
    S.top=-1;
    S.size=15;
    for(int i=0; i<str.length(); i++) {
        if (!in_array(arr_c, str[i], 4)) {
            string s = string(1, str[i]);
            push_s(S, s);
        } else {
            optr = string(1, str[i]);
            string opnd2 = pop_s(S);
            string opnd1 = pop_s(S);
            push_s(S, "("+opnd1 + optr + opnd2+")");
        }
    }
    return pop_s(S);
}

string infix_2_pre(string str) {
    string str2 = str;
    for (int i = 0; i < str.length(); i++)
    {
        str2[i] = str[str.length() - i- 1];
        if (str2[i] == '('){
            str2[i] = ')';
        } else if (str2[i] == ')'){
            str2[i] = '(';
        }
    }
    string str3 = infix_2_post(str2);
    string str4 = str3;
    for (int i = 0; i < str3.length(); i++)
    {
        str4[i] = str3[str3.length() - i - 1];
    }
    return str4;
}

string pre_2_infix(string str) {
    string str2 = str;
    for (int i = 0; i < str.length(); i++)
    {
        str2[i] = str[str.length() - i - 1];
    }
    string str3 = post_2_infix(str2);
    string str4 = str3;
    for (int i = 0; i < str3.length(); i++)
    {
        str4[i] = str3[str3.length() - i- 1];
        if (str4[i] == '('){
            str4[i] = ')';
        } else if (str4[i] == ')'){
            str4[i] = '(';
        }
    }
    return str4;
}



int main() {
    string s1 = "**+AB-+CDEF";
    string arr_s1[100];
    string arr_c[4] = {"+", "-", "*", "/"};
    for (int i=0; i<s1.length(); i++) {
        arr_s1[i] = s1[i];
    }
    pre_2_post(arr_s1, s1.length(), arr_c);
    cout<<endl;
    string s2 = "AB+CD+E-*F*";
    string arr_s2[100];
    for (int i=0; i<s2.length(); i++) {
        arr_s2[i] = s2[i];
    }
    post_2_pre(arr_s2, s2.length(), arr_c);
    cout<<endl;
    string s3 = "(A+B)*(C+D-E)*F";
    cout<<infix_2_post(s3);
    cout<<endl;
    cout<<post_2_infix(s2);
    cout<<endl;
    cout<<infix_2_pre(s3);
    cout<<endl;
    cout<<pre_2_infix(s1);
    cout<<endl;
    return 0;
}

