#include<iostream>
using namespace std;

union Uni{
    int i;
    char c;
};

int main() {
    union Uni arr[100];
    int tags[100];
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    for (int i=0; i<n; i++){
        cout<<"Press 1 for character and 0 for number: ";
        cin>>tags[i];
        cout<<"Enter Number or Character: ";
        if (tags[i] == 0){
            cin>>arr[i].i;
        } else {
            cin>>arr[i].c;
        }
    }
    for (int i=0; i<n; i++) {
        if (tags[i] == 0){
            cout<<arr[i].i<<" ";
        }else {
            cout<<arr[i].c<<" ";
        }
    }
    return 0;
}