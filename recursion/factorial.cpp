#include <iostream>
using namespace std;

int factorial(int n){
    if (n <= 1) return 1;
    int result = n * factorial(n - 1);
    return result;
}

int main(){
    int n;
    cout << "Enter the number who's factorial you wish to calculate: ";
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}