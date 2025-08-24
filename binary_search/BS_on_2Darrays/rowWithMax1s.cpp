#include<iostream>
#include<vector>
using namespace std;

int lowerBound(vector<int> &row, int m, int x) {
    int low = 0; int high = m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (row[mid] >= x) high = mid - 1;
        else {
            low = mid + 1;
        }
    }
    return low;
}

int rowWithMaxOnes(vector<vector<int>> &matrix, int m, int n) {
    int max_count = 0; int index = -1;
    for (int i = 0; i < m; i++) {
        int ones_in_currentRow = m - lowerBound(matrix[i],matrix[i].size(),1);
        if (ones_in_currentRow > max_count) {
            max_count = ones_in_currentRow;
            index = i;
        }
    }
    return index;
}


int main() {
    int m;
    cout << "Enter the number of rows in the matrix: ";
    cin >> m;

    int n;
    cout << "Enter the number of column in the matrix: ";
    cin >> n;

    vector<vector<int>> matrix(m,vector<int>(n));
    cout << "Enter the elements of the matrix ROW-WISE: " << endl;
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "The index of the row in the input matrix that has the maximum number of one's is: " << rowWithMaxOnes(matrix,m,n) << endl;

    return 0;
}