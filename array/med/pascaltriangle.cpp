#include<iostream>
#include<vector>
using namespace std;


int element (int r, int c) {
    long long res = 1;
    for (int i = 0; i < c; i++) {
        res = res * (r - i);
        res = res / (i + 1);
    }
    return res;
}

vector<int> printRow (int row) {
    vector<int> ans;
    long long res = 1;
    ans.push_back(1);
    for (int i = 1; i < row; i++) {
        res = res * (row - i);
        res = res / i;

        ans.push_back(res);
    }
    return ans;   
}

vector<vector<int>> pascalTriangle (int row) {
    vector<vector<int>> answer;
    for (int i = 1; i <= row; i++) {
        answer.push_back(printRow(i));
    }
    return answer;
}


int main() {
    cout << "Choose an option:\n";
    cout << "1. Print a specific element\n";
    cout << "2. Print a specific row\n";
    cout << "3. Print Pascal's Triangle up to n rows\n";
    cout << "Enter your choice (1/2/3): ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        int row, col;
        cout << "Enter row and column to get the element: ";
        cin >> row >> col;
        cout << "Element at (" << row << ", " << col << ") is: " << element(row - 1, col - 1) << endl;
    } else if (choice == 2) {
        int rowNum;
        cout << "Enter the row number to print that row: ";
        cin >> rowNum;
        vector<int> rowVec = printRow(rowNum);
        cout << "Row " << rowNum << ": ";
        for (int num : rowVec) cout << num << " ";
        cout << endl;
    } else if (choice == 3) {
        int n;
        cout << "Enter the number of rows for Pascal's Triangle: ";
        cin >> n;
        vector<vector<int>> triangle = pascalTriangle(n);
        cout << "Pascal's Triangle up to row " << n << ":" << endl;
        for (const auto& row : triangle) {
            for (int num : row) cout << num << " ";
            cout << endl;
        }
    } else {
        cout << "Invalid choice." << endl;
    }
    return 0;
}