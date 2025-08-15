#include<iostream>
#include<vector>
using namespace std;

int iterative(vector<int> arr, int n, int target) {
    int low = 0; int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        else if (target > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int bs(vector<int> & arr, int n, int low, int high, int target) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == target) return mid;
    else if (target > arr[mid]) {
        return bs(arr, n, mid + 1, high,target);
    }
    else {
        return bs(arr, n, low, mid - 1, target);
    }


}

int recursive(vector<int> &arr, int n, int target) {
    return bs(arr, n, 0, n - 1, target);
}


int main() {
    int n;
    cout << "Enter the number of elements you want the input array to have: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements for the input array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the number who's index position you wish to find: ";
    cin >> target;

    cout << "Choose an option:\n";
    cout << "1. Iterative approach for binary search\n";
    cout << " OR \n";
    cout << "2. Recursive approach for for binary search \n";
    cout << "Enter your choice (1 or 2): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "The index position of the target element is: " << iterative(arr,n,target) << endl;
    }
    else if (choice == 2) {
       cout << "The index position of the target element is: " << recursive(arr,n,target) << endl;
    }
    else {
        cout << "Invalid choice." << endl;
    }

    return 0; 
}