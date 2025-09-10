#include<iostream>
#include<string>
using namespace std;

int NoOfSubstr (string &s) {
    int n = s.length();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the length of the input string: ";
    cin >> n;

    string s(n, ' ');
    cout << "Enter the input string: ";
    cin >> s;

    cout << "The number of substrings in the input string are: " << NoOfSubstr(s) << endl;

    return 0;
}