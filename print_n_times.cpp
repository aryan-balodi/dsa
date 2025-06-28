#include<iostream>
using namespace std;

void print_name(int i,int n){
    if(i > n) return;
    cout << "Aryan" << endl;
    print_name(i + 1, n);
}

int main() {
int n;
cout << "Enter the number of times you want the name to be printed: ";
cin >> n;
print_name(1, n);
return 0;

}
