#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Brute force approach using 2 for loops.
int ME_brute(vector<int> &arr, int n) {
    int counter = 0;
    for(int i = 0; i< n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) {
                counter++;
            }
        }
        if(counter > n/2) return arr[i];
    }
    return -1;
}

// Better approach using hashmap.

int ME_better(vector<int> &arr, int n) {
    map<int,int> mpp;
    for(int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }
    for(auto it : mpp) {
        if(it.second > n/2) return it.first;
    }
    return -1;
}

// Optimal approach using Moore's voting logic

int ME_optimal(vector<int> &arr, int n) {
    int counter = 0;
    int element;
    for(int i = 0; i < n; i++) {
        if(counter == 0) {
            element = arr[i];
            counter = 1;
        }
        else if(arr[i] == element) {
            counter++;
        }
        else {
            counter--;
        }
    }
    int counter_new = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == element) {
            counter_new++;
        }
    }
    
    if(counter_new > n/2) return element;

    return -1;
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
        answer = ME_brute(arr,n);
        cout << "The majority element if it exists is: " << answer << endl;
    }
    else if (choice == "better") {
        answer = ME_better(arr,n);
        cout << "The majority element if it exists is: " << answer << endl;
    }
    else if (choice == "optimal") {
        answer = ME_optimal(arr,n);
        cout << "The majority element if it exists is: " << answer << endl;
    }
    else {
        cout << "Invalid choice; please choose between 'brute', 'better' and 'optimal' ONLY.";
    }

    return 0;
}