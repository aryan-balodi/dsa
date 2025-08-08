#include<iostream>
#include<vector>
#include<map>
using namespace std;

int brute(vector<int> &arr, int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0; 
            for (int k = i; k <= j; k++) {
                sum = sum + arr[k];
            }
            if (sum == k) {
                count++;
            }
        }
    }
    return count;
}

int better(vector<int> &arr, int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum = sum + arr[j];

            if (sum == k) {
                count++;
            }
        }
    }
    return count;
}


int optimal(vector<int> &arr, int n, int k) {
    map<int,int> mpp;
    mpp[0] = 1;
    int count = 0; int prefixSum = 0;
    for (int i = 0; i < n; i++) {
        prefixSum = prefixSum + arr[i];
        int remaining = prefixSum - k;
        count += mpp[remaining];
        mpp[prefixSum] += 1;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the number of elements you wish the input array to have: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the input array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the target sum value: ";
    cin >> k;
    
    string choice;
    cout << "Enter 'brute' for brute approach, 'better' for better approaach or 'optimal' for optimal approach: ";
    cin >> choice;
    
    int answer;

    if(choice == "brute") {
        answer = brute(arr,n,k);
        cout << "The number of sum-array with sum k are as follows: ";
        cout << answer << endl;
    }
    else if (choice == "better") {
        answer = better(arr,n,k);
        cout << "The number of sum-array with sum k are as follows: ";
        cout << answer << endl;
    }
    else if (choice == "optimal") {
        answer = optimal(arr,n,k);
        cout << "The number of sum-array with sum k are as follows: ";
        cout << answer << endl;
    }
    else {
        cout << "Invalid choice; please choose between 'brute', 'better' and 'optimal' ONLY.";
    }
    
    return 0;
}