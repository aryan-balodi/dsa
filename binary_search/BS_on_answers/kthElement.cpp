#include<iostream>
#include<vector>
using namespace std;

int kthElement(vector<int> &arr_1, vector<int> &arr_2, int n,  int m, int k) {
    if (n > m) return kthElement(arr_2,arr_1,m,n,k);
    int low = max(0,k-m); int high = min(k,n);
    int left = k;
    int len = n + m;
    while (low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN; int l2 = INT_MIN;
        int r1 = INT_MAX; int r2 = INT_MAX;
        if (mid1 < n) r1 = arr_1[mid1];
        if (mid2 < m) r2 = arr_2[mid2];
        if (mid1 - 1 >= 0) l1 = arr_1[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = arr_2[mid2 - 1];
        if (l1 <= r2 && l2 <= r1) {
            return max(l1,l2);
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

int main() {
    int n;
    cout << "Enter the number of elements in the first array: ";
    cin >> n;

    vector<int> arr_1(n);
    cout << "Enter the elements of the first array (note: they need to be in sorted fashion): ";
    for(int i = 0; i < n; i++) {
        cin >> arr_1[i];
    }

    int m;
    cout << "Enter the number of elements in the second array: ";
    cin >> m;

    vector<int> arr_2(m);
    cout << "Enter the elements of the first array (note: they need to be in sorted fashion): ";
    for(int i = 0; i < m; i++) {
        cin >> arr_2[i];
    }

    int k;
    cout << "Enter the index position at which you wish to find out the element: ";
    cin >> k;

    cout << "The element at the " << k << "th index position is -> " << kthElement(arr_1,arr_2,n,m,k) << endl; 

    return 0;
}