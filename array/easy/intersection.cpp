#include<iostream>
#include<vector>
using namespace std;

// {considering teh fact that the arrays are sorted}

// Brute-approach

vector<int> Brute_Intersection(vector<int> &A, int n, vector<int> &B, int m) {
    vector<int> answer;
    vector<int> visited(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j] && visited[j] == 0) {
                answer.push_back(A[i]);
                visited[j] = 1;
                break;
            }
            if (B[j] > A[i]) break;
        }
    }
    return answer;
}

// Optimal-approach 

vector<int> Optimal_Intersection(vector<int> &A, int n, vector<int> &B, int m) {
    int i = 0;
    int j = 0;
    vector<int> answer;

    while (i < n && j < m) {
        if (A[i] < B[j]) {
            i++;
        }else if (B[j] < A[i]) {
            j++;
        }else {
            answer.push_back(A[i]);
            i++;
            j++;
        }
    }
    return answer;
}



int main() {
    int n;
    cout << "Enter the number of elements you want the first array to have: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the elements of the first array: ";
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int m;
    cout << "Enter the number of elements you wish the second array to have: ";
    cin >> m;

    vector<int> B(m);
    cout << "Enter the elements of the second array: ";
    for(int i = 0; i < m; i++) {
        cin >> B[i];
    }

    char choice;
    cout << "Please choose between 'b' or 'o' for brute or optimal approach: ";
    cin >> choice;

    vector<int> intersection_array;

    if (choice == 'b') {
        intersection_array = Brute_Intersection(A,n,B,m);
    } else if (choice == 'o') {
        intersection_array = Optimal_Intersection(A,n,B,m);
    } else {
        cout << "Invalid choice! Please choose between 'o' and 'b' only.";
        return 1;
    }
    
    cout << "The final array after performing intersection on the two input arrays is as follows: ";
    for(int i = 0; i < intersection_array.size(); i++) {
        cout << intersection_array[i] << " ";
    }
    cout << endl;

    return 0;
}