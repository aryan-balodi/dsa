#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    public:
    Node(int data1, Node *next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node *Array2LL(vector<int> &arr) {
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL(Node *head) {
    int count = 0;
    Node *temp = head;

    while (temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

bool checkIfPresent(Node *head, int val) {
    Node *temp = head;
    while (temp) {
        if (temp->data ==val) return true;
        temp = temp->next;
    }
    return false;
}

int main() {
    vector<int> arr = {5, 6, 7, 8, 9};
    Node *head = Array2LL(arr);
    
    int val; 
    
    cout << "Enter the value u wish to check in the LL: ";
    cin >> val;

    cout << checkIfPresent(head,val) << endl;

    return 0;
}