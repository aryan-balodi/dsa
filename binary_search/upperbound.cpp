#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// how to implement UB in cpp using STL:
// auto ub = upper_bound(start point, end point, target element)
// auto  ub = upper_bound(arr.begin(), arr.end(), x) {this will return an iterator pointing to that index} -> cout << *ub << endl;
// auto  ub = upper_bound(arr.begin(), arr.end(), x) {ub- arr.begin()} -> {substract the beginer iterator to get the index}

int upper_bound (vector<int> &arr, int n, int x) {
    int low = 0; int high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}


int main () {
    int n;
    cout << "Enter the number of elements of the input array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the input array in the sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }  

    int x;
    cout << "Enter the target element 'x' for which we need to find the upper bound: ";
    cin >> x;

    // int answer = upper_bound(arr,n,x);

    auto ub = upper_bound(arr.begin(), arr.end(), x);

    cout << "The index position of the element which is the upper bound for 'x' is: " << ub - arr.begin() << endl;

    return 0;

}