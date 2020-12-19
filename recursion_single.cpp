#include<iostream>
using namespace std;

float function(int arr[], int n, int *max, int *min) {
    if (n==0) {
        *max = (arr[0] > *max ? arr[0] : *max);
        *min = (arr[0] < *min ? arr[0] : *min);
        return 0;
    }
    else {
        *min = arr[n-1] < *min ? arr[n-1] : *min;
        *max = arr[n-1] > *max ? arr[n-1] : *max;
        return (float)(arr[n-1] + (n-1)*function(arr, n-1, max, min)) / (float)(n);
    }
}

int main(){
    int arr[5] = {1, 2, 6, 9, 3};
    // float n= 5;
    int max = -10000;
    int min = 10000;
    float average = function(arr, 5, &max, &min);
    // float average = sum / n;
    cout<<min<<" "<<max<<" "<<average;
    return 0;
}