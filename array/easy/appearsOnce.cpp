#include<iostream>
#include<vector>
using namespace std;

// Brute approach.

int AppearOnce(vector<int> &arr, int n) {
    for(int i = 0; i < n; i++) {
        int num = arr[i];
        int counter = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == num) {
                counter++;
            }
        }
        if (counter == 1) return num;
    }
    return -1;

}

/*Better approach:
  a) using hashing via array.
  b) using hashing via map.
*/

int AppearOnceBetter(vector<int> &arr, int n) {
    int maxi = arr[0];
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }

    vector<int> hash(maxi + 1, 0);
    for(int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    for(int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1) return arr[i];
    }

    return -1;
}

// optimal approach -> using XOR.

int AppearOnceOptimal(vector<int> &arr, int n) {
    int result = 0;
    for(int i = 0; i < n; i++) {
        result = result ^ arr[i];
    }
    return result;
}



int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string choice;
    cout << "Please choose between 'br', 'bt' or 'o' for brute, better, optimal approach: ";
    cin >> choice;

    int answer;

    if (choice == "br") {
        answer = AppearOnce(arr,n);
    } else if (choice == "bt") {
        answer = AppearOnceBetter(arr,n);
    } else if (choice == "o") {
        answer = AppearOnceOptimal(arr,n);
    }else {
        cout << "Invalid choice! Please choose between 'br', 'bt' and 'o' only.";
        return 1;
    }

    cout << "The element that appears only once in the array is: " << answer << endl;

    return 0;

}