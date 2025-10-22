#include<iostream>
using namespace std;

class DListNode {
    public:
    int data;
    DListNode *next;
    DListNode *prev;

    public:
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

DListNode *DelDuplicates(DListNode *head) {
    DListNode *temp = head;

    while (temp != nullptr && temp->next != nullptr) {
        DListNode *NextNode = temp->next;

        while (NextNode != nullptr && NextNode->data == temp->data) {
            DListNode *duplicate = NextNode;
            NextNode = NextNode->next;
            delete duplicate;
        }
        temp->next = NextNode;

        if (NextNode) NextNode->prev = temp;

        temp = temp->next;
    }

    return head;
}

DListNode *Arr2DLL(vector<int> &arr) {
    DListNode *head = new DListNode(arr[0]);
    DListNode *prev = head;

    for (int i = 1; i < arr.size(); i++) {
        DListNode *temp = new DListNode(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(DListNode *head) {
    DListNode *temp = head;

    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "END" << endl;
}


int main() {
    vector<int> arr = {1,1,1,2,3,3,4};

    DListNode *head = Arr2DLL(arr);

    head = DelDuplicates(head);

    print(head);

    return 0;

}