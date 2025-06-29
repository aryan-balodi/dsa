#include<iostream>
using namespace std;

void rev_array(int i, int arr[], int n){
    if (i >= n/2) return;
    swap(arr[i], arr[n-i-1]);
    rev_array(i + 1, arr, n
    );
}

int main(){
    int n;
    cout << "Enter the number of elements you wish the array to have: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements for the array: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    rev_array(0, arr, n);

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}