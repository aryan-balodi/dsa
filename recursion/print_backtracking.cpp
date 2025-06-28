#include<iostream>
using namespace std;

void print_numbers(int i, int n){
    if(i < n) return;
    print_numbers(i - 1, n);
    cout << i << endl;
    
}

int main() {
int n;
cout << "Enter the number till where you want to print: ";
cin >> n;
print_numbers(n , 1);
return 0;

}

