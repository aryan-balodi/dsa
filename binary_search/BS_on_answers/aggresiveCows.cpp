#include<iostream>
#include<vector>
using namespace std;

bool CanPlace(vector<int> &stalls, int dist, int cows) {
    int count_cows = 1; 
    int last = stalls[0];
    for (int i = 0; i < stalls.size(); i++) {
        if (stalls[i] - last >= dist) {
            count_cows += 1;
            last = stalls[i];
        }
        if (count_cows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    int low = 1; int high = stalls[stalls.size() - 1] - stalls[0];
    while (low <= high) {
        int mid = (low + high) / 2;
        if (CanPlace(stalls,mid,k) == true) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        } 
    }
    return high;
}

int main () {
    int n;
    cout << "Enter the number of stalls you wish to keep: ";
    cin >> n;

    vector<int> stalls(n);
    cout << "Enter the position of each stall: ";
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    int k;
    cout << "Enter the number of cows that we need to place: ";
    cin >> k;

    cout << "The maximum value of the minimum distance between the cows is: " << aggressiveCows(stalls,k) << "." << endl;
}