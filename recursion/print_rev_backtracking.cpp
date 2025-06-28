#include<iostream>
using namespace std;

void print_numbers(int i, int n){
    if(i > n) return;
    print_numbers(i + 1, n);
    cout << i << endl;
}

int main() {
int n;
cout << "Enter the number from where you want to print: ";
cin >> n;
print_numbers(1 , n);
return 0;
}

