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

int main() {
    vector<int> arr = {5, 6, 7, 8, 9};
    Node *head = Array2LL(arr);

    cout << "The length of the Linked List is: " << lengthOfLL(head) << endl;

    return 0;
}