#include<bits/stdc++.h>
using namespace std;

void print(stack<char> S, queue<char> Q){
    int i=0;
    while(!Q.empty()){
        S.push(Q.pop());
        i++;
    }
    while(!S.empty()){
        Q.push(S.pop());
    }
    for(int j=0; j<i; j++){
        S.push(Q.pop());
    }
}

int main(){
    stack<char> S;
    char c;
    cin>>c;
    while(c != '#'){
        S.push(c);
        cin>>c;
    }
    queue<char> Q;
    cin>>c;
    while (c != '#')
    {
        Q.push(c);
        cin>>c;
    }
    return 0;
}