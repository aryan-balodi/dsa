#include<iostream>
#include<vector>
#include<map>
using namespace std;

// brute approach using 2 loops

pair<int, int> Two_Sum_brute_pair(vector<int> &arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                return {i, j};
            }
        }
    }
    return {-1,-1};
}

// brute approach returing "yes" or "no".

string Two_Sum_brute_string(vector<int> &arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) return "YES";
        }
    }
    return "NO";
}

// Better approach using hash map 
// to return yes or no

string Two_Sum_better(vector<int> &arr, int n, int target) {
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

// better approach using hash map
// to return indices

pair<int, int> Two_Sum_betteri(vector<int> &arr, int n, int target) {
    map<int,int> mpp;
    for(int i = 0; i < n; i++) {
        int more_needed = target - arr[i];
        if(mpp.find(more_needed) != mpp.end()) {
            return {mpp[more_needed], i};
        }
        mpp[arr[i]] = i;
    }
    return {-1,-1};
}

// optimal approach only in the case when we have to return "yes" or "no".

string Two_sum_optimal(vector<int> &arr, int n, int target) {
    int left = 0; int right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }else if (sum < target) {
            left++;
        }else {
            right--;
        } 
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

    string choice;
    cout << "Please choose between if you want the response in yes/no or you want the indices. Enter 'string' or 'indices' respectively: ";
    cin >> choice;

    string s_answer;
    pair<int,int> p_answer;

    if (choice == "string") {
        string approach;
        string answer;

        cout << "Please select the approach -> brute, better or optimal; enter 'br', 'bt' or 'o' respectively: ";
        cin >> approach;

        if (approach == "br") {
            s_answer = Two_Sum_brute_string(arr,n,target);
        }else if (approach == "bt") {
            s_answer = Two_Sum_better(arr,n,target);
        }else if (approach == "o") {
            s_answer = Two_sum_optimal(arr,n,target);
        }else{
            cout << "Invalid approach!";
            return -1;
        }
        
        cout << "Wether or not the two sum exists is -> " << s_answer << endl;
    }
    else if (choice == "indices"){
        string approach;
        pair<int,int> answer;

        cout << "Please select the approach -> brute or better; enter 'br' or 'bt' respectively: ";
        cin >> approach;

        if (approach == "br") {
            p_answer = Two_Sum_brute_pair(arr,n,target);
        }else if (approach == "bt") {
            p_answer = Two_Sum_betteri(arr,n,target);
        }else {
            cout << "Invalid approach";
        }
        if (p_answer.first != -1) {
            cout << "The two sum indices are: {" << p_answer.first << ", " << p_answer.second << "}" << endl;
        }else {
            cout << "No valid pair found." << endl;
        }
    }
    
    else {
        cout << "Invalid choice";
    }

    return 0;

}