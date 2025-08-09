#include<iostream>
#include<vector>
using namespace std;

int lower_bound (vector<int> &arr, int n, int x) {
    int low = 0; int high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
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
    cout << "Enter the target element 'x' for which we need to find the lower bound: ";
    cin >> x;

    int answer = lower_bound(arr,n,x);

    cout << "The index position of the element which is the lower bound for 'x' is: " << answer << endl;

    return 0;

}