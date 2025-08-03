#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

vector<int> Next_Permutation(vector<int> &arr, int n) {
    int index = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
            break;
        }
    }
    if (index == -1) return arr;

    for (int i = n - 1; i > index; i--) {
        if (arr[i] > arr[index]) {
            swap(arr[i], arr[index]);
            break;
        }
    }

    reverse(arr.begin() + index + 1, arr.end());

    return arr;
}

int main() {
    int n;
    cout << "Enter the number of elements you wish the input array to have: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the input array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> answer = Next_Permutation(arr,n);

    cout << "The next permutation of the input array is as follows: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

}