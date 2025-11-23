#include<iostream>
using namespace std;

// brute-force approach {using 2 nested loops; creating a window of size k from each index to check the maximum element in each of those windows and appending the max element from each of those windows into an answer vector }
// not the correct solution for big values of K; as u will get TLE.

vector<int> ReturnMax(vector<int> &nums, int k) {
    vector<int> ans;
    for (int i = 0; i <= nums.size() - k; i++) {
        int maxele = nums[i];
        for (int j = i; j < i + k; j++) {
            maxele = max(maxele, nums[j]);
        }
        ans.push_back(maxele);
    }
    return ans;
}


int main() {
    int n;
    cout << "Enter the size of the input array: ";
    cin >> n;


    vector<int> nums(n);
    cout << "Enter the elements of the input array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int k;
    cout << "Enter the value of K: ";
    cin >> k;

    vector<int> answer = ReturnMax(nums,k);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    
    return 0;
}