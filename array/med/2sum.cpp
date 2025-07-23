#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Better approach using hash map

string Two_Sum (vector<int> &arr, int n, int target) {
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        int more_needed = target - arr[i];
        if(mpp.find(more_needed) != mpp.end()) {
            return "YES";
        }
        mpp[arr[i]] = i;
    }
    return "NO";
}

int main() {
    int n;
    cout << "Enter the length of the input array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the input array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target sum that we need to check: ";
    cin >> target;

    string answer;

    answer = Two_Sum(arr,n,target);

    cout << "Wether or not the two sum exists is -> " << answer << endl;

    return 0;

}