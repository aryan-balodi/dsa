#include<iostream>
using namespace std;

class DListNode {
    public:
    int data;
    DListNode *next;
    DListNode *prev;

    DListNode(int data1, DListNode *next1, DListNode *prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    DListNode(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

DListNode *Arr2DLL(vector<int> &arr) {
    DListNode *head = new DListNode(arr[0]);
    DListNode *prev = head;

    for (int i = 1; i < arr.size(); i++) {
        DListNode *temp = new DListNode(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

DListNode *DelTail(DListNode *head) {
    if (head == nullptr || head->next == nullptr) return NULL;
    
    DListNode *tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
    }
    DListNode *prev = tail->prev;
    prev->next = nullptr;
    tail->prev = nullptr;

    return head;
}

void print(DListNode *head) {
    while (head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "END" << endl;
}



int main() {
    vector<int> arr = {2,4,6,8,10};

    DListNode *head = Arr2DLL(arr);

    head = DelTail(head);

    print(head);

    return 0;
}