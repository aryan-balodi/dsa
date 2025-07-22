#include <iostream>
#include <vector>
using namespace std;

vector<int> brute_method(vector<int> &arr, int n) {

    // declaring a temporary array that will store all the non-zero elements.
    vector<int> temp;
    for(int i = 0; i < n; i++) {
        if (arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }

    // writing the non-zero elements from the temp array onto the main array in the order they had appeared.
    for(int i = 0; i < temp.size(); i++) {
        arr[i] = temp[i];
    }

    /*  after the main array has all the non-zero elements, start placing 0's starting from 
        index position temp.size() as if there are 5 non-zero elements then starting from index 
        position 5 will mean one index position ahead after the last non-zero element
        which is what we want
    */
    for(int i = temp.size(); i < n; i++) {
        arr[i] = 0;
    }

    return arr;
}

/* optimal method is a 2-pointer approach where the first pointer points to the first 0
   and the second one points to index position one ahead to the first pointer position
   we then iterate through the array swapping non-zero elements with (2nd pointer) with 
   zeros (1st pointer)
*/

vector<int> optimal_method(vector<int> &arr, int n) {
    // finding the first '0' in the array.
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            j = i;
            break;
        }
    }
    if (j == -1) return arr; // if no zeros; return the array as it is.

    // swapping the 0's with the non zero elements till the 0's get pushed to the end.
    for (int i = j + 1; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return arr;
}

int main() {
    int n;
    cout << "Enter the number of elements you wish the array to have: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i< n; i++) {
        cin >> arr[i];
    }

    char choice;
    cout << "Enter 'b' for brute method or 'o' for optimal method: ";
    cin >> choice;

    if (choice == 'b'){
        brute_method(arr,n);
    }else if(choice == 'o'){
        optimal_method(arr,n);
    }else {
        cout << "Invalid choice! Please choose between 'b' and 'o' only.";
    }

    cout << "The array after moving the zeros to the end is as follows: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}