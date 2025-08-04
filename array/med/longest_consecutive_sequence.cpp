#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

bool linear_search(vector<int> &arr, int num) {
    bool answer;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == num) {
            return true;
        }
    }
    return false;
}

int brute(vector<int> &arr, int n) {
    int longest = 1;
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        int count = 1;
        while(linear_search(arr, x + 1) == true) {
            count  = count + 1;
            x = x + 1;
        }
        longest = max(longest, count);
    }
    return longest;
}

int better(vector<int> &arr, int n) {
    if (n == 0) return 0;
    sort(arr.begin(), arr.end());
    int lastsmaller = INT_MIN; int longest = 1; int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] - 1 == lastsmaller) {
            count = count + 1;
            lastsmaller = arr[i];
        }
        else if (arr[i] != lastsmaller) {
            count = 1;
            lastsmaller = arr[i];
        }
        longest = max(longest, count);
    }
    return longest;
}

int optimal(vector<int> &arr, int n) {
    if(n == 0) return 0;
    unordered_set<int> st;
    int longest = 1;
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);
    }

    for (auto it : st) {
        if (st.find(it - 1) == st.end()) {
            int count = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                count = count + 1;
            }
            longest = max(count, longest);
        }
    }
    return longest;
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
        cout << "The longest consecutive sequence in the input array is: " << answer << endl;
    }
    else if(choice == "better"){
        answer = better(arr,n);
        cout << "The longest consecutive sequence in the input array is: " << answer << endl;
    }
    else if (choice == "optimal"){
        answer = optimal(arr,n);
        cout << "The longest consecutive sequence in the input array is: " << answer << endl;
    }
    else {
        cout << "Invalid choice; please choose between 'brute', 'better' and 'optimal' ONLY.";
    }

    return 0;
}
