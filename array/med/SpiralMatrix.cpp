#include<iostream>
#include<vector>
using namespace std;

vector<int> Spiral (vector<vector<int>> & matrix, int m, int n) {
    int left = 0; int top = 0;
    int right = n - 1; int bottom = m - 1;
    
    vector<int> answer;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            answer.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            answer.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                answer.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                answer.push_back(matrix[i][left]);
            } 
            left++;
        }  
    }
    return answer;
}

int main() {
    int m;
    cout << "Enter the number of rows you wish the input matrix to have: ";
    cin >> m;

    int n;
    cout << "Enter the number of columns you wish the input matrix to have: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the elements for the input matrix (row-wise):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "The input matrix printed out in the spiral manner is as follows: " << endl;
    vector<int> ans = Spiral(matrix,m,n);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0; 
}