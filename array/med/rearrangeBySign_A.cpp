#include<iostream>
#include<vector>
using namespace std;

vector<int> brute(vector<int> & arr, int n) {
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            pos.push_back(arr[i]);
        }
        else {
            neg.push_back(arr[i]);
        }
    }

    for (int i = 0; i < n/2; i++) {
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }

    return arr;
}

vector<int> optimal(vector<int> &arr, int n) {
    int posIndex = 0; int negIndex = 1;
    vector<int> res(n,0);
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) {
            res[posIndex] = arr[i];
            posIndex += 2;
        }
        else {
            res[negIndex] = arr[i];
            negIndex += 2;
        }
    }
    return res;
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

    if(choice == "brute") {
        vector<int> answer(n);
        answer = brute(arr,n);
        cout << "The array rearranged by sign is as follows: ";
        for (int i = 0; i < n; i++) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    else {
        vector<int> answer(n);
        answer = optimal(arr,n);
        cout << "The array rearranged by sign is as follows: ";
         for (int i = 0; i < n; i++) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }

    return 0;
}