#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Brute-approach

int Brute_MN(vector<int> &arr, int N) {
    for (int i = 1; i <= N; i++) {
        int flag = 0;
        for (int j = 0; j < N - 1; j++) {
            if (arr[j] == i) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) return i;
    }
    return -1;
}

// Better-approach {using hash array}

int Better_MN(vector<int> &arr, int N) {
    vector<int> hash(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        hash[arr[i]] = 1;
    }
    for (int i = 1; i <= N; i++) {
        if(hash[i] == 0) return i;
    }
    return -1;
}

// Optimal-approach {using n(n+1)/2 formula}

int Optimal_a_MN(vector<int> &arr, int N) {
    int ans = (N * (N + 1)) / 2;
    int sum = 0;

    for (int i = 0; i < N - 1; i++) {
        sum = sum + arr[i];
    }

    return ans - sum;

}

// Using XOR operator

int Optimal_b_NM(vector<int> &arr, int N) {
    int xor1 = 0;
    int xor2 = 0;

    for (int i = 0; i < N - 1; i++) {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
}



int main() {
    int N;
    cout << "Enter the number in which range you wish find the missing number: ";
    cin >> N;

    vector<int> arr(N-1);
    cout << "Enter the numbers for the array in which we will find the missing number: ";
    for (int i = 0; i < N - 1; i++) {
        cin >> arr[i];
    }

    string choice;
    cout << "Please choose between 'br', 'bt', 'oA' or 'oB' for brute, better, optimal summation or optimal XOR approach: ";
    cin >> choice;

    int answer;

    if (choice == "br") {
        answer = Brute_MN(arr,N);
    } else if (choice == "bt") {
        answer = Better_MN(arr,N);
    } else if (choice == "oA") {
        answer = Optimal_a_MN(arr,N);
    } else if (choice == "oB") {
        answer = Optimal_b_NM(arr,N);
    }else {
        cout << "Invalid choice! Please choose between 'oA', 'oB', 'br' and 'bt' only.";
        return 1;
    }

    cout << "The missing number in the array is: " << answer << endl;

    return 0;
}