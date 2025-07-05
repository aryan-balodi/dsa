#include <iostream>
#include <vector>
using namespace std;

bool isArraySorted(vector<int> &arr, int n) {
    for (int i = 0; i <= n - 2; i++) {
        if (arr[i] > arr[i + 1]){
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool result = isArraySorted(arr, n);
    
    if (result)
        cout << "The array is sorted in increasing order." << endl;
    else
        cout << "The array is NOT sorted in increasing order." << endl;

    return 0;
}