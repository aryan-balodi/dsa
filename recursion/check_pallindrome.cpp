#include<iostream>
using namespace std;

bool check_pallindrome(int i, const string &s) {
    if (i >= s.size() / 2) return true;
    if (s[i] != s[s.size() - i - 1]) return false;
    return check_pallindrome(i + 1, s);
}

int main() {
    string s;
    cout << "Enter the word you wish to chck for palindrome: ";
    cin >> s;

    if (check_pallindrome(0, s)){
        cout << "Yes, the word is a palindrome!" << endl;
    }else{
        cout << "No, the word is not a palindrome." << endl;
    }
    
    return 0;
}