#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of digits that you wish the array to have: ";
    cin >> n;

    int arr[n];
    cout << "Enter the numbers for the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //pre-compute
    map<int, int>mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    int q;
    cout << "Enter the number of querires you wish to ask: ";
    cin >> q;
    while(q--){
        int number;
        cout << "Enter the number who's frequency you wish to check: ";
        cin >> number;
        //fetch
        cout << mpp[number] << endl;
    }
    

    return 0;

}