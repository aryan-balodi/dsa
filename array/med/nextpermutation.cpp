#include<iostream>
#include<vector>
using namespace std;

// Brute approach -> consider all sub-arrays and do sum

int brute(vector<int> &arr, int n) {
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum = sum + arr[k];
                maxi = max(sum,maxi);
            }
        }
    }
    return maxi;
}

// Better approach -> do a running sum, no need for the third loop; just store the sum till now in sum and add the current element to it.

int better(vector<int> &arr, int n) {
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum = sum + arr[j];
            maxi = max(maxi,sum);
        }
    }
    return maxi;

}

// Optimal approach -> kadane's algo
// iterate in the array and reset the sum if sum is -ve as a -ve number cannot contribute to "MAXIMUM SUM".

vector<int> optimal(vector<int> &arr, int n) {
    int maxi = INT_MIN;
    int sum = 0;
    int ansStart = -1; int ansEnd = -1; int start = -1;
    for (int i = 0; i < n; i++) {
        if (sum == 0) start = i;
        sum = sum + arr[i];

        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0) {
            sum = 0;
        }
    }
    return {maxi,ansStart, ansEnd};
}

int main() {
    int n;
    cout << "Enter the number of elements you wish the input array to have: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the input array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string choice;
    cout << "Enter 'brute' for brute approach, 'better' for better approaach or 'optimal' for optimal approach: ";
    cin >> choice;

    int answer;

    if(choice == "brute") {
        answer = brute(arr,n);
        cout << "The maximum subarray sum is: " << answer << endl;
    }
    else if (choice == "better") {
        answer = better(arr,n);
        cout << "TThe maximum subarray sum is:: " << answer << endl;
    }
    else if (choice == "optimal") {
        vector<int> answer_optimal = optimal(arr,n);
        int maxSum = answer_optimal[0];
        int start = answer_optimal[1];
        int end = answer_optimal[2];
        cout << "The maximum subarray sum is: " << maxSum << endl;
        cout << "The elements of the sub-array are: [ ";
        for (int i = start; i <= end; i++) {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
    }
    else {
        cout << "Invalid choice; please choose between 'brute', 'better' and 'optimal' ONLY.";
    }

    return 0;

}