#include<iostream>
using namespace std;

int main(){
    string s;
    cout << "Enter the input string: ";
    cin >> s;

    //pre-compute

    int hash[256] = {0};
    for (int i = 0; i<s.size(); i++){
        hash[s[i]]++;
    }

    int q;
    cout << "Enter the number of characters who's frequency you would like to know: ";
    cin >> q;
    while(q--){
        char c;
        cout << "Enter the character who's frequency you would like to know: ";
        cin >> c;

        // fetch 
        cout << hash[c] << endl;
    }
    return 0;
}