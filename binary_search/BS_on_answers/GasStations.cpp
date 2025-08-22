// Minimizing the maximum distance between gas stations by placing "k" gas stations anywhere between the exisitng gas stations.

#include<iostream>
#include<vector>
using namespace std;

// brute-approach -> WILL GIVE TLE as TC -> O(k * n) + O(n)
long double brute_minimizeMaxDistance(vector<int> &arr, int n, int k) {
    vector<int> howMany(n-1,0); 
    for (int gasStations = 1; gasStations <= k; gasStations++) {
        long double maxSection = -1; int maxInd = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = (long double) diff / (howMany[i] + 1);
            if (sectionLength > maxSection) {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }

    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++) {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength = (long double) diff / (howMany[i] + 1);
        maxAns = max(sectionLength,maxAns);
    }
    return maxAns;
}


// better approach using a priority-queue

long double better_minimizeMaxDistance(vector<int> &arr, int n, int k) {
    vector<int> howMany(n-1,0);
    priority_queue<pair<long double, int>> pq;
    for (int i = 0; i < n - 1; i++) {
        pq.push({arr[i + 1] - arr[i], i});
    }
    for (int gasStation = 1; gasStation <= k; gasStation++) {
        auto tp = pq.top(); pq.pop();
        int sec_Index = tp.second;
        howMany[sec_Index]++;
        long double inital_sec_diff = arr[sec_Index + 1] - arr[sec_Index];
        long double new_sec_diff = inital_sec_diff / (long double) (howMany[sec_Index] + 1);
        pq.push({new_sec_diff, sec_Index});

    }

    return pq.top().first;
}

// optimal using BS 

int noOfGasStations(vector<int> &arr, int n, long double dist) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        int numberInBw = ((arr[i + 1] - arr[i]) / dist);
        if ((arr[i + 1] - arr[i]) / dist == numberInBw * dist) {
            numberInBw--;
        }
        count += numberInBw;
    }
    return count;
}

long double optimal_minimizeMaxDistance(vector<int> &arr, int n, int k) {
    long double low = 0; long double high = 0;
    for (int i = 0; i < n - 1; i++) {
        high = max((long double) (arr[i + 1] - arr[i]), high);
    }
    
    long double diff = 1e-6;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int count = noOfGasStations(arr,n,mid);
        if (count > k) low = mid;
        else {
            high = mid;
        }
    }
    return high;
}


int main () {
    int n;
    cout << "Enter the number of pre-existing gas stations: ";
    cin >> n;

    int k;
    cout << "Enter the number of gas stations that are to be placed: ";
    cin >> k;

    vector<int> arr(n);
    cout << "Enter the positions of the existing gas-stations: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int choice;
    cout << "Enter the index number of the approach you would like to use: " << endl;
    cout << "1. Brute" << endl;
    cout << "2. Better" << endl;
    cout << "3. Optimal" << endl;
    cout << "Enter your choice -> ";
    cin >> choice;

    long double answer;
    if (choice == 1) {
        answer = brute_minimizeMaxDistance(arr,n,k);
    }
    else if (choice == 2) {
        answer = better_minimizeMaxDistance(arr,n,k);
    }
    else if (choice == 3) {
        answer = optimal_minimizeMaxDistance(arr,n,k);
    }
    else {
        cout << "Invalid Choice!" << endl;
    }


    cout << "The maximum distance between two gas-stations after minimizing them is -> " << answer << endl;

    return 0;
}