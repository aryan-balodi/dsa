#include<iostream>
#include<vector>
using namespace std;

int Floor(vector<int> &arr, int n, int x) {
    int low = 0; int high = n - 1;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < x) {
            ans = arr[mid];
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

// same as lower bound
int Ciel (vector<int> &arr, int n, int x)  {
    int low = 0; int high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
            ans = arr[mid];
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}
    


int main() {
    int n;
    cout << "Enter the number of elements of the input array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the input array in the sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    } 

    int x;
    cout << "Enter the target element 'x' for which we need to find the floor or ciel: ";
    cin >> x;

    cout << "Choose an option:\n";
    cout << "1. Find out the floor\n";
    cout << " OR \n";
    cout << "2. Find out the ciel \n";
    cout << "Enter your choice (1 or 2): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "The index position of the target element is: " << Floor(arr,n,x) << endl;
    }
    else if (choice == 2) {
       cout << "The index position of the target element is: " << Ciel(arr,n,x) << endl;
    }
    else {
        cout << "Invalid choice." << endl;
    }

}