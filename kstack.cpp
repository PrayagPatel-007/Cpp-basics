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

int peek(struct stack_ &S) {
    if (S.top == -1) {
        cout<<"Stack Empty!!";
        return 0;
    } else {
        int n = S.elements[S.top];
        return n;
    }
}


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

int find_index(char arr[], char c, int n) {
    for (int i=0; i<n; i++) {
        if (arr[i] == c){
            return i;
        }
    }
}

void multidigit_postfix(char str[]) {
    char arr_c[4] = {'+', '-', '*', '/'};
    int number;
    char optr;
    struct stack_ S;
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
}

void balance_parantheses(string a){
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
    char str[50];
    cout<<"Enter the string with each character spaced: ";
    cin.getline(str, 50);
    multidigit_postfix(str);
    cout<<endl;
    balance_parantheses("{{}}{}[](){()}]");
    cout<<endl;
    struct stack_generic S;
    union union_generic inp;
    int tags[50], i=0, j=0, choice, num;
    S.top=-1;
    S.size=15;
    while (true){
        cout<<"Push(1) or Pop(0) or some other number to exit: ";
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
    int k, ind = 0;
    cout<<"Enter k: ";
    cin>>k;
    struct stack_ arr[k];
    for (int i=0; i<k; i++) {
        arr[i].top = -1;
        arr[i].size = 15;
    }
    cout<<"Enter the index (or -1 to exit): ";
    cin>>ind;
    while (ind!=-1){
        cout<<"Push(1) or pop(0): ";
        cin>>choice;
        if (choice == 1){
            cout<<"Enter the number: ";
            cin>>num;
            push(arr[ind], num);
        } else {
            pop(arr[ind]);
        }
        cout<<"Enter the index (or -1 to exit): ";
        cin>>ind;
    }
    for(int i=0; i<k; i++) {
        cout<<i<<" stack: ";
        while(arr[i].top > -1) {
            cout<<pop(arr[i])<<" ";
        }cout<<endl;
    }
    return 0;
}