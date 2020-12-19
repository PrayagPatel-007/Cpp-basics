#include<iostream>
using namespace std;


int main() {
    int arr[100];
    int n, choice;
    cout<<"Enter number of elements: ";
    cin>>n;
    int l=0;
    int h=n-1;
    for (int i=0; i<n; i++){
        cout<<"Press 1 for end and 0 for beginning: ";
        cin>>choice;
        cout<<"Enter Number: ";
        if (choice == 0){
            cin>>arr[l];
            l++;
        } else {
            cin>>arr[h];
            h--;
        }
    }
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}