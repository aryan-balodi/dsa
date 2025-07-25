#include<iostream>
#include<vector>
using namespace std;

// Brute - approach is merge sort; TC -> N log N

// Better-approach -> counting number of 0's, 1's and 2's and then placing them manually.

void sort_better(vector<int> &arr, int n) {
    int count_0 = 0; int count_1 = 0; int count_2 = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0){
            count_0++;
        }
        else if(arr[i] == 1) {
            count_1++;
        }
        else{
            count_2++;
        }
    }

        for(int i = 0; i < count_0; i++) {
            arr[i] = 0;
        }
        for(int i = count_0; i < count_0 + count_1; i++) {
            arr[i] = 1;
        }
        for(int i = count_0 + count_1; i < n; i++) {
            arr[i] = 2;
        }
}

void sort_optimal(vector<int> &arr, int n) {
    int low = 0; int mid = 0; int high = n - 1;
    
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements you wish the inout array to have: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the input array (only 0, 1 or 2): ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string choice;
    cout << "Enter 'better' for better approaach or 'optimal' for optimal approach: ";
    cin >> choice;

    if (choice == "better") {
        sort_better(arr,n);
        cout << "The sorted array is as follows: " << endl;
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else if (choice == "optimal") {
        sort_optimal(arr,n);
        cout << "The sorted array is as follows: " << endl;
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Invalid choice; please choose between 'better' and 'optimal' ONLY.";
    }
    
    return 0;
}