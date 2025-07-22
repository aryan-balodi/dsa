#include <iostream>
#include <vector>
using namespace std;


int returnLargestElement(vector<int> &arr, int n) {
    int largest = arr[0];
    for (int i = 0; i < n; i++){
        if(arr[i] > arr[largest]) {
            largest = arr[i];
        }
    }

    return largest;
}

int main() {
    int n;
    cout << "Enter the number of elements you wish the input array to have: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << returnLargestElement(arr, n) << endl;



}