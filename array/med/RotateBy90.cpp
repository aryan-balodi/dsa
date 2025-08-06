#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

vector<vector<int>> brute (vector<vector<int>> &matrix,int n) {
    vector<vector<int>> answer(n,vector<int>(n));
    // int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer[j][(n-1)-i] = matrix[i][j];
        }
    }
    return answer;
}


vector<vector<int>> optimal (vector<vector<int>> &matrix,int n) {
    // int n = matrix.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return matrix;
}

int main() {
    int n;
    cout << "Enter the dimension of the n x n input matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements of the input array. (row-wise):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    string choice;
    cout << "Enter 'brute' for brute approach or 'optimal' for optimal approach: ";
    cin >> choice;

    vector<vector<int>> ans;

    if(choice == "brute") {
        ans = brute(matrix,n);
        cout << "The rotated matrix is: "<< endl;
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (choice == "optimal") {
        ans = optimal(matrix,n);
        cout << "The rotated matrix is: "<< endl;
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Invalid choice; please choose between 'brute' and 'optimal' ONLY." << endl;
    }
    
    return 0;
}