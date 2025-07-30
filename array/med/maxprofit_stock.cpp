#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> &arr, int n) {
    int mini = arr[0];
    int maxprofit = 0;
    for (int i = 1; i < n; i++) {
        int cost = arr[i] - mini;
        maxprofit = max(cost, maxprofit);
        mini = min(mini, arr[i]);
    }
    return maxprofit;
}

int main() {
    int n;
    cout << "Enter the number of elements you wish the input array to have: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the input elements for the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int answer;
    answer = maxProfit(arr,n);
    cout << "The maximum profit is: " << answer << endl;

    return 0;
}