#include <iostream>
#include <vector>
using namespace std;

void left_rotate(vector<int> &arr, int n) {
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n-1] = temp;

}

int main() {
    int n;
    cout << "Enter the number of elements you wish the array to have: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    left_rotate(arr,n);

    cout << "Array after left rotation : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

}