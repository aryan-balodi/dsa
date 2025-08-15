#include<iostream>
using namespace std;


int fn(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int Nthroot (int n, int m) {
    int l = 1; int h = m;
    while (l <= h) {
        int mid = (l + h) / 2;
        int midN = fn(mid,n,m);
        if (midN == 1) return mid;
        else if (midN == 0) {
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }
    return -1;
}


int main() {
    int m;
    cout << "Enter the number who's nth root you wish to find: ";
    cin >> m;

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "The number that is the nth root of the input number is -> " << Nthroot(n,m) << endl;

    return 0;
}