#include<iostream>
#include<vector>
using namespace std;

int LB (vector<int> &arr, int n, int x) {
    int ans = n;
    int low = 0; int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = low + 1;
        }
    }
    return ans;
}

int UB (vector<int> &arr, int n, int x) {
    int ans = n;
    int low = 0; int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = low + 1;
        }
    }
    return ans;
}

vector<int> ranger(vector<int> &arr, int n, int x) {
    int lb = LB(arr,n,x);
    if (lb == n || arr[lb] != x) return {-1,-1};
    return {lb, UB(arr,n,x) - 1};

}


int main() {
    int n;
    cout << "Enter the number of elements of the input array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the input array in the sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    } 

    int x;
    cout << "Enter the target element 'x' for which we need to find the first and last index positions: ";
    cin >> x;

    vector<int> answer = ranger(arr,n,x);
    cout << "The first and last occourance of the target element in the input array are as follows: " << "[ ";
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << "]";
    cout << endl;

    return 0;
}