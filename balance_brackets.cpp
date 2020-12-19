#include<bits/stdc++.h>
using namespace std;

struct stack_c {
    int size;
    int top;
    char elements[50];
};

void push_char(struct stack_c &S, char c) {
    if (S.top == S.size - 1) {
        cout<<"Stack full!!";
    } else {
        S.top = S.top + 1;
        S.elements[S.top] = c;
    }
}

char pop_char(struct stack_c &S) {
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

int balance_brackets(string a) {
    struct stack_c S;
    S.top=-1;
    S.size=15;
    char OB[3] = {'{', '[', '('};
    char CB[3] = {'}', ']', ')'};
    int count = 0;
    for (int i=0; i<a.length(); i++) {
        if(in_array(OB, a[i], 3)){
            push_char(S, a[i]);
        } else if (in_array(CB, a[i], 3)){
            if(S.top != -1) {
                char x = pop_char(S);
                if (find_index(CB, a[i], 3) != find_index(OB, x, 3)) {
                    count++;
                    a[i] = CB[find_index(OB, x, 3)];
                }
            } else {
                count++;
                a[i] = OB[find_index(CB, a[i], 3)];
                push_char(S, a[i]);
            }
            
        }
    }
    return count;
}

int main() {
    string s1 = "(()(())(()";
    char OB[3] = {'{', '[', '('};
    char CB[3] = {'}', ']', ')'};
    int sum = balance_brackets(s1);
    string s2 = s1;
    for (int i=0; i<s1.length(); i++) {
        s2[i] = s1[s1.length() - i - 1];
        if (in_array(OB, s2[i], 3)){
            s2[i] = CB[find_index(OB, s2[i], 3)];
        } else if (in_array(CB, s2[i], 3)){
            s2[i] = OB[find_index(CB, s2[i], 3)];
        }
    }
    cout<<sum+balance_brackets(s2);
    return 0;
}
