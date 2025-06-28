#include <iostream>
using namespace std;

// function soluiton

int sumation(int n) {
    if (n == 0) return 0;
    int sum = n + sumation(n-1);
    return sum;
}

int main() {
    int n;
    cout << "Provide the number till where you need sumation: ";
    cin >> n;
    int result = sumation(n);
    cout << "Sum is: " << result << endl;
    return 0;
}