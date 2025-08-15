#include<iostream>
using namespace std;


int BS(int n) {
    int low = 1; int high = n;
    int ans = 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if ((mid * mid) <= n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}


int main() {
    int n;
    cout << "Enter the number who's square root you wish to find: ";
    cin >> n;

    cout << "The square root of the input is -> " << BS(n) << endl;

    return 0;
}

