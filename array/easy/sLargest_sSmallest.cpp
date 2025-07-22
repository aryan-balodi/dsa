#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int sLargest(vector<int> &arr, int n) {
    int largest = arr[0];
    int sLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            sLargest = largest;
            largest = arr[i];
        }else if (arr[i] > sLargest && arr[i] < largest) {
        sLargest = arr[i];
        }
    }
    return (sLargest == INT_MIN) ? -1 : sLargest;
}

int sSmallest(vector<int> &arr, int n) {
    int smallest = arr[0];
    int sSmallest = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            sSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] > smallest && arr[i] < sSmallest){
            sSmallest = arr[i];
        }
        
    }
    return (sSmallest == INT_MAX) ? -1 : sSmallest;
}

vector<int> GetSecondOrderElements(vector<int> &arr, int n) {
    int slargest = sLargest(arr, n);
    int ssmallest = sSmallest(arr, n);
    return {slargest, ssmallest};
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

    vector<int> result = GetSecondOrderElements(arr, n);
    cout << "{ ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << "}";
    cout << endl;

    return 0;

}
    
