#include<bits/stdc++.h>
using namespace std;

struct stack_ {
    int top;
    int size;
    int elements[50];
    void push(int n) {
        if (top == size - 1) {
            cout<<"Stack full";
        } else {
            elements[++top] = n;
        }
    }
    int pop() {
        if (top == -1) {
            cout<<"Stack Empty";
            return 0;
        } else {
            return elements[top--];
        }
    }
    int peek() {
        if (top == -1) {
            cout<<"Stack Empty";
            return 0;
        } else {
            return elements[top];
        }
    }
};

void sort_stack(struct stack_ &S1, struct stack_ &S2){
    int n = S1.top;
    for (int i=0; i<n; i++) {
        int max = -10000;
        while (S1.top >= i) {
            if (max < S1.peek()){
                max = S1.peek();
            }
            S2.push(S1.pop());
        }
        S1.push(max);
        while (S2.top >= 0){
            if (S2.peek() != max) {
                S1.push(S2.pop());
            } else {
                S2.pop();
            }
        }
    }
}

void brack_calc(int arr[], int n) {
    bool done = false;
    while (!done) {
        done = true;
        for (int i=0; i<n; i++) {
            if (arr[i] == -1) {
                done=false;
                break;
            }
        }
        int l = -1, h = -1;
        for(int i=0; i<n; i++) {
            if (arr[i] == -1) {
                l = i;
            }
            if (arr[i] == -2) {
                if( l != -1){
                    h = i;
                    if (h == l+1) {
                        arr[l] = 1;
                        arr[h] = 0;
                    } else {
                        arr[l] = 2*arr[l+1];
                        arr[l+1] = 0;
                        arr[h] = 0;
                    }
                    l = -1;
                }
            }
        }
        for (int i=0; i<n-1; i++) {
            if (arr[i] >= 0) {
                int j=i+1, sum=arr[i];
                while (arr[j] >= 0 && j<n){
                    sum += arr[j];
                    arr[j] = 0;
                    j++;
                }
                arr[i] = sum;
            }
        }
    }
    cout<<arr[0]<<endl;
}

void bracket_calculation(string s) {
    int arr[100];
    for (int i=0; i<s.length(); i++){
        if (s[i] == '('){
            arr[i] = -1;
        } else if (s[i] == ')') {
            arr[i] = -2;
        }
    }
    brack_calc(arr, s.length());
}

int slide_window_max(int A[], int B, int n) {
    int max = 0, x;
    for (int i=0; i<=n-B; i++) {
        int min = A[i]; 
        for (int j=i; j<i+B; j++) {
            if (min > A[j]) {
                min = A[j];
            }
        }
        x = B * min;
        if (max < x) {
            max = x;
        }
    }
    return max;
}

int max_area(int A[], int n) {
    int max = 0;
    for (int i=1; i<n; i++) {
        int x = slide_window_max(A, i, n);
        if (max < x) {
            max = x;
        }
    }
    return max;
}

void slide_window(int A[], int B, int n) {
    int C[100];
    int k=0;
    if (B > n) {
        int max = A[0];
        for (int i=0; i<n; i++) {
            if (max < A[i]) {
                max = A[i];
            }
        }
        cout<<max<<endl;
        return;
    }
    for (int i=0; i<=n-B; i++) {
        int max = A[i]; 
        for (int j=i; j<i+B; j++) {
            if (max < A[j]) {
                max = A[j];
            }
        }
        C[k++] = max;
    }
    for (int i = 0; i < n-B+1; i++)
    {
        cout<<C[i]<<" ";
    }
    cout<<endl;
    return;
}

void reverse_stack(struct stack_ &S, int i, int n2) {
    if (S.top == i) {
        return;
    }
    int a = S.pop();
    int b = S.pop();
    S.push(a);
    reverse_stack(S, i ,n2);
    S.push(b);
    if (S.top == n2-1) {
        if (i >= n2-1) {
            return;
        }
        reverse_stack(S, i+1, n2);
    } 
}

int main() {
    struct stack_ S1;
    struct stack_ S2;
    S1.top = -1;
    S2.top = -1;
    S1.size = 15;
    S2.size = 15;
    int n, num;
    cout<<"Enter number of elements: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>num;
        S1.push(num);
    }
    sort_stack(S1, S2);
    while (S1.top > -1) {
        cout<<S1.pop()<<" ";
    }cout<<endl;
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    bracket_calculation(s);
    cout<<endl;
    int A[100], B;
    n = 0;
    cout<<"Enter number of elements: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    cout<<max_area(A, n)<<endl;
    int A1[100], B1;
    n = 0;
    cout<<"Enter number of elements: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>A1[i];
    }
    cout<<"Enter window size: ";
    cin>>B1;
    slide_window(A1, B1, n);
    struct stack_ S3;
    S3.top=-1;
    S3.size=15;
    cout<<"Enter number of elements: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>num;
        S3.push(num);
    }
    reverse_stack(S3, 0, n);
    cout<<"Reversal = ";
    while (S3.top > -1) {
        cout<<S3.pop()<<" ";
    }cout<<endl;
    return 0;
}