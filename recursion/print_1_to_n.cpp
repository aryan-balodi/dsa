#include<iostream>
using namespace std;

void print_numbers(int i,int n){
    if(i > n) return;
    cout << i << endl;
    print_numbers(i + 1, n);
}

int main() {
int n;
cout << "Enter till the number you want to print: ";
cin >> n;
print_numbers(1, n);
return 0;

}
