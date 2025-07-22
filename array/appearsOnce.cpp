#include<iostream>
#include<vector>
using namespace std;


int AppearOnce(vector<int> &arr, int n) {
    for (int i = 0; i < n; i++) {
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

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int answer = AppearOnce(arr,n);

    cout << "The element that appears only once in the array is: " << answer << endl;



}