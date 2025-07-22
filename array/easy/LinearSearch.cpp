#include <iostream>
#include <vector>
using namespace std;

int LinearSearch(vector<int> &arr, int n, int num) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements you wish the array to have: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i< n; i++) {
        cin >> arr[i];
    }

    int num;
    cout << "Enter the numbr whose occourance you wish to find: ";
    cin >> num;

    int index = LinearSearch(arr,n,num);

    if (index != -1) {
        cout << "Number found ar index: " << index << endl;
    }else {
        cout << "Number not found in the array." << endl;
    }
    return 0;
}