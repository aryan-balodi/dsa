#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// you need to allocate books to student such that the amximum number of pages per student is minimum.
// input array has the number of pages per book.

// low for binary search will be -> maximum element of the input array: as will require number of students equal to the number of books in the array {as i + (i + 1) > max_element of the array.}

int countStudents(vector<int> &arr, int n, int pages) {
    int students = 1;
    int pages_per_student = 0;
    for (int i = 0; i < n; i++) {
        if (pages_per_student + arr[i] <= pages) {
            pages_per_student += arr[i];
        }
        else {
            students++;
            pages_per_student = arr[i];
        }
    }
    return students;
}

int findPages (vector<int> &arr, int n, int m) {
    if (m > n) return -1;
    int low = *max_element(arr.begin(), arr.end()); 
    int high = accumulate(arr.begin(), arr.end(),0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int noOfStudents = countStudents(arr,n,mid);
        if (noOfStudents > m) low = mid + 1;
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main () {
    int n;
    cout << "Enter the number of books in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the number of pages present in each book: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m;
    cout << "Enter the number of students among whom the number of pages are to be divided: ";
    cin >> m;

    cout << "The number of pages each student will have to carry after minimizing the maximum number of pages to be carried by each student is : " << findPages(arr,n,m) << endl;

    return 0;
}