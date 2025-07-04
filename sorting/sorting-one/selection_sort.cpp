#include <iostream>
using namespace std;

void selection_sort(int arr[], int n) {
    for (int i = 0; i <= n - 2; i++){
        int min = i;
        for (int j = i; j <= n - 1; j++){
            if (arr[j] < arr[min]) {
                min = j;
            }
            swap(arr[i], arr[min]);
        }
    }
}

int main(){
    int n;
    cout << "Enter the length you want the array to be of: ";
    cin >> n;

    int arr[n];
    cout << "Enter the numbers for the array: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    selection_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;


}