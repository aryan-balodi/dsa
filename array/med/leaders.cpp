#include<iostream>
#include<vector>
using namespace std;

vector<int> Leaders_brute(vector<int> &arr, int n) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        bool leader = true;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                leader = false;
                break;
            }
        }
        if (leader == true) {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

vector<int> Leader_optimal(vector<int> &arr, int n) {
    int maxi = INT_MIN;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > maxi) {
            ans.push_back(arr[i]);
        }
        maxi = max(maxi,arr[i]);
    }
    sort(ans.begin(), ans.end());

    return ans;
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
    cout << "Enter 'brute' for brute approach or 'optimal' for optimal approach: ";
    cin >> choice;

    if (choice == "brute") {
        vector<int> answer;
        answer = Leaders_brute(arr,n);
        cout << "The leaders of the input array are as follows: ";
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    else if (choice == "optimal") {
        vector<int> answer;
        answer = Leader_optimal(arr,n);
        cout << "The leaders of the input array are as follows: ";
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Invalid choice; please choose between 'brute' and 'optimal' ONLY.";
    }

    return 0;

}