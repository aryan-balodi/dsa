#include<iostream>
#include<vector>
using namespace std;


int findMaxConsecutiveOnes(vector<int> &arr, int n) {
    int maxi = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count++;
            maxi = max(maxi, count);
        }else {
            count = 0;
        }
    }
    return maxi;
}


int main() {
    int n;
    cout << "Enter the number of elements you want the first array to have: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the first array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int answer = findMaxConsecutiveOnes(arr,n);

    cout << "Maximum number of consecutive ones in the given array is: " << answer << endl;

    return 0;
}

