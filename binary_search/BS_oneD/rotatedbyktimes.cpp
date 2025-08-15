#include<iostream>
#include<vector>
using namespace std;

int roatated_by_K(vector<int> &nums, int n) {
    int answer = INT_MAX;
    int index = -1;
    int low = 0; int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[low] <= nums[high]) {
            if (answer > nums[low]) {
                answer = nums[low];
                index = low;
            }
            break;
        }
        if (nums[low] <= nums[mid]) {
            if (answer > nums[low]) {
                answer = nums[low];
                index = low;
            }
            low = mid + 1;
        }
        else {
            if (answer > nums[mid]) {
                answer = nums[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}

int main() {
    int n;
    cout << "Enter the number of elements you wish the input array to have: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the input array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "The input sorted array has been rotated by " << roatated_by_K(nums,n) << " times." << endl;

    return 0;
}