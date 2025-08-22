// Minimizing the maximum distance between gas stations by placing "k" gas stations anywhere between the exisitng gas stations.

#include<iostream>
#include<vector>
using namespace std;

// brute-approach -> WILL GIVE TLE as TC -> O(k * n) + O(n)
long double minimizeMaxDistance(vector<int> &arr, int n, int k) {
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

    cout << "The maximum distance between two gas-stations after minimizing them is -> " << minimizeMaxDistance(arr,n,k) << endl;

    return 0;
}