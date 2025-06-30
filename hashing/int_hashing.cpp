#include<iostream>
using namespace std;

// if we declare array gloabally then we can declare teh array of size 10^7.
// ex: int arr[1e7]; no need to initialise it with = {0}; as when declared gloabally no garbage value is assigned.

int main() {
    int n;
    cout << "Enter the number of elements to be in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // precompute
    int hash[13] = {0}; // if we declare array inside main fn then maximum size is 10^6.
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    }


    int q;
    cout << "Enter the number of digits for whom you want to check the frequency: ";
    cin >> q;

    while(q--){
        int number;
        cin >> number;
        // fetch 
        cout << hash[number] << endl;
    }
    return 0;
}
    