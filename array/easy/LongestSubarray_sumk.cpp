#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Brute approach 1 -> TC: n^3 
int LSA_a(vector<int> &arr, int n, long long k) {
    int maxLen = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            long long sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if (sum == k)  {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

// Brute approach 2 -> TC: n^2

int LSA_b(vector<int> &arr, int n, long long k) {
    int maxLen = 0;
    for(int i = 0; i < n; i++) {
        long long sum = 0;
        for(int j = i; j < n; j++) {
                sum += arr[j];
            if (sum == k)  {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

// Better approach using a hashmap

int LSA_better(vector<int> &arr, int n, long long k) {
    int maxLen = 0;
    map<long long, int> m;
    long long sum = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }
    
        long long x = sum - k;
        if(m.find(x) != m.end()) {
            int len = i - m[x];
            maxLen = max(maxLen, len);
        }
        if(m.find(sum) == m.end()) {
            m[sum] = i;
        }
    }
    return maxLen;
}

// Optimal approach, only possible when all positive

int LSA_optimal(vector<int> &arr, int n, long long k) {
    int right = 0, left = 0;
    long long sum = arr[0];
    int maxLen = 0;

    while(right < n) {
        while(left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n) {
            sum += arr[right];
        }
        
    }
    return maxLen;
}

int main() {
    int n;
    cout << "Enter the number of elements you wish the array to have: ";
    cin >> n;

    long long k;
    cout << "Enter target sum: ";
    cin >> k;

    vector<int> arr(n);
    cout << "Enter the elements of the input array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string choice;
    cout << "Please choose between 'br_1', 'br_2', 'bt' or 'o' for brute_1, brute_2, better or optimal approach: ";
    cin >> choice;

    int answer;

    if (choice == "br_1") {
        answer = LSA_a(arr,n,k);
    } else if (choice == "br_2") {
        answer = LSA_b(arr,n,k);
    } else if (choice == "bt") {
        answer = LSA_better(arr,n,k);
    } else if (choice == "o") {
        answer = LSA_optimal(arr,n,k);
    }else {
        cout << "Invalid choice! Please choose between 'br_1', 'br_2', 'bt' or 'o' only.";
        return 1;
    }

    cout << "The length of the longest subarray with the provided target sum is: " << answer << endl;

    return 0;

}