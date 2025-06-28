#include <iostream>
using namespace std;

// paramaterised sumation solution
int param(int n, int sum){
    if (n < 1) return sum;
    sum = sum + n;
    return param(n - 1, sum);
}

int main() {
    int n;
    cout << "Enter the number till where you want the sumation: ";
    cin >> n;
    int result = param(n , 0);
    cout << "Sum is: " << result << endl;
    return 0;
}

