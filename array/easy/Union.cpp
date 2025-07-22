#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Brute-Approach.

vector<int> Union(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    
    set<int> s;
    for (int i = 0; i < n1; i ++) {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < n2; i++) {
        s.insert(arr2[i]);
    }

    vector<int> union_array;
    for (auto it : s) {
        union_array.push_back(it);
    }

    return union_array;
} 

// Optimal-Approach

vector<int> OptimalUnion(vector<int> &arr1, vector<int> &arr2) {
    vector<int> Optimal_Union_Array;
    int i = 0;
    int j = 0;

    int n1 = arr1.size();
    int n2 = arr2.size();

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            if (Optimal_Union_Array.size() == 0 || Optimal_Union_Array.back() != arr1[i]) {
                Optimal_Union_Array.push_back(arr1[i]);
            }
            i++;
        } else {
            if (Optimal_Union_Array.size() == 0 || Optimal_Union_Array.back() != arr2[j]) {
                Optimal_Union_Array.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(j < n2) {
        if (Optimal_Union_Array.size() == 0 || Optimal_Union_Array.back() != arr2[j]) {
                Optimal_Union_Array.push_back(arr2[j]);
            }
            j++;
    }
    while (i < n1) {
        if (Optimal_Union_Array.size() == 0 || Optimal_Union_Array.back() != arr1[i]) {
                Optimal_Union_Array.push_back(arr1[i]);
            }
            i++;
    }

    return Optimal_Union_Array;
    
    
}

int main() {
    int n1;
    cout << "Enter the number of elements you want the first array to have: ";
    cin >> n1;

    vector<int> arr1(n1);
    cout << "Enter the elements for the first array: ";
    for(int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    int n2;
    cout << "Enter the number of elements you want the second array to have: ";
    cin >> n2;

    vector<int> arr2(n2);
    cout << "Enter the elements for the second array: ";
    for(int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }
    
    char choice;
    cout << "Please choose between 'b' or 'o' for brute or optimal approach: ";
    cin >> choice;


    vector<int> union_array;

    if (choice == 'b') {
        union_array = Union(arr1,arr2);
    } else if (choice == 'o') {
        union_array = OptimalUnion(arr1,arr2);
    } else {
        cout << "Invalid choice! Please choose between 'o' and 'b' only.";
        return 1;
    }

    cout << "The final array after performing union on the two input arrays is as follows: ";
    for(int i = 0; i < union_array.size(); i++) {
        cout << union_array[i] << " ";
    }
    cout << endl;

    return 0;

}


 