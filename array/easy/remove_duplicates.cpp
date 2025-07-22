#include <iostream>
#include <vector>
using namespace std;

int remove_duplicates(vector<int> &arr, int n) {
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[i] != arr[j]) {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;

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

    int result = remove_duplicates(arr,n);

    cout << "The number of elements in the array after removing duplicates is -> " << result << endl;

    return 0;
}