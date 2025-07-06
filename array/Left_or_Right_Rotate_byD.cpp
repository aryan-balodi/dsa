#include <iostream>
#include <vector>
using namespace std;

void LeftShift_D(vector<int> &arr, int n, int d) {
    d = d % n;

    // creating the temp array & storing the first d elements in it.
    vector<int> temp(d);
    for(int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // now we will perform the left shift of the elements; starting from index position d.
    for(int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    // now putting the elements from the temp array in place in the main arr.
    for (int i = n - d; i < n; i++) {
        arr[i] = temp[i - (n - d)];
    }
}

// from leetcode it is nums and k
void RightShift_D(vector<int> &arr, int n, int d) {
    d = d % n;
    vector<int> temp(d);

    // saving the right-most elements from arr to temp
    for(int i = n - d; i < n; i++) {
        temp[i - (n - d)] = arr[i];
    }

    // shifting first (n - d) elements to the right
    for (int i = n - d - 1; i >= 0; i--) {
        arr[i + d] = arr[i];
    }

    for (int i = 0; i < d; i++) {
        arr[i] = temp[i];
    }

}

int main() {
    int n;
    cout << "Enter the number of elements that you want the array to be: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int d;
    cout << "Enter the number of digits after which you wish to perform left shift: ";
    cin >> d;

    char choice;
    cout << "Choose if you want left shift or right shift; enter l for left and r for right: ";
    cin >> choice;

    if (choice == 'l'){
        LeftShift_D(arr,n,d);
    }else if(choice == 'r'){
        RightShift_D(arr,n,d);
    }else {
        cout << "Invalid choice! Please choose between 'l' and 'r' only.";
    }
    
    cout << "The array after performing the " << (choice == 'l' ? "left" : "right") << " shift is as follows: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
