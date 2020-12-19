#include<iostream>
using namespace std;

union Uni {
    char cno[10];
    int hno;
};

struct stdu {
    int rno;
    int tag;
    union Uni adr;
};

int main(){
    struct stdu *S[5];
    for (int i=0; i<5; i++) {
        S[i] = new(stdu);
        cout<<"Enter Roll Number: ";
        cin>>S[i] -> rno;
        cout<<"Press 0 for number and 1 for string (10 char atmost): ";
        cin>>S[i] -> tag;
        if (S[i]->tag == 0) {
            cout<<"Enter Address Number: ";
            cin>>S[i] -> adr.hno;
        } else {
            cout<<"Enter Address String: ";
            cin>>S[i] -> adr.cno;
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"RollNo\t\tTag\t\tAddress\n";
    for (int i=0; i<5; i++) {
        cout<<S[i] -> rno<<"\t\t"<<S[i] -> tag<<"\t\t";
        if (S[i]->tag == 0) {
            cout<<S[i] -> adr.hno;
            cout<<endl;
        } else {
            cout<<S[i] -> adr.cno;
            cout<<endl;
        }
    }
    return 0;
}
