#include<iostream>
#include<vector>
using namespace std;

vector<int> unequal_pos_and_neg(vector<int> &arr, int n) {
    vector<int> pos; vector<int> neg;
    for (int i = 0; i < n; i++) {
        
        if (arr[i] > 0) {
            pos.push_back(arr[i]);
        }
        else {
            neg.push_back(arr[i]);
        }
    }
    if (pos.size() > neg.size()) {
        for (int i = 0; i < neg.size(); i++) {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }

        int index = 2 * neg.size();
        // iterating in the pos array.
        for (int i = neg.size(); i < pos.size(); i++) {
            arr[index] = pos[i];
            index++;
        }
    }
    else {
        for (int i = 0; i < pos.size(); i++) {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }

        int index = 2 * pos.size();
        // iterating in the neg array.
        for (int i = pos.size(); i < neg.size(); i++) {
            arr[index] = neg[i];
            index++;
        }
    }
    return arr;
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

    unequal_pos_and_neg(arr,n);

    cout << "The array rearranged by sign is as follows: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}