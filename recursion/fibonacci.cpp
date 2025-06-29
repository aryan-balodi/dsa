#include<iostream>
using namespace std;

int fibonacci(int n){
    if (n <= 1) return n;
    int first = fibonacci(n - 1);
    int second = fibonacci(n - 2);
    return first + second;
}

int main(){
    int n;
    int result;
    cout << "Enter the index number of the fibonacci number you wish to calculate: ";
    cin >> n;
    result = fibonacci(n);
    cout << result << endl;
    return 0;
}