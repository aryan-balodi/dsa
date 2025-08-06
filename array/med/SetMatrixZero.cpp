#include<iostream>
#include<vector>
using namespace std;

void markRow (int row, vector<vector<int>> &matrix) {
    int i = row;
    int n = matrix[0].size();
    for (int j = 0; j < n; j++) {
        if(matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

void markCol (int col, vector<vector<int>> &matrix) {
    int j = col;
    int m = matrix.size();
    for (int i = 0; i < m; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> brute (vector<vector<int>> &matrix, int m, int n) {
    // int m = matrix.size();
    // int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                markRow(i,matrix);
                markCol(j,matrix);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}


vector<vector<int>> better (vector<vector<int>> &matrix, int m, int n) {
    // int m = matrix.size();
    // int n = matrix[0].size();

    vector<int> row(n,0);
    vector<int> col(m,0);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row[j] = 1;
                col[i] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[j] == 1 || col[i] == 1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;

}

vector<vector<int>> optimal (vector<vector<int>> &matrix, int m, int n) {
    // int m = matrix.size();
    // int n = matrix[0].size();

    // vector<int> row(n,0) -> matrix[0][j]
    // vector<int> col(m,0) -> matrix[i][0]

    int col0 = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;

                if (j != 0) {
                    matrix[0][j] = 0;
                }
                else {
                    col0 = 0;
                }

            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] != 0) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if (matrix[0][0] == 0) {
        for (int i = 0; i < n; i++) matrix[0][i] = 0;
    }
    if (col0 == 0) {
        for (int j = 0; j < m; j++) matrix[j][0] = 0;
    }

    return matrix;
}


int main () {
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

    string choice;
    cout << "Enter 'brute' for brute approach, 'better' for better approaach or 'optimal' for optimal approach: ";
    cin >> choice;

    vector<vector<int>> answer;

    if(choice == "brute") {
        answer = brute(matrix,m,n);
        cout << "The set zero matrix is: "<< endl;
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (choice == "better") {
        answer = better(matrix,m,n);
        cout << "The set zero matrix is: "<< endl;
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (choice == "optimal") {
        answer = optimal(matrix,m,n);
        cout << "The set zero matrix is: "<< endl;
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Invalid choice; please choose between 'brute', 'better' and 'optimal' ONLY.";
    }
    
    return 0;
}