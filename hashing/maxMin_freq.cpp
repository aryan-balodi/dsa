#include <iostream>
#include <map>
#include <climits>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements that you wish the array to have: ";
    cin >> n;

    int arr[n];
    cout << "Enter the numbers you wish the array to have: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //pre-compute
    map<int, int>freq_table;
    for(int i = 0; i < n; i++){
        freq_table[arr[i]]++;
    }

    int max_freq = INT_MIN;
    int max_element = -1;

    for (auto it : freq_table) {
        if (it.second > max_freq) {
            max_freq = it.second;
            max_element = it.first;
        }
    }

    cout << "The element with the maximum frequency is -> " << max_element << ", and it's corresponding frequency is -> " << max_freq << "." << endl;



}