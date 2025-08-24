#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// it takes 1 unit of time to paint 1 unit of length on the board.
// each painter needs to have atleast one board to paint. i.e painter canot be idle.
// the boards assigned to a painter need to be contiguous.

// we need to minimize the maximum time taken to paint the boards.

int noOfPainters(vector<int> &arr, int n, int length) {
    int painters = 1;
    int length_per_painter = 0;
    for (int i = 0; i < n; i++) {
        if(length_per_painter + arr[i] <= length) {
            length_per_painter += arr[i];
        }
        else {
            painters++;
            length_per_painter = arr[i];
        }
    }
    return painters;
}

int paintersPartition(vector<int> &arr, int n, int k) {
    if (k > n) return -1;
    // minimum time taken will be equal to the length of the longest board.
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int paintersNeeded = noOfPainters(arr,n,mid);
        if (paintersNeeded > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    int n;
    cout << "Enter the number of boards to be painted: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the length of each board to be painted: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the number of painters: ";
    cin >> k;

    cout << "The maximum length to be painted by a painter such that the time taken is minimum is: " << paintersPartition(arr,n ,k) << endl;

    return 0;

}