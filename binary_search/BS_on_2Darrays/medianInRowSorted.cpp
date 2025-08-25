#include<iostream>
#include<vector>
using namespace std;

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0; int high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int count_Smaller_and_Equal(vector<vector<int>> &matrix, int m, int n, int x) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        count += upperBound(matrix[i], x, n);
    }
    return count;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX; int high = INT_MIN;
    for (int i = 0; i < m; i++) {
        low = min(matrix[i][0], low);
        high = max(matrix[i][n - 1], high);
    }
    int req = (m * n) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallerEquals = count_Smaller_and_Equal(matrix,m,m,mid);
        if (smallerEquals <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main() {
    int m;
    cout << "Enter the number of rows of the input matrix: ";
    cin >> m;

    int n;
    cout << "Enter the number of columns in the input matrix: ";
    cin >> n;

    vector<vector<int>> matrix(m,vector<int> (n));
    cout << "Enter the elements of the inpur matrix in ROW-WISE sorted order: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "The median of the row wise sorted matrix is: " << median(matrix,m,n) << endl;

    return 0;

}