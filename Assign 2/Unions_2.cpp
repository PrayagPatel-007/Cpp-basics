#include<iostream>
using namespace std;

union Uni{
    int i;
    char c;
};

int main() {
    union Uni arr[100];
    int tags[100];
    int n, choice;
    cout<<"Enter number of elements: ";
    cin>>n;
    int l=0;
    int h = n-1;
    for (int i=0; i<n; i++){
        cout<<"Press 1 for character and 0 for number: ";
        cin>>choice;
        cout<<"Enter Number or Character: ";
        if (choice == 0){
            cin>>arr[l].i;
            tags[l] = 0;
            l++;
        } else {
            cin>>arr[h].c;
            tags[h] = 1;
            h--;
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